#ifndef GRAPH_H
#define GRAPH_H

#include "dbManager.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPointF>
#include <QVector>

class graphTimeFrameNode;

class Graph: QGraphicsScene{

    private:
        double PRICE_MULTIPLIER = 10000;
        double PIXELS_PER_PIP;
        int lastNodeId;
        int SCENE_MAX_NODES;
        int SCENE_BATCH_NODES; // when adding nodes dynamically to the scene which alreay has nodes, the nodes are to added in batches
        QVector<graphTimeFrameNode*> graphNodes;
        QVector<graphTimeFrameNode*> batchNodes; // has to be intialized with the first batch
        QPointF setNodePosition(graphTimeFrameNodeState *nodestate);
        void loadNodes(bool batch = false);
        void computeSceneRectDimensions();
        void populateNodes(bool batch = false);
        dbManager *db_manager;
    protected:
        int node_width, scene_width, scene_height;
        int MAX_NODES; // this define the maximum nodes that can  be placed in a scene at ounce
        double max_value, min_value, max_position, min_position;
    public:
        Graph(int __pixelsPerPip);
        ~Graph();
};

#endif