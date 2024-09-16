#include "candleBody.h"
#include "candleStickState.h"
#include <QPainter>
#include <QPen>

candleBody::candleBody(QGraphicsItem *parent, graphTimeFrameNodeState *nodeState)
    : QGraphicsRectItem(parent), node_state(nodeState), m_isHighlighted(false)
{
    // Initialize the rectangle based on the node state
    setRect(0, node_state->getCurCandleStickBodyTopPosition().y(), node_state->getCurCandleStickBodyWidth(), node_state->getCurCandleStickBodyLength());
}

candleBody::~candleBody() {
}

void candleBody::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // Set the pen and brush for the candlestick body
    painter->setPen(QPen(node_state->getCandleStickBodyColor()));
    painter->setBrush(QBrush(node_state->getCandleStickBodyColor()));

    // Draw the candlestick body
    painter->drawRect(rect());
}

bool candleBody::isHighlighted() const {
    return m_isHighlighted;
}

void candleBody::setHighlighted(bool highlighted) {
    if (m_isHighlighted != highlighted) {
        m_isHighlighted = highlighted;
        if (m_isHighlighted) {
            setPen(QPen(Qt::yellow, 2));
        } else {
            setPen(QPen(Qt::black, 1));
        }
    }
}
