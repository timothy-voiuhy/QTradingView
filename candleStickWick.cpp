#include <QPen>
#include <QPainter>
#include "candleStickWick.h"
#include "candleStickState.h"

candleStickWick::candleStickWick(QGraphicsItem *parent, graphTimeFrameNodeState *nodeState)
    : QGraphicsLineItem(parent), node_state(nodeState)
{
    // Initialize the line based on the initial state
    setLength(node_state->getCurCandleStickWickLength());
}

candleStickWick::~candleStickWick(){

}

void candleStickWick::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // Set the pen for the candlestick wick
    // Set the position of the wick line
    QLineF wickLine(node_state->getCurCandleStickWickStartPosition(), node_state->getCurCandleStickWickEndPosition());
    setLine(wickLine);
    painter->setPen(QPen(node_state->getCandleStickWickColor()));

    // Draw the candlestick wick
    painter->drawLine(line());
}

void candleStickWick::setLength(qreal newLength) {
    // Only update if the new length is greater than the current length
    if (newLength > node_state->getCurCandleStickWickLength()) {
        QLineF currentLine = line();
        QPointF bodyCenter = QPointF(currentLine.x1(), node_state->getOpen());
        
        // Determine direction based on whether it's the upper or lower wick
        bool isUpperWick = node_state->getClose() > node_state->getOpen();
        
        // Calculate new start and end points
        QPointF startPoint, endPoint;
        if (isUpperWick) {
            startPoint = bodyCenter;
            endPoint = bodyCenter + QPointF(0, -newLength);
        } else {
            startPoint = bodyCenter;
            endPoint = bodyCenter + QPointF(0, newLength);
        }
        
        // Update the line
        setLine(QLineF(startPoint, endPoint));
        
        // Update the length in the node state
        node_state->setCurCandleStickWickLength(newLength);
        
        update(); // Trigger a redraw of the item
    }
}