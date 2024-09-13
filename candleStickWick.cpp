#include "candleStickWick.h"

candleStickWick::candleStickWick(QGraphicsItem *parent,
    QVector<double> ohlcData, QColor wickColor = nullptr) : lowValue(ohlcData[2]),
    highValue(ohlcData[1]), openValue(ohlcData[0]), closeValue(ohlcData[3]){
    setDirectionColor();
}

void candleStickWick::setDirectionColor(){
    if(closeValue > openValue){
        m_color = Qt::green;
    }else{
        m_color = Qt::red;
    }
    setColor(Qt::red);
    setOpacity(1.0);
}

void candleStickWick::setUpSlots(){

}

candleStickWick::~candleStickWick()
{

}

qreal candleStickWick::getLength() const {
    return m_length;
}

QPointF candleStickWick::getPreviousLocation() const {
    return m_previousLocation;
}

void candleStickWick::setColor(const QColor &color) {
    if (m_color != color) {
        m_color = color;
        emit colorChanged(m_color);
    }
}

void candleStickWick::setLength(qreal length) {
    if (!qFuzzyCompare(m_length, length)) {
        m_length = length;
        emit lengthChanged(m_length);
    }
}

void candleStickWick::setPreviousLocation(const QPointF &location) {
    if (m_previousLocation != location) {
        m_previousLocation = location;
        emit previousLocationChanged(m_previousLocation);
    }
}

void candleStickWick::lengthChanged(qreal length)
{
}

void candleStickWick::previousLocationChanged(const QPointF &location)
{
}
