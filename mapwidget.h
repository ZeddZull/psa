#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include <QQuickView>

namespace Ui {
class MapWidget;
}

class MapWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MapWidget(QWidget *parent = nullptr);
    ~MapWidget();

private:
    Ui::MapWidget *ui;
    QQuickView* view;
    QWidget* container;
};

#endif // MAPWIDGET_H
