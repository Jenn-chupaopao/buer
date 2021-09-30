#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QThread>
#include "model/mainwindow_model.h"
#include "singleton.h"

class MainwindowController : public QObject
{
    SINGLETON(MainwindowController)
    Q_OBJECT

signals:
    void startedCountSignal();
    void finishedCountSignal();
    void showFinishedCountUiSignal();

private:
    void initController();
    QThread *threadCount;
    MainwindowController *firstPageModel;

private slots:
    void startCountSlot();
    void quitCountThreadSlot();
    void finishedCountThreadSlot();


};

#endif // MAINWINDOW_H
