#include "graphTimeFrameNode.h"
#include "candleStickState.h"
#include "candlestick.h"
#include <QDateTime>
#include <QVector>
#include <QPainter>
#include "pathGraphPoint.h"
#include "candleStickWick.h"
#include <QPoint>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsScene>
#include <iostream>
#include <QTextBrowser>
#include <QFrame>
#include <QGraphicsProxyWidget>

graphTimeFrameNode::graphTimeFrameNode(QVector<double> &ohlcData, QDateTime &time_state, int id, bool isDynamic, int nodewidth)
    : ohlcData(ohlcData), node_time_state(time_state), isNodeDynamic(isDynamic), node_id(id), node_width(nodewidth)
{
    // create the internal state of the node
    pixelsPerPip = 4;
    setScale();
    setRange();
    setNodeHeight();
    node_state = new graphTimeFrameNodeState();
    initializeState(); // initialize default values
    populateInternalState();

    setAcceptHoverEvents(true);
}

graphTimeFrameNode::~graphTimeFrameNode()
{
}

graphTimeFrameNodeState *graphTimeFrameNode::getgraphTimeFrameNodeState()
{
    return node_state;
}

pathGraphPoint *graphTimeFrameNode::getPathGraphPoint() const {
    return path_graph_point;
}

QRectF graphTimeFrameNode::boundingRect() const
{
    return QRectF(0, 0, node_width, node_height);
}

void graphTimeFrameNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // The candlestick is a child item, so it will be drawn automatically
    // Draw the path_graph_point if needed
    painter->drawPoint(path_graph_point->toPoint());
}

void graphTimeFrameNode::setgraphTimeFrameNodeState(graphTimeFrameNodeState *state) {
    node_state = state;
}

void graphTimeFrameNode::setIsStateInitialized(bool state)
{
    isStateInitialized = state;
}

void graphTimeFrameNode::updateNodeGeometry(double current_price)
{
    // change the candlestickState/ graphtimeframeNode state and
    // emit signals which are received by the wick and candle body
    // causing them to update their geometry
    if (isNodeDynamic == true){

    }
}

QPointF graphTimeFrameNode::valueToPosition(double value) {
    // Assuming prices are quoted to four decimal places (e.g., Forex)
    const int PIPS_MULTIPLIER = 10000;

    // Calculate the difference in pips from the high value
    int pipsDifference = static_cast<int>((ohlcData[1] - value) * PIPS_MULTIPLIER + 0.5);
    
    // Convert pips to pixels
    double pixelDifference = pipsDifference * getPixelsPerPip();
    
    // Calculate the Y position (remember that screen coordinates increase downwards)
    double y = pixelDifference; // Assuming top of the bounding rect is 0
    
    // X position remains at the center of the bounding rect
    double x = node_width / 2; // Center of the node width
    
    return QPointF(x, y);
}

// this is the the scale of the width:height(length) eg w = 2h, this is to be set in the settings
void graphTimeFrameNode::setScale(){
    node_scale = 2;
}

void graphTimeFrameNode::setRange(){
    range = std::abs(ohlcData[1] - ohlcData[2]);
}

double graphTimeFrameNode::getPixelsPerPip(){
    return pixelsPerPip;
}

void graphTimeFrameNode::setNodeHeight() {
    // Define a maximum height for the node (in pixels)
    const int MAX_HEIGHT = 600;  // Adjust this value as needed

    // Convert range to pips (assuming 4 decimal places for forex)
    int rangePips = static_cast<int>((range * 10000) + 0.5);

    // Ensure a minimum size for very small ranges
    const double MIN_PIXELS_PER_PIP = 0.5;
    double pixelsPerPip_ = std::max(pixelsPerPip, MIN_PIXELS_PER_PIP);

    // Calculate the node height
    double height = rangePips * pixelsPerPip_;

    // Ensure the height doesn't exceed the maximum
    height = std::min(height, static_cast<double>(MAX_HEIGHT));

    node_height = height;
}

void graphTimeFrameNode::initializeState(){
    // these settings will in the future depend on the settings of the app
    node_state->setIsDynamic(isNodeDynamic);
    node_state->setTimeState(node_time_state);
    node_state->setId(node_id);
    if(isNodeDynamic == false){
        node_state->setLow(ohlcData[2]);
        node_state->setHigh(ohlcData[1]);
        node_state->setClose(ohlcData[3]);
        node_state->setOpen(ohlcData[0]);
        setRange();
        if(ohlcData[3] > ohlcData[0]){
            //bullish candle
            node_state->setCandleStickBodyPen(QPen(Qt::green));
            node_state->setCandleStickBodyColor(Qt::green);
            node_state->setCandleStickWickColor(Qt::green);
        }else{
            // bearish candle
            node_state->setCandleStickBodyPen(QPen(Qt::red));
            node_state->setCandleStickBodyColor(Qt::red);
            node_state->setCandleStickWickColor(Qt::green);
        }
        // depending on the range of the prices, the geometry relative to the group item is to be changed.
        // set the dimensions of the graphTimeFrameNode boundingRect
        // boundingRect().setWidth(node_width); // same as the candle body width
        // boundingRect().setHeight(node_height);
        // set positions relative to the boundingRect
        // the minus is to make sure the candles are not on one another
        node_state->setCurCandleStickBodyWidth(node_width-2); // this is the same size as the boundingRect of both the candleStick item group and the graphTimeFrameNode group due to autoAdjustmet done by qt

        // Calculate positions for the wicks and body
        double highPosition = valueToPosition(ohlcData[1]).y();
        double lowPosition = valueToPosition(ohlcData[2]).y();
        double openPosition = valueToPosition(ohlcData[0]).y();
        double closePosition = valueToPosition(ohlcData[3]).y();

        // set the wick positions and in so doing setting the two bounding rectangles
        node_state->setCurCandleStickWickStartPosition(QPointF(node_width/2, highPosition));
        node_state->setPrevCandleStickWickStartPosition(QPointF(node_width/2, highPosition));
        node_state->setCurCandleStickWickEndPosition(QPointF(node_width/2, lowPosition));
        node_state->setPrevCandleStickWickEndPositon(QPointF(node_width/2, lowPosition));

        // set the body top and bottom positions based on whether the candle is bullish or bearish
        double bodyTop = std::min(openPosition, closePosition);
        double bodyBottom = std::max(openPosition, closePosition);
        node_state->setCurCandleStickBodyTopPosition(QPointF(0, bodyTop));
        node_state->setCurCandleStickBodyBottomPosition(QPointF(0, bodyBottom));
        // set lengths
        double bodyLength = std::abs(bodyTop - bodyBottom);
        node_state->setCurCandleSickBodyLength(bodyLength);
        node_state->setPrevCandleStickBodyLength(bodyLength);
        node_state->setCurCandleStickWickLength(std::abs(highPosition - lowPosition));
        node_state->setPrevCandleStickWickLength(std::abs(highPosition - lowPosition));

        // set the current candlestick body location
        node_state->setCurCandleStickBodyLocation(QPoint(node_width / 2, bodyLength / 2));
    }else {
        // Dynamic case: set all OHLC values to the open value
        double openValue = ohlcData[0];
        node_state->setLow(openValue);
        node_state->setHigh(openValue);
        node_state->setClose(openValue);
        node_state->setOpen(openValue);
        node_state->setCandleStickBodyPen(QPen(Qt::transparent));
        node_state->setCandleStickBodyColor(Qt::transparent);
        node_state->setCandleStickWickColor(Qt::transparent);
        node_state->setCurCandleStickBodyWidth(node_width);
        
        // Set positions with x = node_width / 2
        QPointF centerX(node_width / 2, 0);
        node_state->setCurCandleStickWickStartPosition(centerX);
        node_state->setPrevCandleStickWickStartPosition(centerX);
        node_state->setCurCandleStickWickEndPosition(centerX);
        node_state->setPrevCandleStickWickEndPositon(centerX);
        node_state->setCurCandleStickBodyTopPosition(centerX);
        node_state->setCurCandleStickBodyBottomPosition(centerX);
        node_state->setPrevCandleStickBodyTopPosition(centerX);
        node_state->setPrevCandleStickBodyBottomPosition(centerX);
        
        node_state->setCurCandleSickBodyLength(0);
        node_state->setPrevCandleStickBodyLength(0);
        node_state->setCurCandleStickWickLength(0);
        node_state->setPrevCandleStickWickLength(0);
    }
    setIsStateInitialized(true); // Moved outside the if-else block
}

// this populates the internal components with all the data given to it by state parameter.
void graphTimeFrameNode::populateInternalState()
{
    // Create the candlestick and add it to this node
    candle_stick = new candle(this, node_state);
    path_graph_point = new pathGraphPoint();
    addToGroup(candle_stick);
}

void graphTimeFrameNode::setPosition(qreal x, qreal y){
    // the position of the body and wick has to be set relative to the axes and so is the body
    // the position of the group should be the same as the position of the path_graph_point
    
}

void graphTimeFrameNode::mergeNode() {
    // Get the position of the candlestick
    QPointF candlePos = candle_stick->pos();
    
    // Set the x and y positions for the path_graph_point
    path_graph_point->setX(candlePos.x());
    path_graph_point->setY(candlePos.y());
}

void graphTimeFrameNode::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    std::cout << "hover event captured" << std::endl;
    QGraphicsScene *scene = this->scene();
    if (scene) {
        QPointF scenePos = mapToScene(event->pos());
        
        // Create a QTextBrowser to display the information
        QTextBrowser *infoBrowser = new QTextBrowser();
        infoBrowser->setReadOnly(true);
        infoBrowser->setText(QString("Open: %1<br>High: %2<br>Low: %3<br>Close: %4")
                             .arg(node_state->getOpen())
                             .arg(node_state->getHigh())
                             .arg(node_state->getLow())
                             .arg(node_state->getClose()));
        
        // Set up the appearance of the info window
        infoBrowser->setStyleSheet("background-color: white; color: black; font-size: 10pt;");
        infoBrowser->setFrameStyle(QFrame::Box | QFrame::Plain);
        infoBrowser->setLineWidth(1);
        
        // Create a proxy widget to embed the QTextBrowser in the scene
        QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget();
        proxy->setWidget(infoBrowser);
        proxy->setZValue(1);  // Ensure it's drawn on top
        
        // Position the info window near the candle body
        proxy->setPos(scenePos + QPointF(10, 10));
        
        // Add the info window to the scene
        scene->addItem(proxy);
        
        // Store the info window for later removal
        setData(0, QVariant::fromValue<QGraphicsItem*>(proxy));
    }
}

void graphTimeFrameNode::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    std::cout << "hover leave event captured" << std::endl;
    QGraphicsScene *scene = this->scene();
    if (scene) {
        // Retrieve the stored info window
        QGraphicsItem *infoGroup = data(0).value<QGraphicsItem*>();
        if (infoGroup) {
            // Remove the info window from the scene
            scene->removeItem(infoGroup);
            delete infoGroup;
            setData(0, QVariant());  // Clear the stored data to avoid dangling pointers
        }
    }
}
