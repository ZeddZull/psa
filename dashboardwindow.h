#ifndef DASHBOARDWINDOW_H
#define DASHBOARDWINDOW_H

#include <QMainWindow>
#include "planeposition.h"
#include <QMap>
#include <QVector>
#include <QListWidgetItem>
#include <QListWidget>

namespace Ui {
class DashboardWindow;
}

class DashboardWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DashboardWindow(QWidget *parent = nullptr);
    ~DashboardWindow();

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::DashboardWindow *ui;
    QMap<QString,QVector<PlanePosition*>> planePaths;
};

#endif // DASHBOARDWINDOW_H
