#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Polynomial.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    void on_pushButton_digit_numbers();

    void on_pushButton_derivative_clicked();

    void on_pushButton_X_clicked();

    void on_pushButton_neg_clicked();

    void on_pushButton_plus_clicked();

    void on_pushButton_mul_clicked();

    void on_pushButton_pow_clicked();

    void on_pushButton_AC_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
