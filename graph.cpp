#include "graph.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPoint>
#include "candleStickState.h"
#include "graphTimeFrameNode.h"

Graph::Graph(int __pixelsPerPip){

    db_manager = new dbManager("EURUSD");
    min_value = db_manager->getMinValue("low");
    max_value = db_manager->getMaxValue("high");
    computeSceneRectDimensions();
    loadNodes();
    populateNodes();
}

Graph::~Graph()
{
    clear();
}

QPointF Graph::setNodePosition(graphTimeFrameNodeState *nodestate)
{
    QPointF nodePosition;
    nodePosition.setY(nodestate->getHigh()*PRICE_MULTIPLIER*PIXELS_PER_PIP);
    if(nodestate->getId()==0){
        nodePosition.setX(scene_width-10); // from right to left while ploting the nodes
    }else{
        nodePosition.setX(scene_width- (nodestate->getId()*node_width));
    }
    return nodePosition;
}

void Graph::loadNodes(bool batch)
{
    int idCount = 0;
    QVector<QPair<QVector<double>, QDateTime>> nodesData;
    if (!batch) {
        nodesData = db_manager->loadData(0, SCENE_MAX_NODES);
    } else {
        nodesData = db_manager->loadData(lastNodeId + 1, SCENE_BATCH_NODES);
    }
    QVector<graphTimeFrameNode *> nodes;
    for (auto& nodedata : nodesData) { // Change to non-const to allow reference passing
        graphTimeFrameNode *__node = new graphTimeFrameNode(nodedata.first, nodedata.second, idCount++, false, node_width, PIXELS_PER_PIP);
        nodes.append(__node);
    }
    if (!batch) {
        graphNodes = nodes;
    } else {
        batchNodes = nodes;
    }
}

void Graph::populateNodes(bool batch){
    QVector<graphTimeFrameNode *> __nodes;
    if(batch == false){
        __nodes = graphNodes;
    }else{
        __nodes = batchNodes;
    }
    foreach(graphTimeFrameNode *node, graphNodes){
    node->setPos(setNodePosition(node->getgraphTimeFrameNodeState()));
    addItem(node);
    }
}

void Graph::computeSceneRectDimensions()
{
    max_position = max_value*PRICE_MULTIPLIER;
    min_position = min_value*PRICE_MULTIPLIER;
    scene_width = graphNodes.count()*node_width;
    scene_height = max_position- min_position;
    setSceneRect(QRectF(0, max_position, scene_width, scene_height));
}
