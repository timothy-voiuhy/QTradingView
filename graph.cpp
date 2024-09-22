#include "graph.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPoint>
#include <QGraphicsSceneWheelEvent>
#include "candleStickState.h"
#include "graphTimeFrameNode.h"

Graph::Graph(int __pixelsPerPip, const QString &tableName):dbtableName(tableName),
SCENE_MAX_NODES(5365), SCENE_BATCH_NODES(10), node_width(50), PIXELS_PER_PIP(__pixelsPerPip),
node_positions(nullptr){

    db_manager = new dbManager("QTRADINGVIEWFXDATA");
    min_value = db_manager->getMinValue("Low", dbtableName);
    max_value = db_manager->getMaxValue("High", dbtableName);
    numNodes = db_manager->getnNodes(tableName);
    computeSceneRectDimensions();
    loadNodes();
    populateNodes();
}

Graph::~Graph()
{
    // clear();
}

double Graph::transformYCoordinate(double y){
    double qtgraphmin  = max_position;
    double qtgraphmax = min_position;
    double ngraphmin = min_position;
    double ngraphmax  = max_position;

    double qt_transform = qtgraphmin + (qtgraphmax- qtgraphmin)*((y-ngraphmin)/(ngraphmax- ngraphmin));
    return qt_transform;

}

QPointF Graph::setNodePosition(graphTimeFrameNode *node)
{
    graphTimeFrameNodeState *nodestate =  node->getgraphTimeFrameNodeState();
    QPointF nodePosition;
    if(nodestate->isfirst == true){
        double y_coordinate = transformYCoordinate(nodestate->getHigh()*PRICE_MULTIPLIER);
        firstHigh = nodestate->getHigh();
        nodePosition.setY(y_coordinate);
        rel_position = y_coordinate;
    }else{
        double pip_difference = node->getFollowCandleNodeState()->getHigh() - nodestate->getHigh();
        double pixels_equiv  = pip_difference*PRICE_MULTIPLIER;
        double y_coordinate = rel_position + pixels_equiv;
        rel_position = y_coordinate;
        nodePosition.setY(y_coordinate);
    }
    nodePosition.setX(scene_width- (nodestate->getId()*node_width));
    // node_positions.append(nodePosition);
    return nodePosition;
}

void Graph::loadNodes(bool batch)
{
    int idCount = 1;
    QVector<QPair<QVector<double>, QDateTime>> nodesData;
    if (!batch) {
        nodesData = db_manager->loadData(0, SCENE_MAX_NODES, dbtableName);
    } else {
        nodesData = db_manager->loadData(lastNodeId + 1, SCENE_BATCH_NODES, dbtableName);
    }
    QVector<graphTimeFrameNode *> nodes;
    int count = 0;
    bool is_first = false;
    graphTimeFrameNodeState *follow_candle_state;
    for (auto& nodedata : nodesData) { // Change to non-const to allow reference passing
        // qDebug() << nodedata.first;
        if(count == 0){
            is_first = true;
        }else{
            is_first = false;
        }
        graphTimeFrameNode *__node = new graphTimeFrameNode(nodedata.first, nodedata.second, idCount++, false, node_width, PIXELS_PER_PIP, is_first, follow_candle_state);
        follow_candle_state = __node->getgraphTimeFrameNodeState();
        nodes.append(__node);
        count++;
    }
    if (!batch) {
        graphNodes = nodes;
    } else {
        batchNodes = nodes;
    }
}

void Graph::populateNodes(bool batch){
    QVector<graphTimeFrameNode *> __nodes;
    if(!batch){
        __nodes = graphNodes;
    }else{
        __nodes = batchNodes;
    }
    foreach(graphTimeFrameNode *node, graphNodes){
        node->setPos(setNodePosition(node));
        addItem(node);
    }
}

void Graph::computeSceneRectDimensions()
{
    max_position = max_value*PRICE_MULTIPLIER;
    min_position = min_value*PRICE_MULTIPLIER;
    scene_width = numNodes*node_width;
    scene_height = max_position- min_position;
    // sceneRect().setHeight(scene_height);
    setSceneRect(QRectF(0, min_position, scene_width, scene_height));
    qDebug() << "min_position: " << min_position ;
    qDebug() << "max_position: "<< max_position;
    qDebug() << sceneRect();
    qDebug() << "scene_width: " << scene_width;
    qDebug() << "scene_height: " << scene_height;
}
