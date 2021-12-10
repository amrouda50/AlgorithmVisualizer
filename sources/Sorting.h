#ifndef SORT_H
#define SORT_H
#include <vector>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "column.h"
class Sort{
    protected:
    int CurrentIndex1;
    int CurrentIndex2;
 public:
    virtual void sort( vector<Column> &numbers ,  MainWindow* window);
    void swap(Column *xp, Column *yp);

};

//Minimum value selection Sort
class SelectionSort:public Sort{
 public:
    SelectionSort();
    void sort( std::vector<Column> &numbers , MainWindow* window);
};
class BubbleSort : public Sort{
  public:
   void sort(std::vector<Column> &numbers ,  MainWindow* window);
};


class QuickSort : public Sort{
  public:
   void sort(std::vector<Column> &numbers ,  MainWindow* window);

};


class ShellSort : public Sort{
  public:
   void sort(std::vector<Column> &numbers ,  MainWindow* window);

};

class MergeSort : public Sort{
  public:
   void sort(std::vector<Column> &numbers,  MainWindow* window);
};

class InsertionSort : public Sort{
  public:
   void sort(std::vector<Column> &numbers ,  MainWindow* window);

};
#endif // SORT_H
