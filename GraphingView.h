#ifndef GRAPHINGVIEW_H
#define GRAPHINGVIEW_H

#include <QGraphicsView>
#include <QWheelEvent>
#include <QMouseEvent>

class GraphingView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit GraphingView(QWidget *parent = nullptr);
    ~GraphingView();

protected:
    void wheelEvent(QWheelEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    bool panning;
    QPoint lastMousePos;
};

#endif // GRAPHINGVIEW_H
