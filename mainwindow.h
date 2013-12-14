#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <mynakadi.h>
#include <QtCore>
#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    mynakadi *m1;
    mynakadi *m2;


    ~MainWindow();
    
private:
    Ui::MainWindow *ui;


   public slots:
    void onNumChange(int);
public slots:
    void onNumchanged(int);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

};

#endif // MAINWINDOW_H
