#ifndef DEMONSTRATIONCLASS_H
#define DEMONSTRATIONCLASS_H
#include "mainwindow.h"
#include <QTime>
#include <QButtonGroup>
#include <QObject>
#include <QtGui>
#include <QtCore>
#include <QPainter>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QBrush>
#include <myquery.h>
//#include <QMessageBox>
//#include <MyTreap.h>
//#include <MyPair.h>

class DemonstrationClass: public QWidget
{
public:
    DemonstrationClass(Ui::MainWindow* _ui,MainWindow *_parent);

    ~DemonstrationClass();

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
    Ui::MainWindow* ui;
    MainWindow *parent;
};

#endif // DEMONSTRATIONCLASS_H
