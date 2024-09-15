#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QString>
#include <QVector>
#include <QtSql/QSqlDatabase>

class dbManager
{
public:
    QString tableName;
    dbManager(const QString &dbName_);
    ~dbManager();

    bool openDB();
    void closeDB();

    double getMaxValue(const QString &columnName);
    double getMinValue(const QString &columnName);
    QVector<double> getOHLCData(int candleID);
    QVector<QPair<QVector<double>, QDateTime>> loadData(int startCandleID, int endCandleID);

private:
    QString dbName;
    QSqlDatabase db;
};

#endif // DBMANAGER_H
