#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(on_pushButton_digit_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(on_pushButton_digit_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(on_pushButton_digit_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(on_pushButton_digit_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(on_pushButton_digit_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(on_pushButton_digit_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(on_pushButton_digit_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(on_pushButton_digit_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(on_pushButton_digit_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(on_pushButton_digit_numbers()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_derivative_clicked()
{
    std::string str = ui->result_show->text().toStdString();
    if(!str.empty())
        ui->result_show->setText(QString::fromStdString(derivative(str)));
}



void MainWindow::on_pushButton_digit_numbers()
{
    QPushButton * button = (QPushButton *)sender();

    /*double all_numbers;
    QString new_label;

    all_numbers = (ui->result_show->text() + button->text()).toDouble();
    new_label = QString::number(all_numbers, 'g', 15);

    ui->result_show->setText(new_label);*/
    if(!ui->result_show->text().endsWith("x"))
    ui->result_show->setText(ui->result_show->text() + button->text());
}

void MainWindow::on_pushButton_X_clicked()
{
    if(!ui->result_show->text().endsWith("x") &&
            !ui->result_show->text().endsWith("^"))
        ui->result_show->setText(ui->result_show->text() + "x");
}

void MainWindow::on_pushButton_neg_clicked()
{
    if(!ui->result_show->text().endsWith("-") &&
           !ui->result_show->text().endsWith("+") &&
           !ui->result_show->text().endsWith("*") &&
            !ui->result_show->text().endsWith("^"))
        ui->result_show->setText(ui->result_show->text() + "-");
}

void MainWindow::on_pushButton_plus_clicked()
{
    if(!ui->result_show->text().endsWith("-") &&
           !ui->result_show->text().endsWith("+") &&
           !ui->result_show->text().endsWith("*") &&
            !ui->result_show->text().endsWith("^"))
        ui->result_show->setText(ui->result_show->text() + "+");
}


void MainWindow::on_pushButton_mul_clicked()
{
    if(!ui->result_show->text().endsWith("-") &&
           !ui->result_show->text().endsWith("+") &&
           !ui->result_show->text().endsWith("*") &&
            !ui->result_show->text().endsWith("^"))
        ui->result_show->setText(ui->result_show->text() + "*");
}

void MainWindow::on_pushButton_pow_clicked()
{
    if(ui->result_show->text().endsWith("x"))
        ui->result_show->setText(ui->result_show->text() + "^");
}

void MainWindow::on_pushButton_AC_clicked()
{
    ui->result_show->setText("");
}
