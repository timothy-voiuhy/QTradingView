#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include "mainwindow.h"
#include "graphWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{   
    central_widget = new QWidget();
    setCentralWidget(central_widget);

    main_layout = new QVBoxLayout();
    central_widget->setLayout(main_layout);

    graphwindow = new GraphWindow();
    main_layout->addWidget(graphwindow);
    
}

MainWindow::~MainWindow()
{
}