#include "cicadamainwindow.h"
#include "ui_cicadamainwindow.h"
#include "ccurl.h"
//#include "cexcelreader.h"
#include "cdaoyouexcelreader.h"

CicadaMainWindow::CicadaMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CicadaMainWindow)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/images/logo.png"));

    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(slotQuit()));
    connect(ui->btnTest, SIGNAL(clicked()), this, SLOT(slotTest()));
}

CicadaMainWindow::~CicadaMainWindow()
{
    delete ui;
}

void CicadaMainWindow::slotQuit()
{
    qApp->quit();
}

void CicadaMainWindow::slotTest()
{
//    CExcelReader reader("C:/test.xls");
//    if (!reader.open()) {
//        return;
//    }
//    reader.foreachRow([](int count, std::vector<QString>& vec) {
//        qDebug() << count;
//        for (int i = 0; i < count; i++) {
//            qDebug() << i << " -> " + vec[i];
//        }
//    });

//    CExcelReader reader(tr("E:/p22/int/table/物品/物品表.xls"));
//    CExcelReader reader("c:/test.xls");
//    qDebug() << reader.getExcelSheets();

    CDaoyouExcelReader reader("E:/p22/int/table/物品/物品表.xls");
    reader.load();
}

