#ifndef BUER_MVC_H
#define BUER_MVC_H

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedLayout>
#include <QButtonGroup>

QT_BEGIN_NAMESPACE
namespace Ui { class buer_mvc; }
QT_END_NAMESPACE

class buer_mvc : public QMainWindow
{
    Q_OBJECT

public:
    buer_mvc(QWidget *parent = nullptr);
    ~buer_mvc();

private:
    Ui::buer_mvc *ui;

private:
//    void setUi();
    void initMenu();
    void initStackWidget();

    QVBoxLayout *mainLayout;
    QButtonGroup *buttonGroup;
    QStackedLayout *stackLayout;

private slots:
    void buttonGroupSlot(int);
};
#endif // BUER_MVC_H
