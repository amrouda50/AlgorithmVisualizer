#include "acutest.h"
#include "../sources/mainwindow.h"
#include "../sources/column.h"
#include "../sources/Sorting.h"

//compile with: g++ -o test SortingTest.cpp
//documentation of acutest: https://github.com/mity/acutest/blob/master/README.md

//--------------------------------------------------------------------------------------------------------------
//BubbleSort


void Bubble_Sort_Medium_Values(void){

        MainWindow m;  m.addColumn(5); m.addColumn(4); m.addColumn(3);m.addColumn(2); m.addColumn(1);
        MainWindow d;  d.addColumn(1); d.addColumn(2); d.addColumn(3);d.addColumn(4); d.addColumn(5);
	Sort *sorting = new BubbleSort();
        sorting->sort(m.GetColumns().getColumns(),m);
	TEST_CHECK_(m.GetColumns().getColumns() == d.GetColumns().getColumns() );
	
}

TEST_LIST = {
	{"Sorting::BubbleSort() function", Bubble_Sort_Medium_Values },
	{0} /*Must be terminated with {0}*/
};