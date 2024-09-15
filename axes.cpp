#include "axes.h"
#include <QGraphicsScene>

Axes::Axes(double width, double height):scene_height(height), scene_width(width)
{
}

Axes::~Axes()
{
}

// QRectF Axes::boundingRect() const
// {
//     return QRectF();
// }

// void Axes::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
// {
// }

void Axes::drawAxes(QPainter *painter)
{
}

QPointF Axes::valueToPosition(double xValue, double yValue) const
{
    // Assuming the bounding rect's top is 0 and bottom is the height of the scene
    double sceneHeight = scene_height;
    double sceneWidth = scene_width;
    
    // Convert the yValue to a position within the scene
    double y = sceneHeight - (yValue * sceneHeight); // Invert the value to match screen coordinates
    
    // Convert the xValue to a position within the scene
    double x = xValue * sceneWidth; // Scale the xValue to match the scene width

    return QPointF(x, y);
}
