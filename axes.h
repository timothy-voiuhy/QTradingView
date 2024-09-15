#ifndef AXES_H
#define AXES_H

#include <QGraphicsItem>
#include <QPainter>

class Axes
{
public:
    Axes(double widht = 100, double height = 100);
    ~Axes();
    double scene_height, scene_width;
    QPointF valueToPosition(double xValue, double yValue) const;
    // QRectF boundingRect() const override;
    // void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    void drawAxes(QPainter *painter);
};

#endif // AXES_H
