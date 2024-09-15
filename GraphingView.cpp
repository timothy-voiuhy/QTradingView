#include "GraphingView.h"
#include "graphTimeFrameNode.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWheelEvent>
#include <QScrollBar>
#include <QMouseEvent>

GraphingView::GraphingView(QWidget *parent)
    : QGraphicsView(parent), panning(false)
{
    setRenderHint(QPainter::Antialiasing);
    setDragMode(QGraphicsView::ScrollHandDrag);
    setOptimizationFlags(QGraphicsView::DontSavePainterState);
    setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
}

GraphingView::~GraphingView()
{
}

void GraphingView::wheelEvent(QWheelEvent *event)
{
    const double scaleFactor = 1.15;
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
