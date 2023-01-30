#include "mapwidget.h"
#include "ui_mapwidget.h"

MapWidget::MapWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapWidget)
{
    ui->setupUi(this);
    flight = new Flight();
    view = new QQuickView();
    container = QWidget::createWindowContainer(view, this);
    container->setMinimumSize(680,420);
    container->setMaximumSize(680,420);
    qRegisterMetaType<Flight>();
    qmlRegisterType<Flight>("Flight", 1, 0, "Flight");
    view->rootContext()->setContextProperty("flight", flight);
    view->setSource(QUrl("qrc:/map.qml"));
    ui->horizontalLayout->addWidget(container);
}

MapWidget::~MapWidget()
{
    delete ui;
    delete view;
    delete container;
    delete flight;
}

Flight* MapWidget::getFlight(){
    return flight;
}
