#include "cdaoyougmui.h"
#include "ui_cdaoyougmui.h"
#include "cdaoyouitemtable.h"

CDaoYouGmUi::CDaoYouGmUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CDaoYouGmUi)
{
    ui->setupUi(this);

    QList<QString> strItemList;
    CDaoYouItemTable::getInstance().loadFile();
    CDaoYouItemTable::getInstance().getItemList(strItemList);

    m_pCompleter = new QCompleter(strItemList, this);
    m_pCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    m_pCompleter->setMaxVisibleItems(30);
    ui->lineItemName->setCompleter(m_pCompleter);
}

CDaoYouGmUi::~CDaoYouGmUi()
{
    delete ui;
}

void CDaoYouGmUi::on_lineItemName_returnPressed()
{
    QString strCmd = CDaoYouItemTable::getInstance().getGMAddItem(ui->lineItemName->text(), ui->lineNum->text().toInt());
    qApp->clipboard()->setText(strCmd);
    ui->textGm->setText(strCmd);
    ui->lineItemName->clear();
}


void CDaoYouGmUi::on_btnCopy_clicked()
{
    qApp->clipboard()->setText(ui->textGm->toPlainText());
}
