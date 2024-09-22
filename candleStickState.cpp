#include "candleStickState.h"

// Getters
double graphTimeFrameNodeState::getHigh() const {
    return high;
}

double graphTimeFrameNodeState::getLow() const {
    return low;
}

double graphTimeFrameNodeState::getOpen() const {
    return open;
}

double graphTimeFrameNodeState::getClose() const {
    return close;
}

QDateTime graphTimeFrameNodeState::getTimeState() const
{
    return QDateTime();
}

int graphTimeFrameNodeState::getId() const
{
    return id;
}

QColor graphTimeFrameNodeState::getCandleStickWickColor() const {
    return candleStickWickColor;
}

QColor graphTimeFrameNodeState::getCandleStickBodyColor() const {
    return candleStickBodyColor;
}

QPen graphTimeFrameNodeState::getCandleStickBodyPen() const {
    return candleStickBodyPen;
}

QPoint graphTimeFrameNodeState::getPrevCandleStickBodyLocation() const {
    return prevCandleStickBodyLocation;
}

QPoint graphTimeFrameNodeState::getCurCandleStickBodyLocation() const {
    return curCandleStickBodyLocation;
}

QPointF graphTimeFrameNodeState::getPrevCandleStickWickStartPosition() const {
    return prevCandleStickWickStartPosition;
}

QPointF graphTimeFrameNodeState::getCurCandleStickWickStartPosition() const
{
    return curCandleStickWickStartPosition;
}

QPointF graphTimeFrameNodeState::getCurCandleStickWickEndPosition() const {
    return curCandleStickWickEndPosition;
}

QPointF graphTimeFrameNodeState::getPrevCandleStickWickEndPositon() const
{
    return prevCandleStickWickEndPosition;
}

int graphTimeFrameNodeState::getPrevCandleStickLength() const {
    return prevCandleStickWickLength;
}

int graphTimeFrameNodeState::getCurCandleStickWickLength() const {
    return curCandleSickWickLength;
}

int graphTimeFrameNodeState::getPrevCandleStickWickLength() const
{
    return prevCandleStickWickLength;
}

int graphTimeFrameNodeState::getPrevCandleStickBodyLength() const {
    return prevCandleStickBodyLength;
}

int graphTimeFrameNodeState::getCurCandleStickBodyWidth() const {
    return curCandleStickBodyWidth;
}

int graphTimeFrameNodeState::getCurCandleStickBodyLength() const
{
    return curCandleStickBodyLength;
}

void graphTimeFrameNodeState::setId(int __id)
{
    id = __id;
}

void graphTimeFrameNodeState::setTimeState(QDateTime &time_state)
{
    timeState = time_state;
}

void graphTimeFrameNodeState::setIsDynamic(bool is_dynamic)
{
    isDynamic = is_dynamic;
}

// Setters
void graphTimeFrameNodeState::setHigh(double value) {
    high = value;
}

void graphTimeFrameNodeState::setLow(double value) {
    low = value;
}

void graphTimeFrameNodeState::setOpen(double value) {
    open = value;
}

void graphTimeFrameNodeState::setClose(double value) {
    close = value;
}

void graphTimeFrameNodeState::setCandleStickWickColor(const QColor& color) {
    candleStickWickColor = color;
}

void graphTimeFrameNodeState::setCandleStickBodyColor(const QColor& color) {
    candleStickBodyColor = color;
}

void graphTimeFrameNodeState::setCandleStickBodyPen(const QPen& pen) {
    candleStickBodyPen = pen;
}

void graphTimeFrameNodeState::setCurCandleStickWickLength(double length)
{
    curCandleSickWickLength = length;
}

void graphTimeFrameNodeState::setPrevCandleStickWickLength(double length)
{
    prevCandleStickWickLength = length;
}

void graphTimeFrameNodeState::setCurCandleSickBodyLength(double length)
{
    curCandleStickBodyLength = length;
}

void graphTimeFrameNodeState::setPrevCandleStickBodyLocation(const QPoint& location) {
    prevCandleStickBodyLocation = location;
}

void graphTimeFrameNodeState::setCurCandleStickBodyLocation(const QPoint& location) {
    curCandleStickBodyLocation = location;
}

void graphTimeFrameNodeState::setPrevCandleStickWickStartPosition(const QPointF& position) {
    prevCandleStickWickStartPosition = position;
}

void graphTimeFrameNodeState::setCurCandleStickWickStartPosition(const QPointF &position)
{
    curCandleStickWickStartPosition = position;
}

void graphTimeFrameNodeState::setCurCandleStickWickEndPosition(const QPointF& position) {
    curCandleStickWickEndPosition = position;
}

void graphTimeFrameNodeState::setPrevCandleStickWickEndPositon(const QPointF &position)
{
    prevCandleStickWickEndPosition = position;
}

void graphTimeFrameNodeState::setPrevCandleStickBodyLength(int length) {
    prevCandleStickBodyLength = length;
}

void graphTimeFrameNodeState::setCurCandleStickBodyWidth(int width) {
    curCandleStickBodyWidth = width;
}

QPointF graphTimeFrameNodeState::getCurCandleStickBodyTopPosition() const {
    return curCandleStickBodyTopPosition;
}

QPointF graphTimeFrameNodeState::getCurCandleStickBodyBottomPosition() const {
    return curCandleStickBodyBottomPosition;
}

QPointF graphTimeFrameNodeState::getPrevCandleStickBodyTopPosition() const {
    return prevCandleStickBodyTopPosition;
}

QPointF graphTimeFrameNodeState::getPrevCandleStickBodyBottomPosition() const {
    return prevCandleStickBodyBottomPosition;
}

void graphTimeFrameNodeState::setCurCandleStickBodyTopPosition(const QPointF& position) {
    curCandleStickBodyTopPosition = position;
}

void graphTimeFrameNodeState::setCurCandleStickBodyBottomPosition(const QPointF& position) {
    curCandleStickBodyBottomPosition = position;
}

void graphTimeFrameNodeState::setPrevCandleStickBodyTopPosition(const QPointF& position) {
    prevCandleStickBodyTopPosition = position;
}

void graphTimeFrameNodeState::setPrevCandleStickBodyBottomPosition(const QPointF& position) {
    prevCandleStickBodyBottomPosition = position;
}

QVector<double> graphTimeFrameNodeState::getOHLCdata()
{
    QVector<double> ohlc_data = {open, high, low, close};
    return ohlc_data;
}

QDateTime graphTimeFrameNodeState::getCandleDateTime()
{
    return timeState;
}
bool graphTimeFrameNodeState::isBull(){
    if(getHigh() > getOpen()){
        return true;
    }else{
        return false;
    }
}
