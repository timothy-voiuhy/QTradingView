#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QMainWindow>
#include <QSlider>

class GraphingView;
class Graph;

class GraphWindow : public QMainWindow
{
    Q_OBJECT

public:
    Graph *GraphingScene;
    explicit GraphWindow(QWidget *parent = nullptr);
    ~GraphWindow();

private:
    void setupUi();
    void setupConnections();

    GraphingView *graphingView;
    QSlider *horizontalSlider;
    QSlider *verticalSlider;
};

#endif // GRAPHWINDOW_H
