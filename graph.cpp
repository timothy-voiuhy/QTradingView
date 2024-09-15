#include "graph.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPoint>
#include <QGraphicsSceneWheelEvent>
#include "candleStickState.h"
#include "graphTimeFrameNode.h"

Graph::Graph(int __pixelsPerPip, const QString &tableName):dbtableName(tableName),
SCENE_MAX_NODES(100), SCENE_BATCH_NODES(10), node_width(50), PIXELS_PER_PIP(__pixelsPerPip){

    db_manager = new dbManager("QTRADINGVIEWFXDATA");
    min_value = db_manager->getMinValue("Low", dbtableName);
    max_value = db_manager->getMaxValue("High", dbtableName);
    numNodes = db_manager->getnNodes(tableName);
    computeSceneRectDimensions();
    loadNodes();
    qDebug() << "there are "<< graphNodes.count() << "nodes";
    populateNodes();
}

Graph::~Graph()
{
    // clear();
}

QPointF Graph::setNodePosition(graphTimeFrameNodeState *nodestate)
{
    QPointF nodePosition;
    nodePosition.setY(nodestate->getHigh()*PRICE_MULTIPLIER);
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
        nodesData = db_manager->loadData(0, SCENE_MAX_NODES, dbtableName);
    } else {
        nodesData = db_manager->loadData(lastNodeId + 1, SCENE_BATCH_NODES, dbtableName);
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
    if(!batch){
        __nodes = graphNodes;
    }else{
        __nodes = batchNodes;
    }
    foreach(graphTimeFrameNode *node, graphNodes){
        node->setPos(setNodePosition(node->getgraphTimeFrameNodeState()));
        qDebug() << node;
        addItem(node);
    }
}

void Graph::computeSceneRectDimensions()
{
    max_position = max_value*PRICE_MULTIPLIER;
    min_position = min_value*PRICE_MULTIPLIER;
    scene_width = numNodes*node_width;
    scene_height = max_position- min_position;
    sceneRect().setTopLeft(QPointF(0, min_position));
    sceneRect().setWidth(scene_width);
    sceneRect().setHeight(scene_height);
}
