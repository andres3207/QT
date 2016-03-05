#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label->setText("coordenada X:");
    ui->label_2->setText("coordenada Y:");
    ui->pushButton->setText("Animación");
    escena->setSceneRect(0,0,1280,420);
    ui->graphicsView->setScene(escena);

    x_ini.insert(0,100);
    y_ini.insert(0,100);
    x_fin.insert(0,200);
    y_fin.insert(0,100);

    x_ini.insert(1,150);
    y_ini.insert(1,100);
    x_fin.insert(1,150);
    y_fin.insert(1,200);

    x_ini.insert(2,150);
    y_ini.insert(2,200);
    x_fin.insert(2,100);
    y_fin.insert(2,200);

    x_ini.insert(3,100);
    x_fin.insert(3,100);
    y_ini.insert(3,200);
    y_fin.insert(3,180);

    x_ini.insert(4,210);
    x_fin.insert(4,210);
    y_ini.insert(4,100);
    y_fin.insert(4,200);

    x_ini.insert(5,210);
    x_fin.insert(5,310);
    y_ini.insert(5,200);
    y_fin.insert(5,200);

    x_ini.insert(6,310);
    x_fin.insert(6,310);
    y_ini.insert(6,200);
    y_fin.insert(6,100);

    x_ini.insert(7,320);
    x_fin.insert(7,320);
    y_ini.insert(7,200);
    y_fin.insert(7,100);

    x_ini.append(320);
    x_fin.append(420);
    y_ini.append(100);
    y_fin.append(100);

    x_ini.append(420);
    x_fin.append(420);
    y_ini.append(100);
    y_fin.append(200);

    x_ini.append(320);
    x_fin.append(420);
    y_ini.append(150);
    y_fin.append(150);

    x_ini.append(430);
    x_fin.append(430);
    y_ini.append(200);
    y_fin.append(100);

    x_ini.append(430);
    x_fin.append(480);
    y_ini.append(100);
    y_fin.append(100);

    x_ini.append(480);
    x_fin.append(480);
    y_ini.append(100);
    y_fin.append(200);

    x_ini.append(480);
    x_fin.append(530);
    y_ini.append(200);
    y_fin.append(200);

    x_ini.append(530);
    x_fin.append(530);
    y_ini.append(200);
    y_fin.append(100);

    x_ini.append(630);
    x_fin.append(630);
    y_ini.append(200);
    y_fin.append(100);

    x_ini.append(630);
    x_fin.append(730);
    y_ini.append(100);
    y_fin.append(100);

    x_ini.append(730);
    x_fin.append(730);
    y_ini.append(100);
    y_fin.append(150);

    x_ini.append(730);
    x_fin.append(630);
    y_ini.append(150);
    y_fin.append(150);

    x_ini.append(740);
    x_fin.append(740);
    y_ini.append(100);
    y_fin.append(200);

    x_ini.append(740);
    x_fin.append(840);
    y_ini.append(200);
    y_fin.append(200);

    x_ini.append(840);
    x_fin.append(840);
    y_ini.append(200);
    y_fin.append(100);

    x_ini.append(900);
    x_fin.append(900);
    y_ini.append(100);
    y_fin.append(200);

    x_ini.append(850);
    x_fin.append(950);
    y_ini.append(100);
    y_fin.append(100);

    x_ini.append(960);
    x_fin.append(960);
    y_ini.append(200);
    y_fin.append(100);

    x_ini.append(960);
    x_fin.append(1060);
    y_ini.append(100);
    y_fin.append(100);

    x_ini.append(1060);
    x_fin.append(1060);
    y_ini.append(100);
    y_fin.append(200);

    x_ini.append(1060);
    x_fin.append(960);
    y_ini.append(200);
    y_fin.append(200);

    n=x_ini.size();
    i=0;
    j=0;
    k=0;
    cambio=true;
    timer->setInterval(1);
    //timer->timeout(timer_timeout);
    //connect(timer,SIGNAL(timeout()),this,SLOT(timer_timeout));
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(timer_timeout()));
    //timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    /*QString tmp_x,tmp_y;
    tmp_x=ui->textEdit->toPlainText();
    tmp_y=ui->textEdit_2->toPlainText();
    escena->addLine(tmp_x.toInt(),tmp_y.toInt(),tmp_x.toInt(),tmp_y.toInt());*/
    escena->clear();
    i=0;
    cambio=true;
    timer->start();
}

void MainWindow::timer_timeout(){
    if(cambio){
        if(x_ini.at(i)==x_fin.at(i)){
            j=y_ini.at(i);
            k=y_fin.at(i);
            if(y_ini.at(i)>y_fin.at(i)){
                suma=false;
            }else{
               suma=true;
            }
        }else if(y_ini.at(i)==y_fin.at(i)){
            j=x_ini.at(i);
            k=x_fin.at(i);
            if(x_ini.at(i)>x_fin.at(i)){
                suma=false;
            }else{
                suma=true;
            }
        }
        cambio=false;
    }else{
         if(x_ini.at(i)==x_fin.at(i)){
             if(suma){
                escena->addLine(x_ini.at(i),j,x_fin.at(i),j+1);
             }else{
                 escena->addLine(x_ini.at(i),j,x_fin.at(i),j-1);
             }
         }else{
             if(suma){
                escena->addLine(j,y_ini.at(i),j+1,y_fin.at(i));
             }else{
                 escena->addLine(j,y_ini.at(i),j-1,y_fin.at(i));
             }
         }
         if(suma){
            j++;
         }else{
             j--;
         }
         if((j>=k && suma) || (j<=k && !suma)){
             cambio=true;
             i++;
             if (i>=n){
                 timer->stop();
             }
         }
        }


    //escena->addLine(x_ini.at(i),y_ini.at(i),x_fin.at(i),y_fin.at(i));


}
