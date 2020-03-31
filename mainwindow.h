#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTime>
#include <QKeyEvent>
#include <ui_mainwindow.h>
#include "myquery.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_add_last_button_clicked();

    void on_add_first_button_clicked();

    void on_peek_last_button_clicked();

    void on_peek_first_button_clicked();

    void on_pop_last_button_clicked();

    void on_pop_first_button_clicked();

    void on_count_button_clicked();

    void on_random_button_clicked();

    void on_clear_button_clicked();

    void on_task_button_clicked();

    void on_insert_button_clicked();

    void on_add_swap_button__clicked();

    void on_add_erase_button_clicked();

    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
