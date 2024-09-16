#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QMainWindow>

class GraphWindow;

class MainWindow:public QMainWindow {
    private:
        QWidget *central_widget;
        GraphWindow *graphwindow;
        QVBoxLayout *main_layout;
    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
};
#endif