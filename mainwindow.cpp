#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myqswitch.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MyQSwitch *qSwitch = new MyQSwitch(this);
    // 设置初始状态
    qSwitch->setToggleCdtion(false);

    // 设置选中装态
    qSwitch->setCheckedBgColor(QColor(255, 255, 255));
    qSwitch->setCheckedWrapBgColor(QColor(95, 184, 120));

    // 设置未选中装态
    qSwitch->setUnCheckedBgColor(QColor(255, 255, 255));
    qSwitch->setUnCheckedWrapBgColor(QColor(95, 184, 120));

    // 设置禁用状态
    qSwitch->setDisableSwitch(false);
    // 设置
    qSwitch->setGeometry(QRect(20,20,40,20));
    // 设置动画时间
    qSwitch->setTimeNum(10);

    // 设置点击执行的方法
    connect(qSwitch,SIGNAL(toggled(bool)),this,SLOT(getSwitchCheckValue(bool)));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getSwitchCheckValue(bool checkValue)
{
    qDebug()<< "switchValue:" <<checkValue;
}
