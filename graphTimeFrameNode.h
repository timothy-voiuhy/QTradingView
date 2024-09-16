#ifndef GRAPHTIMEFRAMENODE_H
#define GRAPHTIMEFRAMENODE_H

#include <QObject>
#include <QGraphicsItemGroup>
#include <QDateTime>
#include <QVector>

class pathGraphPoint;
class graphTimeFrameNodeState;
// class candle;
class candleBody;
class candleStickWick;

class graphTimeFrameNode :public QGraphicsItemGroup{

    private:
        graphTimeFrameNodeState *node_state;
        void mergeNode(); // add the path_graph_point to the contenxt of the candleStick ie the position of
        // the path_graph_point is derived as the average height of the wick of the candleStick.
        void populateInternalState();
        bool isStateInitialized;


    public:
        explicit graphTimeFrameNode(QVector<double> &ohlcData, QDateTime &time_state, int id, bool isDynamic, int nodewidth, int __pixelsPerPip);
        ~graphTimeFrameNode();

        // group items
        // candle *candle_stick;
        pathGraphPoint *path_graph_point;
        QRectF bounding_rect;
        candleBody *candle_stick_body;
        candleStickWick *candle_stick_wick;
        graphTimeFrameNodeState *getgraphTimeFrameNodeState();
        pathGraphPoint *getPathGraphPoint() const;
        QRectF boundingRect() const override;
        QVector<double> ohlcData;
        QDateTime node_time_state;
        QPointF valueToPosition(double value);
        int node_id;
        bool isNodeDynamic;
        double range;
        int node_width;
        int node_height;
        int node_scale;
        double pixelsPerPip;
        void setScale();
        void setRange();
        double getPixelsPerPip();
        void setNodeHeight();
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
        void setgraphTimeFrameNodeState(graphTimeFrameNodeState *state);
        void setIsStateInitialized(bool state);
        void updateNodeGeometry(double current_price);
        void initializeState();
        void setPosition(qreal x, qreal y);

    protected:
        void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
        void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
};

#endif