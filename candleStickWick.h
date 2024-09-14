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
        explicit candleStickWick(QGraphicsItem *parent = nullptr,
        QVector<double> ohlcData,
        QColor wickColor = nullptr);
        ~candleStickWick();
        qreal getLength() const;
        void setColor(const QColor &color);
        void setLength(qreal length);
        double lowValue;
        double highValue;
        double closeValue;
        double openValue;

    private:
        QColor m_color;
        qreal m_length;
        QLineF m_candleStickWickPosition;
        void setDirectionColor();
};

#endif // CANDLESTICKWICK_H