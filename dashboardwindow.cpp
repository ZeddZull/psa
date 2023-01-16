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
    for (int i; i < planePositions.size(); i++){
        QString name = planePositions[i]->getPlaneName();
        if (!planePaths.contains(name)){
            planePaths[name] = QVector<PlanePosition*>();
        }
        planePaths[name].push_back(planePositions[i]);
    }
    QMapIterator<QString,QVector<PlanePosition*>> it(planePaths);
    while(it.hasNext()){
        it.next();
        ui->listWidget->addItem(it.key());
    }
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

