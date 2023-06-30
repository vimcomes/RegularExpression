#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    label = new QLabel(this);
    label->resize(this->width()-10,30);
    lineEdit = new QLineEdit(this);
    lineEdit->resize(this->width()-10,30);
    lineEdit->move(5,5);
    label->move(5,100);
    connect(lineEdit, &QLineEdit::textEdited,[this](QString currentText){
        //***********
        QRegularExpression exp("^(8|\\+7)\\d{10}$");
        //***********
        if(exp.match(currentText).hasMatch()) {
            setOkLabel();
        } else {
            setNotOkLabel();
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setOkLabel()
{
    label->setText("Right Number");
    setStyleSheet("QLabel {color : green;}");
}

void MainWindow::setNotOkLabel()
{
    label->setText("Wrong Mobile Phone Number format");
    setStyleSheet("QLabel {color : red;}");
}

