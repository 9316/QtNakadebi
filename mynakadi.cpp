#include "mynakadi.h"

mynakadi::mynakadi(QObject *parent) : QThread (parent)
{

}
void mynakadi::run(){
    for(int i=0; i<500; i++){
        if(this->stop) break;

        emit this->numchange(i);
        emit this->numchanged(i);
        msleep(sleepTime);

        num = i;
        num2= i;
    }
}

