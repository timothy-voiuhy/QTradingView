#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMainWindow>

#include "mainwindow.h"
#include "graphTimeFrameNode.h"

MainWindow::MainWindow(){
    GraphingScene = new QGraphicsScene();
    GraphingView = new QGraphicsView(GraphingScene);
    // candlestick testing
    graphTimeFrameNode *candle  = new graphTimeFrameNode();
    GraphingScene->addItem(candle);
}

MainWindow::~MainWindow(){

}