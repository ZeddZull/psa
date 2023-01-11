#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ramloader.h"
#include "cpuloader.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CPULoader* cpuloader = new CPULoader();
    qDebug() << cpuloader->GetCPULoad()*100;
    RAMLoader* ramloader = new RAMLoader();
    qDebug() << ramloader->getPourcentageUse();
}

MainWindow::~MainWindow()
{
    delete ui;
}

