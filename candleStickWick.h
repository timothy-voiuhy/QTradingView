#ifndef CANDLESTICKWICK_H
#define CANDLESTICKWICK_H

#include <QObject>
#include <QColor>
#include <QPointF>
#include <QLineF>
#include <QGraphicsLineItem>

class candleStickWick : public QObject , public QGraphicsLineItem{
    Q_OBJECT

    public:
        candleStickWick(QGraphicsItem *parent = nullptr,
            QVector<double> ohlcData,
            QColor wickColor = nullptr);
        ~candleStickWick();
        qreal getLength() const;
        QPointF getPreviousLocation() const;
        void setColor(const QColor &color);
        void setLength(qreal length);
        void setPreviousLocation(const QPointF &location);
        double lowValue;
        double highValue;
        double closeValue;
        double openValue;

    private:
        QColor m_color;
        qreal m_length;
        QPointF m_previousLocation;
        QLineF m_candleStickWickPosition;
        void setDirectionColor();
        void setUpSlots();

    signals:
        void colorChanged(const QColor &color);
        void lengthChanged(qreal length);
        void previousLocationChanged(const QPointF &location);
};

#endif // CANDLESTICKWICK_H