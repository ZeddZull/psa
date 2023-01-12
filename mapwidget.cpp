#include "mapwidget.h"
#include "ui_mapwidget.h"

MapWidget::MapWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapWidget)
{
    ui->setupUi(this);
    view = new QQuickView();
    container = QWidget::createWindowContainer(view, this);
    container->setMinimumSize(512,512);
    container->setMaximumSize(512,512);
    view->setSource(QUrl("qrc:/map.qml"));
    ui->horizontalLayout->addWidget(container);
}

MapWidget::~MapWidget()
{
    delete ui;
}
