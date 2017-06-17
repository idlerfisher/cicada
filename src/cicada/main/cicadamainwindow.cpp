#include "cicadamainwindow.h"
#include "ui_cicadamainwindow.h"
#include "ccurl.h"

CicadaMainWindow::CicadaMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CicadaMainWindow)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/images/logo.png"));

    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(slotQuit()));
}

CicadaMainWindow::~CicadaMainWindow()
{
    delete ui;
}

void CicadaMainWindow::slotQuit()
{
    qApp->quit();
}

