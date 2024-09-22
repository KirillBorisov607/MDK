#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDoubleValidator"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit1->setValidator(new QDoubleValidator(this));
    ui->lineEdit2->setValidator(new QDoubleValidator(this));
}


MainWindow::~MainWindow()
{
    delete ui;
}

//Обработка кнопки ESC для отчистик блоков с числами
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key()==Qt::Key_Escape)
    {
        ui->lineEdit1->clear();
        ui->lineEdit2->clear();
        ui->resultLabel->clear();
        qDebug()<<"1";
    }
}

//Сложения
void MainWindow::on_plusButton_clicked()
{

    double num1 = ui->lineEdit1->text().toDouble();
    double num2 = ui->lineEdit2->text().toDouble();
    double result = num1 + num2;
    ui->resultLabel->setText(QString::number(result));
}
//Вычитания
void MainWindow::on_minusButton_clicked()
{
    double num1 = ui->lineEdit1->text().toDouble();
    double num2 = ui->lineEdit2->text().toDouble();
    double result = num1 - num2;

    ui->resultLabel->setText(QString::number(result));
}
//Умножения
void MainWindow::on_divideButton_clicked()
{
    double num1 = ui->lineEdit1->text().toDouble();
    double num2 = ui->lineEdit2->text().toDouble();
    double result = num1 * num2;

    ui->resultLabel->setText(QString::number(result));
}
//Деления
void MainWindow::on_multiplyButton_clicked()
{
    double num1 = ui->lineEdit1->text().toDouble();
    double num2 = ui->lineEdit2->text().toDouble();

    if(num1 == 0 ||num2 == 0)
    {
        ui->resultLabel->setText("ERR0R 0!");
    }
    else
    {
        double result = num1 / num2;
        ui->resultLabel->setText(QString::number(result));
    }

}
