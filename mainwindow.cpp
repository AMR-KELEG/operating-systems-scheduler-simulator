#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <utility>
#include <queue>
#include <QLabel>
#include <QLineEdit>
#include <QWidget>
#include <QPushButton>





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    process_grid = new QGridLayout();
    viewport = new QWidget;
    viewport->setLayout(process_grid);
    ui->process_area->setWidget(viewport);

    num_of_process = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    int arrivalTime,burstTime,priority;
    quanta = ui->pQuanta->text().toInt();


    for(int i=0;i<num_of_process;i++)
    {
        arrivalTime = (ui->process_area->findChild<QLineEdit*>(QString("pArrival%1").arg(i))->text()).toInt();
        burstTime =  (ui->process_area->findChild<QLineEdit*>(QString("pBurst%1").arg(i))->text()).toInt();
        priority =  (ui->process_area->findChild<QLineEdit*>(QString("pPriority%1").arg(i))->text()).toInt();
        processVector.push_back(Process(i+1,arrivalTime,burstTime,priority));
    }

    this->hide();
    simwin = new SimulationWindow(processVector ,quanta, algorithm );
    simwin->show();
}

void MainWindow::on_ps_clicked()
{
    for(int i=0; i<num_of_process; i++)
    {
       ui->process_area->findChild<QLineEdit*>(QString("pPriority%1").arg(i))->setDisabled(0);
    }

    algorithm = "ps";

}

void MainWindow::on_sjf_clicked()
{
    for(int i=0; i<num_of_process; i++)
    {
       ui->process_area->findChild<QLineEdit*>(QString("pPriority%1").arg(i))->setDisabled(1);
    }

    algorithm = "sjf";
}

void MainWindow::on_fcfs_clicked()
{
    for(int i=0; i<num_of_process; i++)
    {
       ui->process_area->findChild<QLineEdit*>(QString("pPriority%1").arg(i))->setDisabled(1);
    }

    algorithm = "fcfs";

}

void MainWindow::on_rr_clicked()
{
    for(int i=0; i<num_of_process; i++)
    {
       ui->process_area->findChild<QLineEdit*>(QString("pPriority%1").arg(i))->setDisabled(1);
    }

    algorithm = "rr";

}

void MainWindow::on_add_process_clicked()
{
    QLineEdit *arriv = new QLineEdit();
    QLineEdit *burst = new QLineEdit();
    QLineEdit *prio  = new QLineEdit();
    QPushButton *btn = new QPushButton("x");

    arriv->setObjectName(QString("pArrival%1").arg(num_of_process));
    burst->setObjectName(QString("pBurst%1").arg(num_of_process));
    prio->setObjectName(QString("pPriority%1").arg(num_of_process));
    btn->setObjectName(QString("pDelbtn%1").arg(num_of_process));

    process_grid->addWidget(arriv,num_of_process,0);
    process_grid->addWidget(burst,num_of_process,1);
    process_grid->addWidget(prio,num_of_process,2);
    process_grid->addWidget(btn,num_of_process,3);
    num_of_process++;

}
