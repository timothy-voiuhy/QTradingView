#include "dbManager.h"
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QDateTime>
#include <QVariant>
#include <QDebug>

dbManager::dbManager(const QString &dbName_) : dbName(dbName_), db(QSqlDatabase::addDatabase("MYSQL"))
{
    db.setDatabaseName(dbName);
}

dbManager::~dbManager()
{
    closeDB();
}

bool dbManager::openDB()
{
    if (!db.open())
    {
        qDebug() << "Error: connection with database fail";
        return false;
    }
    else
    {
        qDebug() << "Database: connection ok";
        return true;
    }
}

void dbManager::closeDB()
{
    db.close();
}

double dbManager::getMaxValue(const QString &columnName)
{
    QSqlQuery query;
    query.prepare(QString("SELECT MAX(%1) FROM %2").arg(columnName).arg(tableName));

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

double dbManager::getMinValue(const QString &columnName)
{
    QSqlQuery query;
    query.prepare(QString("SELECT MIN(%1) FROM %2").arg(columnName).arg(tableName));

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

QVector<double> dbManager::getOHLCData(int candleID)
{
    QVector<double> ohlcData;
    QSqlQuery query;
    query.prepare(QString("SELECT open, high, low, close FROM %1 WHERE id = :id").arg(tableName));
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

QVector<QPair<QVector<double>, QDateTime>> dbManager::loadData(int startCandleID, int endCandleID)
{
    QVector<QPair<QVector<double>, QDateTime>> data;
    QSqlQuery query;
    query.prepare(QString("SELECT open, high, low, close, datetime FROM %1 WHERE id BETWEEN :startID AND :endID").arg(tableName));
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
