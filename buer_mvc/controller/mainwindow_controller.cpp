#include "mainwindow_controller.h"
#include <QDebug>

MainwindowController::MainwindowController()
{
    initController();
}

MainwindowController::~MainwindowController()
{

}

void MainwindowController::initController()
{
    connect(this, SIGNAL(startedCountSignal()), this, SLOT(startCountSlot()));
}

void MainwindowController::startCountSlot()
{
    threadCount = new QThread;
    firstPageModel = new MainwindowController();
    firstPageModel->moveToThread(threadCount);
    connect(threadCount, SIGNAL(started()), firstPageModel, SLOT(countSlot()));
    connect(threadCount, SIGNAL(finished()), threadCount, SLOT(deleteLater()));
    //保证线程先结束，再去更新UI，可以防止UI卡死
    connect(threadCount, SIGNAL(finished()), this, SLOT(finishedCountThreadSlot()));
    connect(this, SIGNAL(finishedCountSignal()), this, SLOT(quitCountThreadSlot()));
    threadCount->start();
}

void MainwindowController::quitCountThreadSlot()
{
    threadCount->quit();
    threadCount->wait();
}

void MainwindowController::finishedCountThreadSlot()
{
    qDebug() << "完成计算逻辑功能！！！";
    emit showFinishedCountUiSignal();
}
