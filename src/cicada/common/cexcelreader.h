#ifndef CEXCELREADER_H
#define CEXCELREADER_H

#include <QtSql>
#include <QtCore>
#include <iostream>
#include <string>
#include <functional>

class CExcelReader : QObject
{
    Q_OBJECT
public:
    CExcelReader();
    CExcelReader(const QString& strFile);
    bool open();
    void close();
    void foreachRow(const std::function<void(int, std::vector<QString>&)>& func);

private:
    QString m_strFile;
    QSqlDatabase m_db;
};

#endif // CEXCELREADER_H
