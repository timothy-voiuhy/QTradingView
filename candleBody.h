#ifndef CANDLEBODY_H
#define CANDLEBODY_H

#include <QObject>
#include <QRectF>
#include <QGraphicsRectItem>

class graphTimeFrameNodeState;

class candleBody : public QObject ,  public QGraphicsRectItem{
    Q_OBJECT

    public:
        explicit candleBody(QGraphicsItem *parent = nullptr, graphTimeFrameNodeState *nodestate = nullptr);
        ~candleBody();

    private:
        bool m_isHighlighted;

    public:
        graphTimeFrameNodeState *node_state;
        bool isHighlighted() const;
        void setHighlighted(bool highlighted);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

};

#endif // candleBody_H