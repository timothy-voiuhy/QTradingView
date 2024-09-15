#include "candleStickDataStream.h"
#include <QtWebSockets/QWebSocket>
#include <QUrlQuery>
#include <QDebug>

CandleDataStreamer::CandleDataStreamer() {
    // Constructor implementation
    connect(&webSocket, &QWebSocket::connected, this, &CandleDataStreamer::onConnected);
    connect(&webSocket, &QWebSocket::textMessageReceived, this, &CandleDataStreamer::onTextMessageReceived);
    connect(&webSocket, &QWebSocket::pong, this, &CandleDataStreamer::onPongReceived);

    // Initialize and configure the ping timer
    connect(&pingTimer, &QTimer::timeout, this, &CandleDataStreamer::onPingTimeout);
    pingTimer.setInterval(30000); // Ping every 30 seconds
}

CandleDataStreamer::~CandleDataStreamer() {
    // Destructor implementation
    pingTimer.stop();
    webSocket.close();
}

void CandleDataStreamer::connectToServer(const QUrl &url, const QString &apiKey) {
    // Connect to the WebSocket server with API key
    QUrl urlWithKey = url;
    QUrlQuery query;
    query.addQueryItem("api_key", apiKey);
    urlWithKey.setQuery(query);
    webSocket.open(urlWithKey);
}

void CandleDataStreamer::startDataStream() {
    // Start the data stream
    if (webSocket.isValid()) {
        webSocket.sendTextMessage(QStringLiteral("Start Data Stream"));
    }
}

void CandleDataStreamer::onConnected() {
    // Handle connection established
    qDebug() << "WebSocket connected";
    webSocket.sendTextMessage(apiKey); // Send API key
    startDataStream();
    pingTimer.start(); // Start the ping timer
}

void CandleDataStreamer::onTextMessageReceived(const QString &message) {
    // Handle incoming data
    qDebug() << "Received message:" << message;
    emit dataUpdated(message.toUtf8());
}

void CandleDataStreamer::onPingTimeout() {
    // Send a ping message
    if (webSocket.isValid()) {
        webSocket.ping();
    } else {
        // Attempt to reconnect if the WebSocket is not valid
        qDebug() << "WebSocket is not valid, attempting to reconnect...";
        webSocket.open(webSocket.requestUrl());
    }
}

void CandleDataStreamer::onPongReceived(quint64 elapsedTime, const QByteArray &payload) {
    // Handle pong response
    qDebug() << "Pong received, elapsed time:" << elapsedTime << "ms, payload:" << payload;
}
