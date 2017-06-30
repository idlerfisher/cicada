#include "cdaoyouitemtable.h"

#define ITEM_TABLE_FILE "itemtable.txt"

CDaoYouItemTable::CDaoYouItemTable(QObject *parent) :
    QObject(parent)
{
}

CDaoYouItemTable &CDaoYouItemTable::getInstance()
{
    static CDaoYouItemTable obj;
    return obj;
}

void CDaoYouItemTable::loadFile()
{
    QFile file(ITEM_TABLE_FILE);
    if (!file.open(QFile::ReadOnly)) {
        qDebug() << "open failed";
        return;
    }

    QTextStream stream(&file);
    QString strLine;
    QStringList strList;
    while (!stream.atEnd()) {
        strLine = stream.readLine();
        strList = strLine.split("\t");
        if (!strList.empty() && strList.size() >= 2) {
            m_mapCache.insert(strList.at(1), strList.at(0).toInt());
//            qDebug() << strList;
        } else {
            qDebug() << "split error:" + strLine;
        }
    }

    file.close();
}

void CDaoYouItemTable::getItemList(QList<QString> &strList)
{
    strList = m_mapCache.keys();
}

QString CDaoYouItemTable::getGMAddItem(const QString &strItemName, int count)
{
    int nTid = getTidByItemName(strItemName);
    QString strCmd = tr("me.gm.addItem(%1,%2)").arg(nTid).arg(count);
    return strCmd;
}

int CDaoYouItemTable::getTidByItemName(const QString &strItemName)
{
    return m_mapCache.value(strItemName);
}

