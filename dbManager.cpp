#include "dbManager.h"
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDateTime>
#include <QVariant>
#include <QDebug>
#include <QtSql/QSqlDatabase>

dbManager::dbManager(const QString &dbName_) : dbName(dbName_), db(QSqlDatabase::addDatabase("QMYSQL"))
{
    db.setDatabaseName(dbName);
    db.setHostName("localhost");
    db.setUserName("program");
    db.setPassword("program");
    openDB();
}

dbManager::~dbManager()
{
    closeDB();
}

bool dbManager::openDB()
{
    if (!db.open())
    {
        qDebug() << "Error: connection with database fail" << db.lastError().text();
        return false;
    }
    return true;
}

void dbManager::closeDB()
{
    db.close();
}

double dbManager::getMaxValue(const QString &columnName, const QString &tablename)
{
    if (!db.isOpen()) {
        qDebug() << "Database not open";
        return -1;
    }

    QSqlQuery query;
    query.prepare(QString("SELECT MAX(%1) FROM %2").arg(columnName).arg(tablename));

    if (!query.exec())
    {
        qDebug() << "getMaxValue error: " << query.lastError();
        return -1;
    }

    if (query.next())
    {
        return query.value(0).toDouble();
    }

    return -1;
}

double dbManager::getMinValue(const QString &columnName, const QString &tablename)
{
    if (!db.isOpen()) {
        qDebug() << "Database not open";
        return -1;
    }

    QSqlQuery query;
    query.prepare(QString("SELECT MIN(%1) FROM %2").arg(columnName).arg(tablename));

    if (!query.exec())
    {
        qDebug() << "getMinValue error: " << query.lastError();
        return -1;
    }

    if (query.next())
    {
        return query.value(0).toDouble();
    }

    return -1;
}

QVector<double> dbManager::getOHLCData(int candleID, const QString &tablename)
{
    QVector<double> ohlcData;

    if (!db.isOpen()) {
        qDebug() << "Database not open";
        return ohlcData;
    }

    QSqlQuery query;
    query.prepare(QString("SELECT Open, High, Low, Close FROM %1 WHERE id = :id").arg(tablename));
    query.bindValue(":id", candleID);

    if (!query.exec())
    {
        qDebug() << "getOHLCData error: " << query.lastError();
        return ohlcData;
    }

    if (query.next())
    {
        ohlcData.append(query.value(0).toDouble());
        ohlcData.append(query.value(1).toDouble());
        ohlcData.append(query.value(2).toDouble());
        ohlcData.append(query.value(3).toDouble());
    }

    return ohlcData;
}

int dbManager::getnNodes(const QString &tablename){
    if (!db.isOpen()) {
        qDebug() << "Database not open";
        return -1;
    }

    QSqlQuery query;
    query.prepare(QString("SELECT COUNT(*) FROM %1").arg(tablename));

    if (!query.exec())
    {
        qDebug() << "getnNodes error: " << query.lastError();
        return -1;
    }

    if (query.next())
    {
        int count = query.value(0).toInt();
        return count;
        // qDebug() << "Number of rows in" << tablename << ":" << count;
    }
    return -1;
}

QVector<QPair<QVector<double>, QDateTime>> dbManager::loadData(int startCandleID, int endCandleID, const QString &tablename)
{
    QVector<QPair<QVector<double>, QDateTime>> data;

    if (!db.isOpen()) {
        qDebug() << "Database not open";
        return data;
    }

    QSqlQuery query;
    query.prepare(QString("SELECT Open, High, Low, Close, Date FROM %1 WHERE id BETWEEN :startID AND :endID ORDER BY id DESC").arg(tablename));
    query.bindValue(":startID", startCandleID);
    query.bindValue(":endID", endCandleID);

    if (!query.exec())
    {
        qDebug() << "loadData error: " << query.lastError();
        return data;
    }

    while (query.next())
    {
        QVector<double> ohlcData;
        ohlcData.append(query.value(0).toDouble());
        ohlcData.append(query.value(1).toDouble());
        ohlcData.append(query.value(2).toDouble());
        ohlcData.append(query.value(3).toDouble());
        QDateTime dateTime = query.value(4).toDateTime();
        data.append(qMakePair(ohlcData, dateTime));
    }

    return data;
}
