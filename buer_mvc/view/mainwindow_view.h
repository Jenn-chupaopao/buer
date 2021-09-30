#ifndef MAINWINDOW_VIEW_H
#define MAINWINDOW_VIEW_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>

class MainwindowView : public QWidget
{
    Q_OBJECT
public:
    explicit MainwindowView(QWidget *parent = nullptr);

private:
    void setUi();
    QVBoxLayout *mainLayout;

private slots:
    void showUiSlot();
    void showFinishedCountResultUISlot();
};

#endif // MAINWINDOW_VIEW_H
