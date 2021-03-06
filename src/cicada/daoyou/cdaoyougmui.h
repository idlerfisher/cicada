#ifndef CDAOYOUGMUI_H
#define CDAOYOUGMUI_H

#include <QWidget>
#include <QtCore>
#include <QtGui>

namespace Ui {
class CDaoYouGmUi;
}

class CDaoYouGmUi : public QWidget
{
    Q_OBJECT
    
public:
    explicit CDaoYouGmUi(QWidget *parent = 0);
    ~CDaoYouGmUi();
    
private slots:
    void on_lineItemName_returnPressed();

    void on_btnCopy_clicked();

private:
    Ui::CDaoYouGmUi *ui;
    QCompleter* m_pCompleter;
};

#endif // CDAOYOUGMUI_H
