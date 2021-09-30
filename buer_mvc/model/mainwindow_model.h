#ifndef MAINWINDOW_MODEL_H
#define MAINWINDOW_MODEL_H


#include <QObject>

class MainwindowModel : public QObject
{
    Q_OBJECT
public:
    explicit MainwindowModel(QObject *parent = nullptr);

signals:

public slots:
    void countSlot();
};

#endif // MAINWINDOW_MODEL_H
