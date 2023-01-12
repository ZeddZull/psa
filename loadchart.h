#ifndef LOADCHART_H
#define LOADCHART_H

#include <QWidget>
#include <QtCharts>
#include "cpuloader.h"
#include "ramloader.h"

namespace Ui {
class LoadChart;
}

class LoadChart : public QWidget
{
    Q_OBJECT

public:
    explicit LoadChart(QWidget *parent = nullptr);
    ~LoadChart();
 public slots:
    void updateChart();

private:
    Ui::LoadChart *ui;
    QLineSeries* cpuload;
    QLineSeries* ramload;
    QChart* chart;
    QChartView* chartview;
    CPULoader* cpuloader;
    RAMLoader* ramloader;
    QTimer* updateTimer;
    int cpt;
};

#endif // LOADCHART_H
