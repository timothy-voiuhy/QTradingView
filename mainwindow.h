#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QGraphicsView;
class QGraphicsScene;

class MainWindow:public QMainWindow {
    public:
        QGraphicsView *GraphingView;
        QGraphicsScene *GraphingScene;
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
};
#endif