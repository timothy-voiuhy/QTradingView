#ifndef CANDLEDATASTREAM_H
#define CANDLEDATASTREAM_H

#include <QObject>
#include <QtWebSockets/QWebSocket>
#include <QTimer> // Include for timer functionality

class CandleDataStreamer : public QObject {

    Q_OBJECT // Macro to enable signals and slots

public:
    CandleDataStreamer();
    ~CandleDataStreamer();

    void connectToServer(const QUrl &url, const QString &apiKey); // Function to connect to server
    void startDataStream(); // Function to start data stream

private slots:
    void onConnected(); // Slot to handle connection established
    void onTextMessageReceived(const QString &message); // Slot to handle incoming data
    void onPingTimeout(); // Slot to handle ping timeout
    void onPongReceived(quint64 elapsedTime, const QByteArray &payload); // Slot to handle pong response

signals:
    void dataUpdated(const QByteArray &data); // Signal to notify data update

private:
    QWebSocket webSocket; // WebSocket for the connection
    QString apiKey;
    QTimer pingTimer; // Timer for sending ping messages
};

#endif