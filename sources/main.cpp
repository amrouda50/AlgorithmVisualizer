#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
/*
    MainWindow w;
    w.show();
    MainWindow m;
    m.addColumn(5);
    m.addColumn(4);
    m.addColumn(3);
    m.addColumn(2);
    m.addColumn(1);

   for(int i = 0 ; i < 4 ; i++){
       qDebug() << m.GetColumns().getColumns()[i].getVal();
   }*/


    //m.swapColumns([5,4,3,2,1] , m);

    //what the application will do =>
    w.addColumn(3);
    w.addColumn(7);
    w.addColumn(5);
    w.addColumn(9);
    w.addColumn(20);
    w.addColumn(1);
    w.addColumn(13);
    w.addColumn(5);
    w.addColumn(9);
    w.addColumn(1);
    w.addColumn(68);
    w.addColumn(92);
    w.addColumn(1);
    w.addColumn(81);

    w.drawColumns();

    return a.exec();
}


