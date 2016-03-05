#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label->setText("coordenada X:");
    ui->label_2->setText("coordenada Y:");
    ui->pushButton->setText("Marcar punto");

    ui->graphicsView->setScene(escena);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString tmp_x,tmp_y;
    tmp_x=ui->textEdit->toPlainText();
    tmp_y=ui->textEdit_2->toPlainText();
    escena->addLine(tmp_x.toInt(),tmp_y.toInt(),tmp_x.toInt(),tmp_y.toInt());
}
