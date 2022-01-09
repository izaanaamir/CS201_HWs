#include <iostream>
#include <string>
#include "Chemical.h"
#include "Cabinet.h"
#include <stdlib.h>

using namespace std;


Cabinet::Cabinet(int givenId, int givenRow, int givenColumn) {
    id = givenId;
    row = givenRow;
    column = givenColumn;
    chemical = new Chemical* [row];
    for (int i = 0; i < row; i++)
    {
        chemical[i] = new Chemical[column];

    }
    numberOfFreeSlots = column * row;
    numOfChemicals = 0;
}

Cabinet::Cabinet() {
    id = 0;
    row = 0;
    column = 0;
    numberOfFreeSlots = 0;
    numOfChemicals = 0;
    chemical = NULL;
}

int Cabinet::getID() {
    return id;
}

int Cabinet::getRow() {
    return row;
}

int Cabinet::getColumn() {
    return column;
}


int Cabinet::getChemicalID(int id) {
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (id == chemical[i][j].getID())
            {
                return true;
            }
        }
    }

    return false;
}

int Cabinet::getNumOfFreeSlots() {
    return numberOfFreeSlots;
}

void Cabinet::getCabinetItems() {
    string rowName = "ABCDEFGHI";
    string colNum = "123456789";
    cout << "ID: " << id << ", " << row << "x" << column << ", empty: " << numberOfFreeSlots<< ". Chemicals: ";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (chemical[i][j].getChemType() != '+') {
                cout << rowName[chemical[i][j].getRow()]<< colNum[chemical[i][j].getColumn()] << ": " << chemical[i][j].getID() << " |";
            }
        }
    }
    cout << "\n" << endl;
    cout << "   ";
    for (int i = 0; i < column; i++)
    {
        cout << i + 1 << "  ";
    }
    cout << endl;
    for (int j = 0; j < row; j++)
    {
        char m = j + 65;
        cout << m << "  ";
        for (int k = 0; k < column; k++)
        {
            cout << chemical[j][k].getChemType() << "  ";
        }
        cout << endl;
    }
}


int Cabinet::getNumofChemicals() {
    return numOfChemicals;
}

bool Cabinet::isPlacable(int rows, int columns) {
    //for first row
    if (rows == 0) {
        if (columns == 0) //first column
        {
            for (int k = rows; k <= rows + 1; k++)
            {
                for (int l = columns; l <= columns + 1; l++)
                {
                    if (chemical[k][l].getChemType() == 'c')
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        else if (columns == column-1) { // last column
            for (int k = rows; k <= rows + 1; k++)
            {
                for (int l = columns - 1; l <= columns; l++)
                {
                    if (chemical[k][l].getChemType() == 'c')
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        else { //rest of the columns
            for (int k = rows ; k <= rows + 1; k++)
            {
                for (int l = columns -  1; l <= columns + 1; l++)
                {
                    if (chemical[k][l].getChemType() == 'c')
                    {
                        return false;
                    }
                }
            }
            return true;
        }
    }
    else if (rows == row-1) { // for last row
        if (columns == 0)
        {
            for (int k = rows -1 ; k <= rows; k++)
            {
                for (int l = columns; l <= columns + 1; l++)
                {
                    if (chemical[k][l].getChemType() == 'c')
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        else if (columns == column-1) {// last column
            for (int k = rows -1; k <= rows; k++)
            {
                for (int l = columns - 1; l <= columns; l++)
                {
                    if (chemical[k][l].getChemType() == 'c')
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        else { //rest of the columns
            for (int k = rows-1; k <= rows; k++)
            {
                for (int l = columns - 1; l <= columns + 1; l++)
                {
                    if (chemical[k][l].getChemType() == 'c')
                    {
                        return false;
                    }
                }
            }
            return true;
        }
    }
    else {
        if (columns == 0) //first column
        {
            for (int k = rows -1; k <= rows + 1; k++)
            {
                for (int l = columns; l <= columns + 1; l++)
                {
                    if (chemical[k][l].getChemType() == 'c')
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        else if (columns == column-1) {
            for (int k = rows - 1; k <= rows + 1; k++)
            {
                for (int l = columns - 1; l <= columns; l++)
                {
                    if (chemical[k][l].getChemType() == 'c')
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        else {

            for (int k = rows - 1; k <= rows + 1; k++)
            {
                for (int l = columns - 1; l <= columns + 1; l++)
                {
                    if (chemical[k][l].getChemType() == 'c')
                    {
                        return false;
                    }
                }
            }
            return true;
        }
    }
}

string Cabinet::suitablePlacement(int rows, int columns) {
    string suitableSlot1 = "";
    string suitableSlot2 = "";
    string suitableSlot3 = "";
    string suitableSlot4 = "";
    bool state;
    int distance1 = 0;
    int distance2 = 0;
    int distance3 = 0;
    int distance4 = 0;
    string rowNames = "ABCDEFGHI";
    string colNames = "123456789";
        for (int k = 0; k < row; k++)
        {
            for (int l = 0; l < column; l++)
            {
                state = isPlacable(k, l);
                if (state)
                {
                    if (abs(k - rows) <= 1 && abs(l - columns) <= 1)
                    {
                        distance1++;
                        suitableSlot1 = suitableSlot1 + rowNames[k] + colNames[l] + " ";
                    }
                    else if (abs(k - rows) <= 2 && abs(l - columns) <= 2 )
                    {
                        distance2++;
                        suitableSlot2 = suitableSlot2 + rowNames[k] + colNames[l] + " ";
                    }
                    else if (abs(k - rows) <= 3 && abs(l - columns) <= 3) {
                        distance3++;
                        suitableSlot3 = suitableSlot3 + rowNames[k] + colNames[l] + " ";
                    }
                    else if (abs(k - rows) <= 4 && abs(l - columns) <= 4) {
                        distance4++;
                        suitableSlot4 = suitableSlot4+ rowNames[k] + colNames[l] + " ";
                    }
                }
            }
        }
        if (distance1 != 0) {
            return suitableSlot1 + "\n";
        }
        if (distance2 != 0) {
            return suitableSlot2 + "\n";
        }
        if (distance3 != 0) {
            return suitableSlot3 + "\n";
        }
        if (distance4 != 0) {
            return suitableSlot4 + "\n";
        }

    return "";
 }
       
string Cabinet::suitablePlacementforR(int rows, int columns) {
    string suitableSlot1 = "";
    string suitableSlot2 = "";
    string suitableSlot3 = "";
    string suitableSlot4 = "";
    int distance1 = 0;
    int distance2 = 0;
    int distance3 = 0;
    int distance4 = 0;
    string rowNames = "ABCDEFGHI";
    string colNames = "123456789";
    for (int k = 0; k < row; k++)
    {
        for (int l = 0; l < column; l++)
        {
            
            if (chemical[k][l].getChemType()=='+')
            {
                if (abs(k - rows) <= 1 && abs(l - columns) <= 1)
                {
                    distance1++;
                    suitableSlot1 = suitableSlot1 + rowNames[k] + colNames[l] + " ";
                }
                else if (abs(k - rows) <= 2 && abs(l - columns) <= 2)
                {
                    distance2++;
                    suitableSlot2 = suitableSlot2 + rowNames[k] + colNames[l] + " ";
                }
                else if (abs(k - rows) <= 3 && abs(l - columns) <= 3) {
                    distance3++;
                    suitableSlot3 = suitableSlot3 + rowNames[k] + colNames[l] + " ";
                }
                else if (abs(k - rows) <= 4 && abs(l - columns) <= 4) {
                    distance4++;
                    suitableSlot4 = suitableSlot4 + rowNames[k] + colNames[l] + " ";

                }
            }
        }
    }
    if (distance1 != 0) {
        return suitableSlot1 + "\n";
    }
    if (distance2 != 0) {
        return suitableSlot2 + "\n";
    }
    if (distance3 != 0) {
        return suitableSlot3 + "\n";
    }
    if (distance4 != 0) {
        return suitableSlot4 + "\n";
    }

    return "";
}

            

void Cabinet::addChemical(int row, int column, string chemtype, int id) {
    chemical[row][column] = Chemical(id, row, column, chemtype);
    numOfChemicals++;
    numberOfFreeSlots--;
}

void Cabinet::removeSingleChemical(int chemID) {
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (chemID == chemical[i][j].getID())
            {
                cout << "Chemical with ID: " << chemID << " removed from Cabinet "<<getID()<<"\n";
                chemical[i][j].removeChemicalFromList();
                numberOfFreeSlots++;
                numOfChemicals--;
                return;
            }
        }
        
    }
}

void Cabinet::removeCabinet() {
    for (int i = 0; i < row; i++)
    {
        delete[] chemical[i];
    }
    delete[] chemical;
}

void Cabinet::getChemicalLocation(int id) {
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (id == chemical[i][j].getID())
            {
                char k = i + 65;
                cout << k;
                cout << j+1;
            }
        }
    }
}

void Cabinet::removeAllChemicals(int cabID) {
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (chemical[i][j].chemicalExists())
            {
                int id = chemical[i][j].getID();
                cout << "Chemical with ID: " << id << " removed from Cabinet " << cabID << endl;
                chemical[i][j].removeChemicalFromList();
                numberOfFreeSlots++;
                numOfChemicals--;
            }

        }
    }
}

Cabinet& Cabinet::operator=(const Cabinet& other) {
    id = other.id;
    row = other.row;
    column = other.column;
    numOfChemicals = other.numOfChemicals;
    numberOfFreeSlots = other.numberOfFreeSlots;
    chemical = other.chemical;
    return *this;
}

bool Cabinet::isChemicalPresent(int rows, int columns) {
    if (chemical[rows ][columns].chemicalExists()) {
        return true;
    }
    return false;
}
