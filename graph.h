#ifndef GRAPH_H
#define GRAPH_H

#include "dbManager.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPointF>
#include <QVector>

class graphTimeFrameNode;
class graphTimeFrameNodeState;

class Graph:public QGraphicsScene{

    private:
        double PRICE_MULTIPLIER = 10000;
        double PIXELS_PER_PIP;
        double rel_position;
        double firstHigh;
        int lastNodeId;
        int SCENE_MAX_NODES;
        int SCENE_BATCH_NODES; // when adding nodes dynamically to the scene which alreay has nodes, the nodes are to added in batches
        QVector<QPointF> *node_positions;
        QVector<graphTimeFrameNode*> graphNodes;
        QVector<graphTimeFrameNode*> batchNodes; // has to be intialized with the first batch
        QPointF setNodePosition(graphTimeFrameNode *node);
        void loadNodes(bool batch = false);
        void computeSceneRectDimensions();
        void populateNodes(bool batch = false);
        dbManager *db_manager;
        double transformYCoordinate(double y);
        int numNodes;
    protected:
        int node_width, scene_width, scene_height;
        int MAX_NODES; // this define the maximum nodes that can  be placed in a scene at ounce
        double max_value, min_value, max_position, min_position;
    public:
        QString dbtableName;
        Graph(int __pixelsPerPip, const QString &tableName);
        ~Graph();
};

#endif