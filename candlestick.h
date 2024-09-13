#ifndef CANDLESTICK_H
#define CANDLESTICK_H

#include <QPen>

class QGraphicsRectItem;
class QGraphicsLineItem;
class pathGraphPoint;
class graphTimeFrameNode;
class QRectF;
class QLineF;
class QPoint;
class candleBody;
class candleStickWick;

class candle: public QGraphicsItemGroup{

public:
    explicit candle(QGraphicsItem *parent = nullptr,
                QColor candleBodyColor,
                QColor candleStickColor,
                QVector<double> ohlcData);
    ~candle();
    candleBody *candle_stick_body;
    candleStickWick *candle_stick_wick;
    double getWickTop();
    double getWickBottom();
    double open;
    double close;
    double high;
    double low;

    // void drawCandleStick();
    protected:
        bool m_isHighlighted;
        void setHighlighted(bool highlighted);
        void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
        void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
};

class pathGraphPoint : public QPoint{

};


#endif
