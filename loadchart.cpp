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
    cpuload->setName("CPU");
    ramload->setName("RAM");

    chart = new QChart();
    chart->addSeries(cpuload);
    chart->addSeries(ramload);

    axisY = new QValueAxis;
    axisY->setTitleText("RAM / CPU % use");
    axisY->setMax(100);
    axisY->setMin(0);
    chart->addAxis(axisY, Qt::AlignLeft);
    ramload->attachAxis(axisY);
    cpuload->attachAxis(axisY);

    axisX = new QValueAxis;
    axisX->setTitleText("time (s)");
    axisX->setMax(100);
    axisX->setMin(0);
    chart->addAxis(axisX, Qt::AlignBottom);
    ramload->attachAxis(axisX);
    cpuload->attachAxis(axisX);

    chart->setTitle("CPU/RAM usage");

    chartview = new QChartView(chart);

    chartview->setMinimumSize(650,250);
    ui->verticalLayout->addWidget(chartview);

    updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this, &LoadChart::updateChart);
    updateTimer->start(1000);
}

LoadChart::~LoadChart()
{
    delete ui;
    delete chart;
    delete chartview;
    delete cpuloader;
    delete cpuload;
    delete ramloader;
    delete ramload;
    delete updateTimer;
    delete axisX;
    delete axisY;
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
