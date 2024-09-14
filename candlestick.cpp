#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QGraphicsItemGroup>
#include <QFont>
#include <iostream>
#include "candlestick.h"
#include "candleBody.h"
#include "candleStickWick.h"

#include <QPainter>

candle::~candle(){

}

candle::candle(QGraphicsItem *parent, graphTimeFrameNodeState *nodestate)
    : QGraphicsItemGroup(parent), m_isHighlighted(false), node_state(nodestate)
{
    if (node_state) {
        open = node_state->getOpen(); 
        high = node_state->getHigh();
        low = node_state->getLow();
        close = node_state->getClose();
        ohlcData = node_state->getOHLCdata();
        
        candle_stick_body = new candleBody(this, node_state);
        candle_stick_wick = new candleStickWick(this, node_state);

        addToGroup(candle_stick_body);
        addToGroup(candle_stick_wick);

        setAcceptHoverEvents(true);
    }
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
