#include "candleBody.h"
#include <QGraphicsRectItem>
#include <QPen>

candleBody::candleBody(QGraphicsItem *parent, double open,
    double close) : m_isHighlighted(false), openValue(open),
    closeValue(close) {
}

candleBody::~candleBody() {
}

void candleBody::onMouseEnter() {
    // enter
    setHighlighted(true);
}

void candleBody::onMouseClick() {

}

void candleBody::setDirectionColor(){
    if(closeValue > openValue){
        m_color = Qt::green;
    }
    else{
        m_color = Qt::red;
    }
    setColor(m_color);
    setBrush(QBrush(m_color));
}

QRectF candleBody::getCandleBodyPosition() const
{
    return m_candleBodyPosition;
}

QColor candleBody::getColor() const {
    return m_color;
}

bool candleBody::isHighlighted() const {
    return m_isHighlighted;
}

void candleBody::setCandleBodyPosition(const QRectF &position) {
    if (m_candleBodyPosition != position) {
        m_candleBodyPosition = position;
        setRect(position);
    }
}

void candleBody::setColor(const QColor &color) {
    if (m_color != color) {
        m_color = color;
        setBrush(QBrush(m_color));
    }
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
