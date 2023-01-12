#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    number_of_tries = 0;
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
            QMessageBox::information(this,"Password","Username and Password is Correct !");
            return;
            }

        if (!authentification){
            ++number_of_tries;
            QMessageBox::information(this,"Password","Username and/or Password is not Correct ! Number of try : ");
            return;
        }
    }
    else
        QApplication::quit();

}
