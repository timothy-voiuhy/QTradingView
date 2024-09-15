#include "GraphingView.h"
#include <QGraphicsScene>
#include <QMainWindow>
#include "mainwindow.h"
#include "axes.h"
#include "graphTimeFrameNode.h"
#include <QDateTime>
#include <QVector>
#include "graph.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Create the scene and view
    GraphingScene = new Graph(4, "EURUSD_D1");
    graphingView = new GraphingView(this);
    graphingView->setScene(GraphingScene);
    setCentralWidget(graphingView);
}

MainWindow::~MainWindow()
{
    // Clean up
    delete GraphingScene;
    delete graphingView;
}