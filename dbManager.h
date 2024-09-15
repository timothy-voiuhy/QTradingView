#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QString>
#include <QVector>
#include <QtSql/QSqlDatabase>
#include <QPair>
#include <QDateTime>


class dbManager
{
public:
    dbManager(const QString &dbName_);
    ~dbManager();

    bool openDB();
    void closeDB();

    double getMaxValue(const QString &columnName, const QString &tablename);
    double getMinValue(const QString &columnName, const QString &tablename);
    QVector<double> getOHLCData(int candleID, const QString &tablename);
    int getnNodes(const QString &tablename);
    QVector<QPair<QVector<double>, QDateTime>> loadData(int startCandleID, int endCandleID, const QString &tablename);

private:
    QString dbName;
    QSqlDatabase db;
};

#endif // DBMANAGER_H
