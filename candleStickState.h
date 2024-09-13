#ifndef CANDLESTICKSTATE_H
#define CANDLESTICKSTATE_H

#include <QPoint>
#include <QColor>
#include <QPen>

class candleState {
private:
    QPoint prevCandleStickBodyLocation;
    QPoint curCandleStickBodyLocation;
    QPoint prevCandleStickStartPosition;
    QPoint curCandleStickEndPosition;
    int prevCandleStickLength;
    int curCandleSickLength;
    int prevCandleStickBodyLength;
    int curCandleStickBodyWidth;
    QColor candleStickColor;
    QColor candleStickBodyColor;
    QPen candleStickPen;
    QPen candleStickBodyPen;
    double high;
    double low;
    double open;
    double close;

public:
    // Getters
    double getHigh() const;
    double getLow() const;
    double getOpen() const;
    double getClose() const;
    QColor getCandleStickColor() const;
    QColor getCandleStickBodyColor() const;
    QPen getCandleStickPen() const;
    QPen getCandleStickBodyPen() const;
    QPoint getPrevCandleStickBodyLocation() const;
    QPoint getCurCandleStickBodyLocation() const;
    QPoint getPrevCandleStickStartPosition() const;
    QPoint getCurCandleStickEndPosition() const;
    int getPrevCandleStickLength() const;
    int getCurCandleSickLength() const;
    int getPrevCandleStickBodyLength() const;
    int getCurCandleStickBodyWidth() const;

    // Setters
    void setHigh(double value);
    void setLow(double value);
    void setOpen(double value);
    void setClose(double value);
    void setCandleStickColor(const QColor& color);
    void setCandleStickBodyColor(const QColor& color);
    void setCandleStickPen(const QPen& pen);
    void setCandleStickBodyPen(const QPen& pen);
    void setPrevCandleStickBodyLocation(const QPoint& location);
    void setCurCandleStickBodyLocation(const QPoint& location);
    void setPrevCandleStickStartPosition(const QPoint& position);
    void setCurCandleStickEndPosition(const QPoint& position);
    void setPrevCandleStickLength(int length);
    void setCurCandleSickLength(int length);
    void setPrevCandleStickBodyLength(int length);
    void setCurCandleStickBodyWidth(int width);
};

#endif