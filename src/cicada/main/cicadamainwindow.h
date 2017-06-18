#ifndef CICADAMAINWINDOW_H
#define CICADAMAINWINDOW_H

#include <QtCore>
#include <QtGui>
#include <QMainWindow>

namespace Ui {
class CicadaMainWindow;
}

class CicadaMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit CicadaMainWindow(QWidget *parent = 0);
    ~CicadaMainWindow();

private slots:
    void slotQuit();
    void slotTest();
    
private:
    Ui::CicadaMainWindow *ui;
};

#endif // CICADAMAINWINDOW_H
