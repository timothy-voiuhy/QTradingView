#ifndef CANDLESTICKWICK_H
#define CANDLESTICKWICK_H

#include <QObject>
#include <QColor>
#include <QPointF>
#include <QLineF>
#include <QGraphicsLineItem>

class graphTimeFrameNodeState;

class candleStickWick : public QObject , public QGraphicsLineItem{
    Q_OBJECT

    public:
        explicit candleStickWick(QGraphicsItem *parent = nullptr, graphTimeFrameNodeState* nodestate);
        ~candleStickWick();
        void setLength(qreal length);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
        graphTimeFrameNodeState *node_state;
};

#endif // CANDLESTICKWICK_H