#include "graphTimeFrameNode.h"
#include "candleStickState.h"
#include "candlestick.h"
#include "pathGraphPoint.h"
#include "candleStickWick.h"
#include <QPoint>

candleStickState *graphTimeFrameNode::getCandleStickState() const {
    return candle_stick_state;
}

candle *graphTimeFrameNode::getCandleStick() const
{
    return candle_stick;
}

pathGraphPoint *graphTimeFrameNode::getPathGraphPoint() const {
    return path_graph_point;
}

void graphTimeFrameNode::setCandleStickState(candleStickState *state) {
    candle_stick_state = state;
}

void graphTimeFrameNode::setCandleStick(candle *stick) {
    candle_stick = stick;
}

void graphTimeFrameNode::setPathGraphPoint(pathGraphPoint *point) {
    path_graph_point = point;
}

void graphTimeFrameNode::mergeNode() {
    // This function should add the path_graph_point to the context of the candleStick
    // The position of the path_graph_point is derived as the average height of the wick of the candleStick
    
    double wickTop = candle_stick->getWickTop();
    double wickBottom = candle_stick->getWickBottom();
    
    // Calculate the average height of the wick
    double averageWickHeight = (wickTop + wickBottom) / 2.0;
    // the x value is the same as candlestick 
    path_graph_point->setY(averageWickHeight);
    path_graph_point->setX(candle_stick->candle_stick_wick->x());
}
