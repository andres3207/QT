#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>       /* sin */
#include <QtDebug>

#define PI 3.14159265


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    ui->label->setText("resultado");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{


    double result;
    QString resultado;
    result = sin(value*PI/180);
    resultado.setNum(result);

    ui->label->setText(resultado);
/*
    qDebug() << value;
    qDebug() << result;
    qDebug() << resultado; */
}
