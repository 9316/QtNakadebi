#ifndef MYNAKADI_H
#define MYNAKADI_H
#include <QtCore>
#include <QThread>

class mynakadi : public QThread
{
    Q_OBJECT

public:
    explicit mynakadi(QObject *parent =0);
    mynakadi();
    void run();
    bool stop;
    int sleepTime;
    int num;
    int num2;

signals:
    void numchange(int);
    void numchanged(int);
};

#endif // MYNAKADI_H
