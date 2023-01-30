#include "dashboardwindow.h"
#include "ui_dashboardwindow.h"


DashboardWindow::DashboardWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DashboardWindow)
{
    ui->setupUi(this);
    planePaths = QMap<QString,QVector<PlanePosition*>>();
    QVector<PlanePosition*> planePositions;
    PlanePosition::getPositions(&planePositions);
    for (int i = 0; i < planePositions.size(); i++){
        QString name = planePositions[i]->getPlaneName();
        if (!planePaths.contains(name)){
            planePaths[name] = QVector<PlanePosition*>();
        }
        planePaths[name].push_back(planePositions[i]);
    }
    QMapIterator<QString,QVector<PlanePosition*>> it(planePaths);
    QListWidgetItem *headerItem = new QListWidgetItem();
    headerItem->setText("Airplane :");
    headerItem->setTextAlignment(Qt::AlignCenter);
    headerItem->setFlags(Qt::ItemIsEnabled);
    ui->listWidget->addItem(headerItem);
    while(it.hasNext()){
        it.next();
        //ui->listWidget->setMinimumSize(90,580);
        ui->listWidget->addItem(it.key());
    }
    airportwindow = new AirportWindow();
    connect(this, &DashboardWindow::showAirportWindow, airportwindow, &AirportWindow::show);
    flightwindow = new FlightWindow();
    connect(this, &DashboardWindow::showFlightWindow, flightwindow, &FlightWindow::show);
    DashboardWindow::setWindowTitle("Dashboard");

    ui->ButtonPlay->setIcon(QIcon(":/data_images/image/play-button.png"));
    ui->ButtonPlayback->setIcon(QIcon(":/data_images/image/Playback.png"));
    ui->ButtonForward->setIcon(QIcon(":/data_images/image/right-arrow.png"));
    ui->ButtonPause->setIcon(QIcon(":/data_images/image/pause.png"));
    ui->ButtonStep->setIcon(QIcon(":/data_images/image/rewind.png"));


}

DashboardWindow::~DashboardWindow()
{
    delete ui;
}

void DashboardWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    emit ui->widget_2->getFlight()->triggerClearPath();
    QVector<PlanePosition*> positions = planePaths[item->text()];
    for (int i = 0; i < positions.size(); i++){
        emit ui->widget_2->getFlight()->triggerAddPath(QPointF(positions[i]->getLongitude(), positions[i]->getLatitude()));
    }
    // Ici on fait des ketru !
}

void DashboardWindow::on_ButtonAirportListDashboard_clicked()
{
    emit showAirportWindow();
}


void DashboardWindow::on_ButtonFlightListDashboard_clicked()
{
    emit showFlightWindow();
}


void DashboardWindow::on_ButtonDisconnect_clicked()
{
    DashboardWindow::close();
}

