#include "mainwindow_model.h"
#include "controller/mainwindow_controller.h"
#include "singleton.h"

#include <QDebug>

MainwindowModel::MainwindowModel(QObject *parent) : QObject(parent)
{

}

void MainwindowModel::countSlot()
{
    int a = 2;
    int b = 3;
    emit Singleton<MainwindowController>::getInstance().finishedCountSignal();
    qDebug() << QString("页面1的逻辑功能计算结果为==%1").arg(a + b);
}
