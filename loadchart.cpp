#include "loadchart.h"
#include "ui_loadchart.h"

LoadChart::LoadChart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoadChart)
{
    ui->setupUi(this);
    cpuload = new QLineSeries();
    cpuloader = new CPULoader();
    ramload = new QLineSeries();
    ramloader = new RAMLoader();
    cpt = 0;
    cpuload->append(0,cpuloader->getCPULoad());
    ramload->append(0,ramloader->getRAMLoad());
    chart = new QChart();
    cpuload->setName("CPU");
    ramload->setName("RAM");
    chart->addSeries(cpuload);
    chart->addSeries(ramload);

    QValueAxis* axisY = new QValueAxis;
    axisY->setTitleText("RAM / CPU % use");
    axisY->setMax(100);
    axisY->setMin(0);
    chart->addAxis(axisY, Qt::AlignLeft);
    ramload->attachAxis(axisY);
    cpuload->attachAxis(axisY);
    QValueAxis* axisX = new QValueAxis;
    axisX->setTitleText("time (s)");
    axisX->setMax(100);
    axisX->setMin(0);
    chart->addAxis(axisX, Qt::AlignBottom);
    ramload->attachAxis(axisX);
    cpuload->attachAxis(axisX);

    chart->setTitle("CPU/RAM usage");

    chartview = new QChartView(chart);

    ui->verticalLayout->addWidget(chartview);

    updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this, &LoadChart::updateChart);
    updateTimer->start(1000);
}

LoadChart::~LoadChart()
{
    delete ui;
}

void LoadChart::updateChart()
{
    cpt++;
    cpuload->append(cpt,cpuloader->getCPULoad());
    ramload->append(cpt,ramloader->getRAMLoad());

    if (cpt == 101){
        cpt--;
        cpuload->remove(0);
        ramload->remove(0);
        for (int i=0; i < 100; i++){
            cpuload->replace(i,QPointF(i,cpuload->at(i).y()));
            ramload->replace(i,QPointF(i,ramload->at(i).y()));
        }
    }

}
