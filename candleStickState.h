#ifndef CANDLESTICKSTATE_H
#define CANDLESTICKSTATE_H

#include <QPoint>
#include <QColor>
#include <QPen>
#include <QDateTime>

class graphTimeFrameNodeState {
    private:
        bool isDynamic;
        QDateTime timeState;
        double high;
        double low;
        double open;
        double close;
        int id; // the number location in the graph forexample if there are 50 candles then we can locate each depending on what number position they hold

        // colors
        QColor candleStickBodyColor;
        QPen candleStickBodyPen;
        QColor candleStickWickColor;

        // Geometry
        int prevCandleStickWickLength;
        int prevCandleStickBodyLength;
        int curCandleSickWickLength;
        int curCandleStickBodyLength;
        int curCandleStickBodyWidth;

        // location
        QPoint prevCandleStickBodyLocation;
        QPoint curCandleStickBodyLocation;

        QPointF prevCandleStickWickStartPosition;
        QPointF prevCandleStickWickEndPosition;
        QPointF curCandleStickWickEndPosition;
        QPointF curCandleStickWickStartPosition;

    private:
        QPointF curCandleStickBodyTopPosition;
        QPointF curCandleStickBodyBottomPosition;
        QPointF prevCandleStickBodyTopPosition;
        QPointF prevCandleStickBodyBottomPosition;

    public:
        QPointF getCurCandleStickBodyTopPosition() const;
        QPointF getCurCandleStickBodyBottomPosition() const;
        QPointF getPrevCandleStickBodyTopPosition() const;
        QPointF getPrevCandleStickBodyBottomPosition() const;
        void setCurCandleStickBodyTopPosition(const QPointF& position);
        void setCurCandleStickBodyBottomPosition(const QPointF& position);
        void setPrevCandleStickBodyTopPosition(const QPointF& position);
        void setPrevCandleStickBodyBottomPosition(const QPointF& position);

    public:
        // Getters
        double getHigh() const;
        double getLow() const;
        double getOpen() const;
        double getClose() const;
        QDateTime getTimeState() const;
        int getId() const;
        QColor getCandleStickWickColor() const;
        QColor getCandleStickBodyColor() const;
        QPen getCandleStickBodyPen() const;
        QPoint getPrevCandleStickBodyLocation() const;
        QPoint getCurCandleStickBodyLocation() const;

        QPointF getPrevCandleStickWickStartPosition() const;
        QPointF getCurCandleStickWickStartPosition() const;
        QPointF getCurCandleStickWickEndPosition() const;
        QPointF getPrevCandleStickWickEndPositon() const;

        int getPrevCandleStickLength() const;
        int getCurCandleStickWickLength() const;
        int getPrevCandleStickWickLength() const;
        int getPrevCandleStickBodyLength() const;
        int getCurCandleStickBodyWidth() const;
        int getCurCandleStickBodyLength() const;

        // Setters
        void setId(int __id);
        void setTimeState(QDateTime &time_state);
        void setIsDynamic(bool is_dynamic);
        void setHigh(double value);
        void setLow(double value);
        void setOpen(double value);
        void setClose(double value);
        void setCandleStickWickColor(const QColor& color);
        void setCandleStickBodyColor(const QColor& color);
        void setCandleStickBodyPen(const QPen& pen);

        void setCurCandleStickWickLength(double length);
        void setPrevCandleStickBodyLength(int length);
        void setCurCandleStickBodyWidth(int width);
        void setPrevCandleStickWickLength(double length);
        void setCurCandleSickBodyLength(double length);

        void setPrevCandleStickBodyLocation(const QPoint& location);
        void setCurCandleStickBodyLocation(const QPoint& location);

        void setPrevCandleStickWickStartPosition(const QPointF& position);
        void setCurCandleStickWickStartPosition(const QPointF& position);
        void setCurCandleStickWickEndPosition(const QPointF& position);
        void setPrevCandleStickWickEndPositon(const QPointF& position);

        QVector<double> getOHLCdata();
        QDateTime getCandleDateTime();
        bool isBull();
        bool isfirst;
};

#endif