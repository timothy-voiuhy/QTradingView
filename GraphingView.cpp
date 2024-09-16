#include "GraphingView.h"
#include "graphTimeFrameNode.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWheelEvent>
#include <QScrollBar>
#include <QMouseEvent>
#include <QBrush>
#include <Qt>

GraphingView::GraphingView(QWidget *parent)
    : QGraphicsView(parent), panning(false), verticalScaleFactor(1), horizontalScaleFactor(1)
{
    // setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setRenderHint(QPainter::Antialiasing);
    setDragMode(QGraphicsView::ScrollHandDrag);
    setOptimizationFlags(QGraphicsView::DontSavePainterState);
    setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setBackgroundBrush(QBrush(Qt::white));
}

GraphingView::~GraphingView()
{
}

void GraphingView::setHorizontalScale(int value){
    double scaleFactor = value / 100.0;
    scale(scaleFactor / horizontalScaleFactor, 1.0);
    horizontalScaleFactor = scaleFactor;
}

void GraphingView::setVerticalScale(int value){
    double scaleFactor = value / 100.0;
    scale(1.0, scaleFactor / verticalScaleFactor);
    verticalScaleFactor = scaleFactor;
}

void GraphingView::wheelEvent(QWheelEvent *event)
{   
    const double scaleFactor = 1.15;
    verticalScaleFactor = scaleFactor;
    horizontalScaleFactor = scaleFactor;
    if (event->angleDelta().y() > 0) {
        scale(scaleFactor, scaleFactor);
    } else {
        scale(1.0 / scaleFactor, 1.0 / scaleFactor);
    }
}

void GraphingView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        panning = true;
        lastMousePos = event->pos();
        setCursor(Qt::ClosedHandCursor);
    }
    QGraphicsView::mousePressEvent(event);
}

void GraphingView::mouseMoveEvent(QMouseEvent *event)
{
    if (panning) {
        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - (event->x() - lastMousePos.x()));
        verticalScrollBar()->setValue(verticalScrollBar()->value() - (event->y() - lastMousePos.y()));
        lastMousePos = event->pos();
    }
    QGraphicsView::mouseMoveEvent(event);
}

void GraphingView::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        panning = false;
        setCursor(Qt::ArrowCursor);
    }
    QGraphicsView::mouseReleaseEvent(event);
}
