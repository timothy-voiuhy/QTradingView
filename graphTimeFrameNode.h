#ifndef GRAPHTIMEFRAMENODE_H
#define GRAPHTIMEFRAMENODE_H

#include <QObject>
#include <QGraphicsItemGroup>

class pathGraphPoint;
class candleStickState;

class graphTimeFrameNode{

    private:
        candleStickState *candle_stick_state;

    public:
        candle *candle_stick;
        pathGraphPoint *path_graph_point;
        candleStickState *getCandleStickState() const;
        candle *getCandleStick() const;
        pathGraphPoint *getPathGraphPoint() const;

        // Setters
        void setCandleStickState(candleStickState *state);
        void setCandleStick(candle *stick);
        void setPathGraphPoint(pathGraphPoint *point);

    protected:
        void mergeNode(); // add the path_graph_point to the contenxt of the candleStick ie the position of
        // the path_graph_point is derived as the average height of the wick of the candleStick.

};

#endif