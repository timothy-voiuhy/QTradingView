#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QGraphicsItemGroup>
#include <QFont>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsScene>

#include "candlestick.h"
#include "candleBody.h"
#include "candleStickWick.h"

#include <QPainter>

candle::~candle(){

}

candle::candle(QGraphicsItem *parent, graphTimeFrameNodeState *nodestate): m_isHighlighted(false){
    node_state = nodestate;
    open = node_state->getOpen(); 
    high = node_state->getHigh();
    low = node_state->getLow();
    close = node_state->getClose();
    ohlcData = node_state->getOHLCdata();
    candle_stick_body = new candleBody(this, open, close);
    candle_stick_wick = new candleStickWick(this, node_state);

    addToGroup(candle_stick_body);
    addToGroup(candle_stick_wick);
}


QRectF candle::boundingRect() const
{
    return QRectF();
}

void candle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // Delegate drawing to the body and wick items
    candle_stick_body->paint(painter, option, widget);
    candle_stick_wick->paint(painter, option, widget);
}

void candle::setHighlighted(bool highlighted)
{
    candle_stick_body->setHighlighted(highlighted);
}

void candle::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setHighlighted(true);
    QGraphicsScene *scene = this->scene();
    if (scene) {
        QPointF scenePos = mapToScene(event->pos());
        
        // Create a QGraphicsTextItem to display the information
        QString info = QString("Open: %1\nClose: %2").arg(open).arg(close);
        QGraphicsTextItem *infoItem = new QGraphicsTextItem(info);
        
        // Set up the appearance of the info window
        QFont font = infoItem->font();
        font.setPointSize(10);
        infoItem->setFont(font);
        infoItem->setZValue(1);  // Ensure it's drawn on top
        
        // Create a white background rectangle for the text
        QRectF textRect = infoItem->boundingRect();
        QGraphicsRectItem *backgroundRect = new QGraphicsRectItem(textRect);
        backgroundRect->setBrush(Qt::white);
        backgroundRect->setPen(QPen(Qt::black));
        backgroundRect->setZValue(0.9);  // Just below the text
        
        // Group the background and text together
        QGraphicsItemGroup *infoGroup = new QGraphicsItemGroup();
        infoGroup->addToGroup(backgroundRect);
        infoGroup->addToGroup(infoItem);
        
        // Position the info window near the candle body
        infoGroup->setPos(scenePos + QPointF(10, 10));
        
        // Add the info window to the scene
        scene->addItem(infoGroup);
        
        // Store the info window for later removal
        setData(0, QVariant::fromValue<QGraphicsItem*>(infoGroup));
    }
    
    // QGraphicsRectItem::hoverEnterEvent(event);
}

void candle::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    setHighlighted(false);
    QGraphicsScene *scene = this->scene();
    if (scene) {
        // Retrieve the stored info window
        QGraphicsItem *infoGroup = data(0).value<QGraphicsItem*>();
        if (infoGroup) {
            // Remove the info window from the scene
            scene->removeItem(infoGroup);
            delete infoGroup;
        }
    }
    // QGraphicsRectItem::hoverLeaveEvent(event);
}

