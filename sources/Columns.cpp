#include "Columns.h"

//adds a Column to the vector of columns
void Columns::addColumn(int val){
    try {
        if (val < 1 || val > 100) {
            throw std::invalid_argument("The value of the column must be between 1 and 100");
        }
        else{
            Column newCol;
            newCol.setVal(val);
            v.push_back(newCol);
            newCol.setPos((int)v.size());
            cerr << newCol.getPos() << endl;
        }
    }
    catch (std::invalid_argument& e) {
        cerr << e.what() << endl;
    }


}

//returns the number of columns
int Columns::numberOfColumns() {
    return v.size();
}

//returns the n-th Column's value
int Columns::nthColumnVal(int n) {
    if(n < 0 || n > (numberOfColumns()-1) ) {
        return -1;
    }

    return v[n].getVal();
}

//returns the value of the highest value Column
int Columns::maxColumn() {
    if(numberOfColumns() == 0) {
        return -1;
    }
    int max = v[0].getVal();
    for(int i=0;static_cast<std::vector<int>::size_type>(i) < v.size();i++) {
        if( v[i].getVal() > max ) max = v[i].getVal();
    }
    return max;
}

//returns the value of the lowest value Column
int Columns::minColumn() {
    if(numberOfColumns() == 0) {
        return -1;
    }
    int min = v[0].getVal();
    for(int i=0;static_cast<std::vector<int>::size_type>(i) < v.size();i++) {
        if( v[i].getVal() < min ) min = v[i].getVal();
    }
    return min;
}
