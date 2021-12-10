#ifndef COLUMNS_H
#define COLUMNS_H
#include "column.h"
//a set of columns with values between 1 and 100
class Columns {
    private:
        vector<Column> v;
    public:

        Columns(){ v = { }; }
        vector<Column>& getColumns(){
           return v;
        }

        //adds a Column to the vector of columns
        void addColumn(int val);

        //returns the number of columns
        int numberOfColumns() ;

        //returns the n-th Column's value
        int nthColumnVal(int n) ;

        //returns the value of the highest value Column
        int maxColumn();

        //returns the value of the lowest value Column
        int minColumn();
};
#endif // COLUMNS_H
