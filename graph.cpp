#include "graph.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPoint>
#include <QGraphicsSceneWheelEvent>
#include "candleStickState.h"
#include "graphTimeFrameNode.h"

Graph::Graph(int __pixelsPerPip, const QString &tableName):dbtableName(tableName),
SCENE_MAX_NODES(5365), SCENE_BATCH_NODES(10), node_width(50), PIXELS_PER_PIP(__pixelsPerPip){

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

QPointF Graph::setNodePosition(graphTimeFrameNodeState *nodestate)
{
    QPointF nodePosition;
    nodePosition.setY((transformYCoordinate(nodestate->getHigh()*PRICE_MULTIPLIER)));
    nodePosition.setX(scene_width- (nodestate->getId()*node_width));
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
    for (auto& nodedata : nodesData) { // Change to non-const to allow reference passing
        // qDebug() << nodedata.first;
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
