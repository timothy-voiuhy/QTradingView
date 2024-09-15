#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class GraphingView;
class Graph;

class MainWindow:public QMainWindow {
    public:
        GraphingView *graphingView;
        Graph *GraphingScene;
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
};
#endif