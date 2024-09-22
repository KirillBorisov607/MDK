#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_plus_minus,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_percent,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_divide,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_minis,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_multiply,SIGNAL(clicked()),this,SLOT(math_operations()));

    ui->pushButton_divide -> setCheckable(true);
    ui->pushButton_minis -> setCheckable(true);
    ui->pushButton_plus -> setCheckable(true);
    ui->pushButton_multiply -> setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//Ввод цыфор на экран
void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *) sender();

    double all_number;
    QString new_label;
    all_number = (ui->result_show->text() + button->text()).toDouble();
    new_label =QString::number(all_number, 'g' , 15);

    ui->result_show->setText(new_label);
}
//Ввод кнопка "."
void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->result_show->text().contains(".")))
    {
        ui->result_show->setText(ui->result_show->text() + ".");
    }
}
//Ввод кновки плюс минуса
void MainWindow::operations()
{
    QPushButton *button = (QPushButton *) sender();
    double all_number;
    QString new_label;
    if(button->text() == "+/-")
    {
        all_number = (ui->result_show->text()).toDouble();
        all_number = all_number * -1;
        new_label =QString::number(all_number, 'g' , 15);
        ui->result_show->setText(new_label);
    }// процент
    else if(button->text() == "%")
    {
        all_number = (ui->result_show->text()).toDouble();
        all_number = all_number * 0.1;
        new_label =QString::number(all_number, 'g' , 15);
        ui->result_show->setText(new_label);
    }
}
//условия для решения
void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *) sender();

    num_first = ui->result_show->text().toDouble();
    ui ->result_show->setText("");
    button -> setChecked(true);
}
//чистка экрана
void MainWindow::on_pushButton_AC_clicked()
{

}
//равно
void MainWindow::on_pushButton_equals_clicked()
{

    double labelNumber, num_second;
    QString new_label;

    num_second = ui ->result_show->text().toDouble();


    if(ui->pushButton_plus->isChecked())
    {
        labelNumber = num_first + num_second;
        new_label =QString::number(labelNumber, 'g' , 15);
        ui->result_show->setText(new_label);
        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_minis->isChecked())
    {
        labelNumber = num_first - num_second;
        new_label =QString::number(labelNumber, 'g' , 15);
        ui->result_show->setText(new_label);
        ui->pushButton_minis->setChecked(false);
    }
    else if(ui->pushButton_divide->isChecked())
    {
        if(num_second == 0)
        {
            ui->result_show->setText("0");
        }else
        {
            labelNumber = num_first / num_second;
            new_label =QString::number(labelNumber, 'g' , 15);
            ui->result_show->setText(new_label);
            ui->pushButton_multiply->setChecked(false);
        }
    }
    else if(ui->pushButton_multiply->isChecked())
    {

        labelNumber = num_first * num_second;
        new_label =QString::number(labelNumber, 'g' , 15);
        ui->result_show->setText(new_label);
        ui->pushButton_divide->setChecked(false);
    }
}

