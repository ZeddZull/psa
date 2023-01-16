#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include <QQuickView>
#include "flight.h"
#include <QQmlContext>

namespace Ui {
class MapWidget;
}

class MapWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MapWidget(QWidget *parent = nullptr);
    Flight* getFlight();
    ~MapWidget();

private:
    Ui::MapWidget *ui;
    QQuickView* view;
    QWidget* container;
    Flight* flight;
};

#endif // MAPWIDGET_H
