
#include <string>
#include "Chemical.h"
using namespace std;

Chemical::Chemical(int Nid, int Nrow, int Ncolumn, string NchemType) {
    id = Nid;
    row = Nrow;
    column = Ncolumn;
    chemType = NchemType[0];
    chemPresent = true;
}

Chemical::Chemical() {
    id = 1;
    row = 0;
    column = 0;
    chemType = '+';
    chemPresent = false;
}
    
int Chemical::getID() {
    return id;
}

int Chemical::getRow() {
    return row;

}int Chemical::getColumn() {
    return column;
}
void Chemical::setID() {
    id = 0;
}

char Chemical::getChemType() {
    return chemType;
}

void Chemical::removeChemicalFromList() {
    chemType = '+';
    id = 1;
    chemPresent = false;
    row = 0;
    column = 0;
}

bool Chemical::chemicalExists() {
    return chemPresent;
}

Chemical& Chemical::operator=(const Chemical& other) {
    row = other.row;
    column = other.column;
    chemType = other.chemType;
    id = other.id;
    chemPresent = other.chemPresent;
        
    return *this;
}

string Chemical::getLoc() {
    string rowName = "ABCDEFGHI";
    string colNum = "123456789";
    return rowName[row]  + colNum[column] + "";
    
}
