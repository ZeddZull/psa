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
    container->setMinimumSize(512,512);
    container->setMaximumSize(512,512);
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
