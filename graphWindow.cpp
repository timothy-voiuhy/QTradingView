#include "graphWindow.h"
#include "GraphingView.h"
#include <QGraphicsScene>
#include "axes.h"
#include "graphTimeFrameNode.h"
#include <QDateTime>
#include <QVector>
#include "graph.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSlider>

GraphWindow::GraphWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Create the scene and view
    GraphingScene = new Graph(4, "EURUSD_D1");
    graphingView = new GraphingView(this);
    graphingView->setScene(GraphingScene);
    setupUi();
    setupConnections();
}

GraphWindow::~GraphWindow()
{
    // Clean up
    delete GraphingScene;
    delete graphingView;
}

void GraphWindow::setupUi()
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QHBoxLayout *viewLayout = new QHBoxLayout();
    verticalSlider = new QSlider(Qt::Vertical, this);
    verticalSlider->setRange(50, 500); // Adjust range as needed
    verticalSlider->setValue(250);

    viewLayout->addWidget(verticalSlider);
    viewLayout->addWidget(graphingView);

    horizontalSlider = new QSlider(Qt::Horizontal, this);
    horizontalSlider->setRange(50, 500); // Adjust range as needed
    horizontalSlider->setValue(250);

    mainLayout->addLayout(viewLayout);
    mainLayout->addWidget(horizontalSlider);

    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

void GraphWindow::setupConnections()
{
    connect(horizontalSlider, &QSlider::valueChanged, graphingView, &GraphingView::setHorizontalScale);
    connect(verticalSlider, &QSlider::valueChanged, graphingView, &GraphingView::setVerticalScale);
}
