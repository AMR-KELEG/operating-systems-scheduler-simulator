#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QString>
#include "simulationwindow.h"
#include "Process.h"
#include <vector>

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

    void on_ps_clicked();

    void on_sjf_clicked();

    void on_fcfs_clicked();

    void on_rr_clicked();

    void on_add_process_clicked();

private:
    Ui::MainWindow *ui;
    SimulationWindow *simwin;
    QGridLayout *process_grid;
    QWidget *viewport ;
    int num_of_process;
    std::vector<Process> processVector;
    int quanta;
    std::string algorithm;

};

#endif // MAINWINDOW_H
