#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QVector>
#include <QTimer>
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
    void on_pushButton_clicked();
    void timer_timeout();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena= new QGraphicsScene();
    QTimer *timer=new QTimer();
    int i,n,j,k;
    bool cambio,suma;
    QVector<int> x_ini,y_ini,x_fin,y_fin;
};

#endif // MAINWINDOW_H
