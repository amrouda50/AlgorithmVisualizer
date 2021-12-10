#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QString>
#include "column.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void drawColumns(); //draw all columns on the canvas (QGraphicsScene object)
    void addColumn(int newColumnVal); //add a new column
    void clearCanvas(); //clear the canvas (QGraphicsScene object)
    void delColumns();
    void swapColumns(int col1ind,int col2ind);
    void delay(int time);
    Columns GetColumns();
    float  animationdelayGetter() ;
    void  animationdelaySetter(int time) ;

private slots:
    void on_addToDatasetButton_clicked();
    void on_clearDatasetButton_clicked();

    void on_pushButton_2_clicked();

    void on_horizontalSlider_sliderMoved(int position);



    void on_checkBox_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    int animationdelay;
    bool ShowValues;
    //all columns are stored here
    Columns columns;
};
#endif // MAINWINDOW_H
