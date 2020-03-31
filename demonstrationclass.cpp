#include "demonstrationclass.h"
MyQuery<int> qr;
DemonstrationClass::DemonstrationClass(Ui::MainWindow* _ui,MainWindow *_parent): QWidget()
{
    ui = _ui;
    parent = _parent;

}

DemonstrationClass::~DemonstrationClass()
 {

 }

void DemonstrationClass::on_add_last_button_clicked()
{
    if (ui->x->text()=="") return;
    qr.EnqueueLast(ui->x->text().toInt());
    ui->listWidget->addItem(ui->x->text());
    ui->x->clear();
}

void DemonstrationClass::on_add_first_button_clicked()
{
    if (ui->x->text()=="") return;
    qr.EnqueueFirst(ui->x->text().toInt());
    ui->listWidget->insertItem(0,ui->x->text());
    ui->x->clear();
}

void DemonstrationClass::on_peek_last_button_clicked()
{
    try {
        QMessageBox::information(this, "Well done",QString::number(qr.PeekLast()));
    }
    catch(int) {
        QMessageBox::critical(this, " ","Error");
        return;
    }
}

void DemonstrationClass::on_peek_first_button_clicked()
{
    try {
        QMessageBox::information(this, "Well done",QString::number(qr.PeekFirst()));
    }
    catch(int) {
        QMessageBox::critical(this, " ","Error");
        return;
    }
}

void DemonstrationClass::on_pop_last_button_clicked()
{
    try {
        QMessageBox::information(this, "Well done",QString::number(qr.DequeueLast()));
    }
    catch(int){
        QMessageBox::critical(this, " ","Error");
        return;
    }
    ui->listWidget->takeItem(qr.Count());
}

void DemonstrationClass::on_pop_first_button_clicked()
{
    try {
        QMessageBox::information(this, "Well done",QString::number(qr.DequeueFirst()));
    }
    catch(int){
        QMessageBox::critical(this, " ","Error");
        return;
    }
    ui->listWidget->takeItem(0);
}


void DemonstrationClass::on_count_button_clicked()
{
    QMessageBox::information(this, "Well done",QString::number(qr.Count()));
}


void DemonstrationClass::on_random_button_clicked()
{
    int n = rand()%12+3,p = 0;
    int mas[100];
    for (int i = 0;i<n;i++)
    {
        mas[i] = p + rand()%5+1;
        p = mas[i];
    }
    for (int i = 0;i<n;i++)
    {
        int p1 = rand()%n;
        int p2 = rand()%n;
        int x = mas[p1];
        mas[p1] = mas[p2];
        mas[p2] = x;
    }
    for (int i = 0;i<n;i++)
    {
        qr.EnqueueLast(mas[i]);
        ui->listWidget->addItem(QString::number(mas[i]));
    }
}

void DemonstrationClass::on_clear_button_clicked()
{
    qr.Clear();
    ui->listWidget->clear();
}

void DemonstrationClass::on_task_button_clicked()
{
    if (qr.Count()==0) return;
    MyQuery<int>::node *head = qr.First();
    MyQuery<int>::node *tale = qr.Last();
    int max = tale->x;
    int min = tale->x;
    while (head!=tale)
    {
        if (head->x==max)
        {
            QMessageBox::critical(this, " ","Error");
            return;
        }
        if (head->x>max) max=head->x;
        if (head->x==min)
        {
            QMessageBox::critical(this, " ","Error");
            return;
        }
        if (head->x<min) min=head->x;


        head = head->next;
    }
    head = qr.First();
    int i = 0;
    while (head->x!=min && head->x!=max)
    {
        head=head->next;
        i++;
    }
    if (head->x==min)
    {
        while (tale->x!=max) tale = tale->prev;
    }
    else
    {
        while (tale->x!=min) tale = tale->prev;
    }

    if (tale==head) return;
    while (head->next!=tale)
    {
        try
        {
        qr.EraseAt(i+1);
        }
        catch(int) {
            QMessageBox::critical(this, " ","Error");
            return;
        }
        ui->listWidget->takeItem(i+1);
    }
}

void DemonstrationClass::on_insert_button_clicked()
{
    if (ui->x_2->text()=="") return;
    if (ui->p_2->text()=="") return;
    try {
    qr.Insert(ui->p_2->text().toInt(),ui->x_2->text().toInt());
    } catch (int) {
    QMessageBox::critical(this, " ","Error");
    return;
    }

    ui->listWidget->insertItem(ui->p_2->text().toInt(),ui->x_2->text());
    ui->x_2->clear();
    ui->p_2->clear();
}

void DemonstrationClass::on_add_swap_button__clicked()
{
    int p1 = ui->p1->text().toInt();
    int p2 = ui->p2->text().toInt();
    try
    {
    qr.Swap(p1,p2);
    }
    catch(int) {
        QMessageBox::critical(this, " ","Error");
        return;
    }
    if (p1>p2)
    {
        int x = p1;
        p1 = p2;
        p2 = x;
    }
    QListWidgetItem *item2 = ui->listWidget->takeItem(p2);
    QListWidgetItem *item1 = ui->listWidget->takeItem(p1);
    ui->listWidget->insertItem(p1,item2);
    ui->listWidget->insertItem(p2,item1);
}


void DemonstrationClass::on_add_erase_button_clicked()
{
    try
    {
    qr.EraseAt(ui->p->text().toInt());
    }
    catch(int) {
        QMessageBox::critical(this, " ","Error");
        return;
    }
    ui->listWidget->takeItem(ui->p->text().toInt());
}

void DemonstrationClass::keyPressEvent(QKeyEvent *event)
{
    if (event->key()==Qt::Key_T) on_task_button_clicked();
    if (event->key()==Qt::Key_R) on_random_button_clicked();
    if (event->key()==Qt::Key_C) on_clear_button_clicked();
}


