#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMainWindow>

#include "mainwindow.h"
#include "graphTimeFrameNode.h"
#include <QDateTime>
#include <QVector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Create the scene and view
    GraphingScene = new QGraphicsScene(this);
    GraphingView = new QGraphicsView(GraphingScene, this);
    setCentralWidget(GraphingView);

    // Example OHLC data
    QVector<double> ohlcData = {2.1212, 2.1292, 2.1197, 2.1277}; // Open, High, Low, Close
    QDateTime timeState = QDateTime::currentDateTime();
    int nodeId = 1;
    bool isDynamic = false;
    int nodeWidth = 50;

    // Create the graphTimeFrameNode
    graphTimeFrameNode *node = new graphTimeFrameNode(ohlcData, timeState, nodeId, isDynamic, nodeWidth);

    // Add the node to the scene
    GraphingScene->addItem(node);
}

MainWindow::~MainWindow()
{
    // Clean up
    delete GraphingScene;
    delete GraphingView;
}