#include "graphTimeFrameNode.h"
#include "candleStickState.h"
#include "candlestick.h"
#include <QDateTime>
#include <QVector>
#include <QPainter>
#include "pathGraphPoint.h"
#include "candleStickWick.h"
#include <QPoint>

graphTimeFrameNode::graphTimeFrameNode(QVector<double> &ohlcData, QDateTime &time_state, int id,  bool isDynamic, int nodewidth):
ohlcData(ohlcData), node_time_state(time_state), isNodeDynamic(isDynamic), node_id(id), node_width(nodewidth)
{
    // create the internal state of the node
    node_state = new graphTimeFrameNodeState();
    initializeState(); // initialize default values
    populateInternalState();
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
    // Calculate the difference in pips
    int pipsDifference = static_cast<int>((ohlcData[1] - value) * 10000 + 0.5);
    
    // Convert pips to pixels
    double pixelDifference = pipsDifference * getPixelsPerPip();
    
    // Calculate the Y position (remember that screen coordinates increase downwards)
    double y = boundingRect().top() + pixelDifference;
    
    // X position remains at the center of the bounding rect
    double x = boundingRect().center().x();
    
    return QPointF(x, y);
}

// this is the the scale of the width:height(length) eg w = 2h, this is to be set in the settings
void graphTimeFrameNode::setScale(){
    node_scale = 2;
}

void graphTimeFrameNode::setRange(){
    range = ohlcData[1] - ohlcData[2];
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
    pixelsPerPip = std::max(pixelsPerPip, MIN_PIXELS_PER_PIP);

    // Calculate the node height
    double height = rangePips * pixelsPerPip;

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
        if(isNodeDynamic == false){
            setNodeHeight();
            // set the dimensions of the graphTimeFrameNode boundingRect
            boundingRect().setWidth(node_width); // same as the candle body width
            boundingRect().setHeight(node_height);
            // set positions relative to the boundingRect
            // the minus is to make sure the candles are not on one another
            node_state->setCurCandleStickBodyWidth(node_width-2); // this is the same size as the boundingRect of both the candleStick item group and the graphTimeFrameNode group due to autoAdjustmet done by qt

            // set the wick positions and in so doing setting the two bounding rectangles
            node_state->setCurCandleStickWickStartPosition(QPointF(node_width/2, 0));
            node_state->setPrevCandleStickWickStartPosition(QPointF(node_width/2, 0));
            node_state->setCurCandleStickWickEndPosition(QPointF(node_width/2, node_height));
            node_state->setPrevCandleStickWickEndPositon(QPointF(node_width/2, node_height));

            // set the body top and bottom positions
            double bodyTop = valueToPosition(ohlcData[3]).y();
            double bodyBottom = valueToPosition(ohlcData[0]).y();
            node_state->setCurCandleStickBodyTopPosition(QPointF(node_width/2, bodyTop));
            node_state->setCurCandleStickBodyBottomPosition(QPointF(node_width/2, bodyBottom));

            // set lengths
            double bodyLength = std::abs(bodyTop - bodyBottom);
            node_state->setCurCandleSickBodyLength(bodyLength);
            node_state->setPrevCandleStickBodyLength(bodyLength);
            node_state->setCurCandleStickWickLength(node_state->getCurCandleStickWickStartPosition().y() - node_state->getCurCandleStickWickEndPosition().y());
            node_state->setPrevCandleStickWickLength(node_state->getCurCandleStickWickStartPosition().y() - node_state->getCurCandleStickWickEndPosition().y());
        }else{

        }
    setIsStateInitialized(true);
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
        setIsStateInitialized(true);
    }
}

// this populates the internal components with all the data given to it by state parameter.
void graphTimeFrameNode::populateInternalState()
{
    candle_stick = new candle(this, node_state);
}

void graphTimeFrameNode::setPosition(qreal x, qreal y){
    // the position of the body and wick has to be set relative to the axes and so is the body
    // the position of the group should be the same as the position of the path_graph_point
    
}

void graphTimeFrameNode::mergeNode() {
    // This function should add the path_graph_point to the context of the candleStick
    // The position of the path_graph_point is derived as the average height of the wick of the candleStick
    
    double wickTop = candle_stick->getWickTop();
    double wickBottom = candle_stick->getWickBottom();
    // Calculate the average height of the wick
    double averageWickHeight = (wickTop + wickBottom) / 2.0;
    // the x value is the same as candlestick 
    path_graph_point->setY(averageWickHeight);
    path_graph_point->setX(candle_stick->candle_stick_wick->x());
}
