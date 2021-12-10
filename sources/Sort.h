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
    virtual void sort( vector<Column> &numbers);
    void swap(Column *xp, Column *yp)
    {
        Column temp = *xp;
        *xp = *yp;
        *yp = temp;
    }

};

//Minimum value selection Sort
class SelectionSort:public Sort{
 public:
    SelectionSort(){
         //In Selection sort CurrentValue1 represent the Minmum value selected
        CurrentIndex1 = 0;
        CurrentIndex2 = 0;
    }
    void sort( std::vector<Column> &numbers){
        int i , j;
        for (i = 0; i < (int)numbers.size() ; i++)
           {
               // Find the minimum element in unsorted array
               CurrentIndex1 = i;
               for (j = i+1; j < (int)numbers.size(); j++){
                   CurrentIndex2 = j;
                   if (numbers[CurrentIndex2].getVal() < numbers[CurrentIndex1].getVal()){
                       CurrentIndex1 = j;
                   }
               }
                // Swap the found minimum element with the first element
                swap(&numbers[CurrentIndex1], &numbers[i]);


           }


    }



};

class BubbleSort : public Sort{
  public:
   void sort(std::vector<Column> &numbers){
    int i , j ;
    for(i = 0 ; i < (int)numbers.size()-1 ; i++  ){
        for( j = numbers.size()-1 ;  j > i  ; j--){
            if(numbers[j-1].getVal() > numbers[j].getVal()){
                swap(&numbers[j] , &numbers[j-1]);

            }
        }

    }




}
};
#endif // SORT_H
