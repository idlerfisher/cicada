#include "cexcelreader.h"

CExcelReader::CExcelReader()
{
    m_db = QSqlDatabase::addDatabase("QODBC");
}

CExcelReader::CExcelReader(const QString &strFile)
{
    m_db = QSqlDatabase::addDatabase("QODBC");
    m_strFile = strFile;
}

bool CExcelReader::open()
{
    if (m_strFile.isEmpty()) {
        qDebug() << "CExcelReader::open 文件名为空";
        return false;
    }

    if (m_db.isOpen()) {
        m_db.close();
    }

    QString strDbName = "Driver={Microsoft Excel Driver (*.xls)};Dbq=" + m_strFile + ";";
    m_db.setDatabaseName(strDbName);
    if (!m_db.open()) {
        qDebug() << tr("open %1 failed: %2").arg(m_strFile).arg(m_db.lastError().text());
//        qDebug() << "open " + m_strFile + " failed: " + m_db.lastError().text();
        return false;
    }

    qDebug() << tr("open %1 success").arg(m_strFile);

//    QSqlQuery query("select * from [" + QString("Sheet1") + "$]");
//    // Select range, place A1:B5 after $
//    while (query.next()) {
//        qDebug() << query.record().count();
//        QSqlRecord record = query.record();
//        int len = record.count();
//        for (int i = 0; i < len; i++) {
//            qDebug() << i << " -> " << record.fieldName(i);
//        }
//        QString column1= query.value(0).toString();
//        qDebug() << column1;
//        break;
//    }


    return true;
}

void CExcelReader::close()
{
    m_db.close();
}

void CExcelReader::foreachRow(const std::function<void(int, std::vector<QString>&)>& func)
{
    int count = 0;
    std::vector<QString> vec;

    QSqlQuery query("select * from [" + QString("Sheet1") + "$]");
    // Select range, place A1:B5 after $
    while (query.next()) {
        vec.clear();
        count = query.record().count();
        vec.resize(count);

        for (int i = 0; i < count; i++) {
            vec[i] = query.value(i).toString();
//            qDebug() << i << " -> " << record.fieldName(i);
        }
        if (func) {
            func(count, vec);
        }
    }
}
