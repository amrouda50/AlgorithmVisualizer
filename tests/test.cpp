#include "acutest.h"
#include "../sources/column.h"


//compile with: g++ -o test test.cpp
//documentation of acutest: https://github.com/mity/acutest/blob/master/README.md

//--------------------------------------------------------------------------------------------------------------

//Testing the Column class
void column_empty_constructor(void){
	Column col;
	TEST_CHECK_(col.getVal() != 0, "an empty column's value is: %d",col.getVal() );
	TEST_CHECK_(col.getPos() == 0, "an empty column's position is: %d",col.getPos() );
}

void column_value_constructor(void){
	Column col(3);
	TEST_CHECK_(col.getVal() == 3, "a value set column's value is: %d",col.getVal() );
	TEST_CHECK_(col.getPos() == 0, "a value set column's position is: %d",col.getPos() );
}

void column_value_and_position_constructor(void){
	Column col(5,7);
	TEST_CHECK_(col.getVal() == 5, "a value and position set column's value is: %d",col.getVal() );
	TEST_CHECK_(col.getPos() == 7, "a value and position set column's position is: %d",col.getPos() );
}

//--------------------------------------------------------------------------------------------------------------
//Testing the Columns class

void columns_delete_function() {
	Columns cols;
	cols.addColumn(3);cols.addColumn(7);cols.addColumn(4);
	cols.delColumns();
	TEST_CHECK_(cols.numberOfColumns() == 0, "number of columns after deletion: %d",cols.numberOfColumns() );
}

void columns_number_of_columns_function() {
	Columns cols;
	cols.addColumn(3);cols.addColumn(7);cols.addColumn(4);
	TEST_CHECK_(cols.numberOfColumns() == 3, "number of columns after deletion: %d",cols.numberOfColumns() );
}

void columns_nth_column_val_function() {
	Columns cols;
	cols.addColumn(3);cols.addColumn(7);cols.addColumn(4);
	
	TEST_CHECK_(cols.nthColumnVal(-1) == (-1), "%d th column value (underindexing): %d",-1,cols.nthColumnVal(-1) );
	TEST_CHECK_(cols.nthColumnVal(0) == 3, "%d th column value: %d",0,cols.nthColumnVal(0) );
	TEST_CHECK_(cols.nthColumnVal(1) == 7, "%d th column value: %d",1,cols.nthColumnVal(1) );
	TEST_CHECK_(cols.nthColumnVal(2) == 4, "%d th column value: %d",2,cols.nthColumnVal(2) );
	TEST_CHECK_(cols.nthColumnVal(3) == (-1), "%d th column value (overindexing): %d",3,cols.nthColumnVal(3) );
}


void columns_min_column_function() {
	Columns cols;
	cols.addColumn(3);cols.addColumn(7);cols.addColumn(4);cols.addColumn(1);cols.addColumn(12);cols.addColumn(15);cols.addColumn(3);
	
	TEST_CHECK_(cols.minColumn() == 1, "minimum value column is: %d",cols.minColumn() );
}

void columns_max_column_function() {
	Columns cols;
	cols.addColumn(3);cols.addColumn(7);cols.addColumn(4);cols.addColumn(1);cols.addColumn(12);cols.addColumn(15);cols.addColumn(3);
	
	TEST_CHECK_(cols.maxColumn() == 15, "minimum value column is: %d",cols.maxColumn() );
}

void columns_add_column_under_1_exception_function() {
	Columns cols;
	TEST_EXCEPTION(cols.addColumn(-41), std::invalid_argument);
}

void columns_add_column_over_100_exception_function() {
	Columns cols;
	TEST_EXCEPTION(cols.addColumn(145), std::invalid_argument);
}

void columns_add_column_function() {
	Columns cols;
	cols.addColumn(3);cols.addColumn(7);cols.addColumn(4);cols.addColumn(1);
	
	TEST_CHECK_(cols.numberOfColumns() == 4, "number of columns: %d",cols.numberOfColumns() );
	TEST_CHECK_(cols.nthColumnVal(0) == 3, "%d th column value: %d",0,cols.nthColumnVal(0) );
	TEST_CHECK_(cols.nthColumnVal(1) == 7, "%d th column value: %d",1,cols.nthColumnVal(1) );
	TEST_CHECK_(cols.nthColumnVal(2) == 4, "%d th column value: %d",2,cols.nthColumnVal(2) );
	TEST_CHECK_(cols.nthColumnVal(3) == 1, "%d th column value: %d",3,cols.nthColumnVal(3) );
	
}
//--------------------------------------------------------------------------------------------------------------
//Test results

TEST_LIST = {
	{"Column() constructor", column_empty_constructor },
	{"Column(int val) constructor", column_value_constructor },
	{"Column(int val, int pos) constructor", column_value_and_position_constructor },
	
	{"Columns::delColumns() function", columns_delete_function },
	{"Columns::numberOfColumns() function", columns_number_of_columns_function },
	{"Columns::nthColumnVal(int n) function", columns_nth_column_val_function },
	{"Columns::minColumn() function", columns_min_column_function },
	{"Columns::maxColumn() function", columns_max_column_function },
	{"Columns::addColumn(int val) function under 1 exception", columns_add_column_under_1_exception_function },
	{"Columns::addColumn(int val) function over 100 exception", columns_add_column_over_100_exception_function },
	{"Columns::addColumn(int val) function", columns_add_column_function },
	{0} /*Must be terminated with {0}*/
};

//--------------------------------------------------------------------------------------------------------------
