 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <mynakadi.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m1=new mynakadi(this);
    m2=new mynakadi(this);
    connect(m1,SIGNAL(numchange(int)),this,SLOT(onNumChange(int)));
    connect(m1,SIGNAL(numchange(int)),ui->progressBar,SLOT( setValue(int)));
    connect(m2,SIGNAL(numchanged(int)),this,SLOT(onNumChanged(int)));
    connect(m2,SIGNAL(numchanged(int)),ui->progressBar_2,SLOT( setValue(int)));


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::onNumChange(int k){
    if(m1->num<=100)
            ui->label->setText(QString::number(k));
    else if(m1->num>100)
            ui->label->setText("<font color=red>" + QString::number(k) + "</font>");
}

void MainWindow::on_pushButton_clicked()
{
    m1->stop=false;
    if(ui->lineEdit->text().trimmed().isEmpty()){
        QMessageBox::warning(this,"გაფრთხილება","გთხოვთ შეიყვანოთ ციკლის სიჩქარე(რაც ნაკლები მით უფრო ჩქარი");
    }
    else {m1->sleepTime=ui->lineEdit->text().toInt();

    m1->start();
    m1->wait(2);

}


}




void MainWindow::on_pushButton_2_clicked()
{

     m1->stop=true;

    }



void MainWindow::onNumchanged(int c){
    if(m2->num2<=100)
        ui->label_3->setText(QString::number(c));
    else if(m2->num2>100)
        ui->label_3->setText("<font color=red>"+ QString::number(c)+"</font");
}



void MainWindow::on_pushButton_3_clicked()
{
    m2->stop=false;
    if(ui->lineEdit_2->text().trimmed().isEmpty()){
        QMessageBox::warning(this,"გაფრთხილება","გთხოვთ შეიყვანოთ ციკლის სიჩქარე(რაც ნაკლებია მით უფრო ჩქარია)");

    }
    else{m2->sleepTime=ui->lineEdit_2->text().toInt();
        m2->start();
        m2->wait(4);
    }

}

void MainWindow::on_pushButton_4_clicked()
{
    m2->stop=true;
}


