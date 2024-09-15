#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMainWindow>

#include "mainwindow.h"
#include "axes.h"
#include "graphTimeFrameNode.h"
#include <QDateTime>
#include <QVector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Create the scene and view
    GraphingScene = new QGraphicsScene(0,0,1000,1000);
    GraphingView = new QGraphicsView(GraphingScene, this);
    setCentralWidget(GraphingView);

    // Example OHLC data
    QVector<double> ohlcData = {2.1212, 2.1292, 2.1197, 2.1277}; // Open, High, Low, Close
    QDateTime timeState = QDateTime::currentDateTime();
    int nodeId = 1;
    bool isDynamic = false;
    int nodeWidth = 50;

        // Example OHLC data
    QVector<double> ohlcData0 = {2.1277, 2.1291, 2.1239, 2.1256}; // Open, High, Low, Close
    QDateTime timeState0 = QDateTime::currentDateTime();
    int nodeId0 = 2;
    bool isDynamic0 = false;
    int nodeWidth0 = 50;

    Axes axes = Axes();
    QPointF pos0 = axes.valueToPosition(1, ohlcData[0]);
    QPointF pos1 = axes.valueToPosition(2, ohlcData0[0]);

    // Create the graphTimeFrameNode
    graphTimeFrameNode *node = new graphTimeFrameNode(ohlcData, timeState, nodeId, isDynamic, nodeWidth);
    node->setPos(100,100);
    graphTimeFrameNode *node0  = new graphTimeFrameNode(ohlcData0, timeState0, nodeId0, isDynamic0, nodeWidth0);
    node0->setPos(155, 100);

    // Add the node to the scene
    GraphingScene->addItem(node);
    GraphingScene->addItem(node0);
}

MainWindow::~MainWindow()
{
    // Clean up
    delete GraphingScene;
    delete GraphingView;
}