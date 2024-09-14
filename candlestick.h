#ifndef CANDLESTICK_H
#define CANDLESTICK_H

#include <QPen>
#include "candleStickState.h"

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
    explicit candle(QGraphicsItem *parent = nullptr, graphTimeFrameNodeState *nodestate);
    ~candle();
    candleBody *candle_stick_body;
    candleStickWick *candle_stick_wick;
    double open;
    double close;
    double high;
    double low;
    QVector<double> ohlcData;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    // void drawCandleStick();
    protected:
        graphTimeFrameNodeState *node_state;
        bool m_isHighlighted;
        void setHighlighted(bool highlighted);
        void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
        void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
};

#endif
