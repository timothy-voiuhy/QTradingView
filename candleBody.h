#ifndef CANDLEBODY_H
#define CANDLEBODY_H

#include <QObject>
#include <QRectF>
#include <QGraphicsRectItem>

class candleBody : public QObject ,  public QGraphicsRectItem{
    Q_OBJECT

    public:
        explicit candleBody(QGraphicsItem *parent = nullptr, double open, double close);
        ~candleBody();

    public slots:
        void onMouseEnter();
        void onMouseClick();

    private:
        QRectF m_candleBodyPosition;
        QColor m_color;
        bool m_isHighlighted;
        void setDirectionColor();

    public:
        QRectF getCandleBodyPosition() const;
        QColor getColor() const;
        bool isHighlighted() const;
        void setCandleBodyPosition(const QRectF &position);
        void setColor(const QColor &color);
        void setHighlighted(bool highlighted);
        double openValue;
        double closeValue;

};

#endif // candleBody_H