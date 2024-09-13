#include "candleStickState.h"

// Getters
double candleState::getHigh() const {
    return high;
}

double candleState::getLow() const {
    return low;
}

double candleState::getOpen() const {
    return open;
}

double candleState::getClose() const {
    return close;
}

QColor candleState::getCandleStickColor() const {
    return candleStickColor;
}

QColor candleState::getCandleStickBodyColor() const {
    return candleStickBodyColor;
}

QPen candleState::getCandleStickPen() const {
    return candleStickPen;
}

QPen candleState::getCandleStickBodyPen() const {
    return candleStickBodyPen;
}

QPoint candleState::getPrevCandleStickBodyLocation() const {
    return prevCandleStickBodyLocation;
}

QPoint candleState::getCurCandleStickBodyLocation() const {
    return curCandleStickBodyLocation;
}

QPoint candleState::getPrevCandleStickStartPosition() const {
    return prevCandleStickStartPosition;
}

QPoint candleState::getCurCandleStickEndPosition() const {
    return curCandleStickEndPosition;
}

int candleState::getPrevCandleStickLength() const {
    return prevCandleStickLength;
}

int candleState::getCurCandleSickLength() const {
    return curCandleSickLength;
}

int candleState::getPrevCandleStickBodyLength() const {
    return prevCandleStickBodyLength;
}

int candleState::getCurCandleStickBodyWidth() const {
    return curCandleStickBodyWidth;
}

// Setters
void candleState::setHigh(double value) {
    high = value;
}

void candleState::setLow(double value) {
    low = value;
}

void candleState::setOpen(double value) {
    open = value;
}

void candleState::setClose(double value) {
    close = value;
}

void candleState::setCandleStickColor(const QColor& color) {
    candleStickColor = color;
}

void candleState::setCandleStickBodyColor(const QColor& color) {
    candleStickBodyColor = color;
}

void candleState::setCandleStickPen(const QPen& pen) {
    candleStickPen = pen;
}

void candleState::setCandleStickBodyPen(const QPen& pen) {
    candleStickBodyPen = pen;
}

void candleState::setPrevCandleStickBodyLocation(const QPoint& location) {
    prevCandleStickBodyLocation = location;
}

void candleState::setCurCandleStickBodyLocation(const QPoint& location) {
    curCandleStickBodyLocation = location;
}

void candleState::setPrevCandleStickStartPosition(const QPoint& position) {
    prevCandleStickStartPosition = position;
}

void candleState::setCurCandleStickEndPosition(const QPoint& position) {
    curCandleStickEndPosition = position;
}

void candleState::setPrevCandleStickLength(int length) {
    prevCandleStickLength = length;
}

void candleState::setCurCandleSickLength(int length) {
    curCandleSickLength = length;
}

void candleState::setPrevCandleStickBodyLength(int length) {
    prevCandleStickBodyLength = length;
}

void candleState::setCurCandleStickBodyWidth(int width) {
    curCandleStickBodyWidth = width;
}