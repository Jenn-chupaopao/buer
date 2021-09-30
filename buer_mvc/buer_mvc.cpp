#include "buer_mvc.h"
#include "ui_buer_mvc.h"

#include "view/mainwindow_view.h"
#include <QPushButton>
#include <QDebug>
#include <QString>

buer_mvc::buer_mvc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::buer_mvc)
{
    ui->setupUi(this);
    mainLayout = new QVBoxLayout;
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    //启动QWidget页面需要制定父对象this指针，不然会出现闪屏bug
    QWidget *mainWidget = new QWidget(this);
    mainWidget->setLayout(mainLayout);
    mainWidget->setObjectName("mainWidget");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addWidget(mainWidget);
    this->setLayout(layout);

    initMenu();
    initStackWidget();
}

buer_mvc::~buer_mvc()
{
    delete ui;
}

void buer_mvc::initMenu()
{
    const QSize btnSize(120, 90);
    QPushButton *firstPageBtn = new QPushButton("\n\n\n\n\n第一页");
    firstPageBtn->setObjectName("firstPageBtn");
    firstPageBtn->setCheckable(true);
    firstPageBtn->setChecked(true);
    firstPageBtn->setFixedSize(btnSize);

    QPushButton *secondPageBtn = new QPushButton("\n\n\n\n\n第二页");
    secondPageBtn->setObjectName("secondPageBtn");
    secondPageBtn->setCheckable(true);
    secondPageBtn->setChecked(true);
    secondPageBtn->setFixedSize(btnSize);

    buttonGroup = new QButtonGroup();
    buttonGroup->setObjectName("buttonGroup");
    buttonGroup->addButton(firstPageBtn);
    buttonGroup->addButton(secondPageBtn);
    //只有一个按钮能被选中
    buttonGroup->setExclusive(true);
    connect(buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(buttonGroupSlot(int)));

    QHBoxLayout *menuLayout = new QHBoxLayout();
    menuLayout->setMargin(0);
    menuLayout->setSpacing(0);
    menuLayout->addWidget(firstPageBtn);
    menuLayout->addWidget(secondPageBtn);
    menuLayout->addStretch();

    mainLayout->addLayout(menuLayout);

}

void buer_mvc::initStackWidget()
{
    //启动菜单栏界面
    MainwindowView *firstPageView = new MainwindowView(this);
    stackLayout = new QStackedLayout;
    stackLayout->addWidget(firstPageView);
    stackLayout->setCurrentIndex(0);
    mainLayout->addLayout(stackLayout);
}

void buer_mvc::buttonGroupSlot(int)
{
    QPushButton *checkedButton = qobject_cast<QPushButton*>(buttonGroup->checkedButton());
    QString checkedButtonName = checkedButton->objectName();
    if (checkedButtonName.compare(QStringLiteral("firstPageBtn")) == 0) {
        qDebug() << "单击了第一页菜单按钮";
        stackLayout->setCurrentIndex(0);
    } else if (checkedButtonName.compare(QStringLiteral("secondPageBtn")) == 0) {
        qDebug() << "单击了第二页菜单按钮";
        stackLayout->setCurrentIndex(1);
    }
}

