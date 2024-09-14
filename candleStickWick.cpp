#include <QPen>
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

candleStickWick::~candleStickWick(){

}

qreal candleStickWick::getLength() const {
    return m_length;
}

void candleStickWick::setColor(const QColor &color) {
    if (m_color != color) {
        m_color = color;
    }
    setPen(QPen(m_color));
    update();
}

void candleStickWick::setLength(qreal newLength) {
    // Only update if the new length is greater than the current length
    if (newLength > m_length) {
        QLineF currentLine = line();
        QPointF bodyCenter = QPointF(currentLine.x1(), openValue);
        
        // Determine direction based on whether it's the upper or lower wick
        bool isUpperWick = closeValue > openValue;
        
        // Calculate new start and end points
        QPointF startPoint, endPoint;
        if (isUpperWick) {
            startPoint = bodyCenter;
            endPoint = bodyCenter + QPointF(0, -newLength/2);
        } else {
            startPoint = bodyCenter;
            endPoint = bodyCenter + QPointF(0, newLength/2);
        }
        
        // Update the line
        setLine(QLineF(startPoint, endPoint));
        
        // Update length and position
        m_length = newLength;
        m_candleStickWickPosition = QLineF(startPoint, endPoint);
        
        update(); // Trigger a redraw of the item
    }
}