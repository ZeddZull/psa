#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    number_of_tries = 0;
    dashboardWindow = new DashboardWindow();
    connect(this, &MainWindow::showSecondWindow, dashboardWindow, &DashboardWindow::show);
    ui->lineEditPassword->setEchoMode(QLineEdit::Password); // masque le contenu du LineEdit
    ui->lineEditUsername->setStyleSheet("border: 1px solid black");
    ui->lineEditPassword->setStyleSheet("border: 1px solid black");
    ui->ButtonLogin->setStyleSheet("border: 1px solid black");
    ui->ButtonLogin->setStyleSheet("background-color: blue light;");
    ui->ButtonLogin->setIcon(QIcon(":/data_images/image/in.png"));
    /*player.setVideoOutput(videoWidget);
    videoWidget->show();
    player.setSource(QUrl("qrc:/data_images/image/sky.mp4"));
    player.play();*/
    //ui->horizontalLayout_video->addWidget(videoWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ButtonLogin_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();


    if (username == ""){
        QMessageBox::information(this,"Username","Username is Empty !");
        return;
        }
    if (password == ""){
        QMessageBox::information(this,"Password","Password is Empty !");
        return;
        }

    user = new User(username,password);
    bool authentification = authorised_User.isAuthorise(user);

    if(number_of_tries <5)
    {
        if (authentification){
            //QMessageBox::information(this,"Password","Username and Password is Correct !");
            number_of_tries = 0;
            emit showSecondWindow();
            }

        if (!authentification){
            ++number_of_tries;
            QMessageBox::information(this,"Password","Username and/or Password is not Correct !");
            return;
        }
    }
    else
        QApplication::quit();

}
