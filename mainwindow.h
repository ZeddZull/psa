#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QMessageBox"
#include <QThread>
#include "user.h"
#include "authoriseduser.h"
#include "dashboardwindow.h"
#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <QQuickView>
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void showSecondWindow();

private slots:
    void on_ButtonLogin_clicked();

private:
    Ui::MainWindow *ui;
    User *user;
    AuthorisedUser authorised_User = AuthorisedUser();
    int number_of_tries;
    DashboardWindow *dashboardWindow;

    /*QQuickView* view;
    QWidget* container;
    QMediaPlayer player;
    QVideoWidget *videoWidget = new QVideoWidget();*/
};

#endif // MAINWINDOW_H
