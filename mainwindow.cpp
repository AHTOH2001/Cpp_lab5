#include "mainwindow.h"
#include <demonstrationclass.h>
DemonstrationClass* demclass;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(490,830);
    this->setFixedSize(490,830);
    demclass = new DemonstrationClass(ui,this);

    QTime now = QTime::currentTime();
    srand(now.msec());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_last_button_clicked()
{
    demclass -> on_add_last_button_clicked();
}

void MainWindow::on_add_first_button_clicked()
{
    demclass -> on_add_first_button_clicked();
}

void MainWindow::on_peek_last_button_clicked()
{
    demclass -> on_peek_last_button_clicked();
}

void MainWindow::on_peek_first_button_clicked()
{
    demclass -> on_peek_first_button_clicked();
}

void MainWindow::on_pop_last_button_clicked()
{
    demclass -> on_pop_last_button_clicked();
}

void MainWindow::on_pop_first_button_clicked()
{
    demclass -> on_pop_first_button_clicked();
}


void MainWindow::on_count_button_clicked()
{
    demclass -> on_count_button_clicked();
}


void MainWindow::on_random_button_clicked()
{
    demclass -> on_random_button_clicked();
}

void MainWindow::on_clear_button_clicked()
{
    demclass -> on_clear_button_clicked();
}

void MainWindow::on_task_button_clicked()
{
    demclass -> on_task_button_clicked();
}

void MainWindow::on_insert_button_clicked()
{
    demclass -> on_insert_button_clicked();
}

void MainWindow::on_add_swap_button__clicked()
{
    demclass -> on_add_swap_button__clicked();
}


void MainWindow::on_add_erase_button_clicked()
{
    demclass -> on_add_erase_button_clicked();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    demclass -> keyPressEvent(event);
}


