#include <QtGui>
#include <QGraphicsScene>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "column.h"
#include "Sorting.h"
#include <sstream>
int Partition(std::vector<Column> &numbers,MainWindow* window, int start, int end);
void Sort::swap(Column *xp, Column *yp){
    Column temp = *xp;
    *xp = *yp;
    *yp = temp;

}
SelectionSort::SelectionSort(){

}
void SelectionSort::sort(std::vector<Column> &numbers , MainWindow* window){
    int i , j;
    for (i = 0; i < (int)numbers.size()+1 ; i++)
       {
           // Find the minimum element in unsorted array
           CurrentIndex1 = i;
           CurrentIndex2 = -1;
          int  minindex = i;
           for (j = i+1; j < (int)numbers.size(); j++){
               if (numbers[j].getVal() < numbers[minindex].getVal()){
                   CurrentIndex2 = j;
                   minindex = j;

               }

           }
            // Swap the found minimum element with the first element
           if(CurrentIndex2 != -1){

           window->swapColumns(CurrentIndex1, CurrentIndex2);
            //swap(&numbers[CurrentIndex1], &numbers[CurrentIndex2]);


           }





}

}

//Minimum value selection Sort


    void BubbleSort::sort(std::vector<Column> &numbers , MainWindow* window){

             int i , j ;
             for(i = 0 ; i < (int)numbers.size()-1 ; i++  ){
                 for( j = numbers.size()-1 ;  j > i  ; j--){
                     if(numbers[j-1].getVal() > numbers[j].getVal()){
                        // swap(&numbers[j] , &numbers[j-1]);

                     window->swapColumns( j-1 ,j);

                     }
                 }


    }

}


   void QuickSort::sort(std::vector<Column> &numbers ,  MainWindow* window){

           int  mid_idx  =  numbers.size()/2;
           int   root_el  =  numbers[mid_idx].getVal();

           vector<int>  smaller;
           vector<int>  bigger;
           vector<int>  equals;

           for (int i = 0; i < numbers.size(); i++)
           {
               if (numbers[i].getVal() > root_el){
                   bigger.push_back(numbers[i].getVal());
                     window->swapColumns(i, root_el);
               }
               else if (numbers[i].getVal() < root_el)
               {
                   smaller.push_back(numbers[i].getVal());

               }
               else
                   equals.push_back(numbers[i].getVal());

           }
           window->swapColumns(numbers.end()->getPos(),mid_idx );



       }

   void ShellSort::sort(std::vector<Column> &numbers ,  MainWindow* window){
       int gap = numbers.size()/2;
           while(gap > 0){
               for(int index = gap; index < numbers.size(); index++){
                   for(int j = index; j >= gap; j-=gap){
                       if(numbers[j].getVal() < numbers[j-gap].getVal()){
                        window->swapColumns(j-gap,j);
                       }
                       else{
                           break;
                       }
                   }
               }
               gap = gap/2;

           }
       }
   void MergeSortedIntervals(std::vector<Column> &numbers, int s, int m, int e,  MainWindow* window) {

       // temp is used to temporary store the vector obtained by merging
       // elements from [s to m] and [m+1 to e] in v
       vector<int> temp;

       int i, j;
       i = s;
       j = m + 1;

       while (i <= m && j <= e) {

           if (numbers[i].getVal() <= numbers[j].getVal()) {
               temp.push_back(numbers[i].getVal());
               ++i;
           }
           else {
               temp.push_back(numbers[j].getVal());
               ++j;
           }

       }

       while (i <= m) {
           temp.push_back(numbers[i].getVal());
           ++i;
       }

       while (j <= e) {
           temp.push_back(numbers[j].getVal());
           ++j;
       }

       for (int i = s; i <= e; ++i)
           numbers[i] = temp[i - s];
        //swap(numbers[i],numbers[temp[i - s]]);
        window->swapColumns(numbers[i].getVal(), numbers[temp[i - s]].getVal());

   }

   void MergeSort::sort(std::vector<Column> &numbers,  MainWindow* window){

   }

   void InsertionSort::sort(std::vector<Column> &numbers , MainWindow* window)
    {

            int i, key, j;
            for (i = 1; i < (int)numbers.size(); i++)
            {
                key = numbers[i].getVal();
                j = i - 1;

                /* Move elements of arr[0..i-1], that are
                greater than key, to one position ahead
                of their current position */
                while (j >= 0 && numbers[j].getVal() > key)
                {
                     window->swapColumns(j , j + 1);
                    j = j - 1;
                }
               numbers[j + 1].setVal( key);
            }
        }

