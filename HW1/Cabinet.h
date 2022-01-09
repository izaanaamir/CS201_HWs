#pragma once
#ifndef __CABINET_H
#define __CABINET_H
#include <string>
#include "Chemical.h"
#include <stdlib.h>
using namespace std;

class Cabinet {
public:
    Cabinet(int id, int rows, int columns);
    Cabinet();
    int getID();
    int getRow();
    int getColumn();
    int getChemicalID(int id);
    int getNumOfFreeSlots();
    void getCabinetItems();
    int getNumofChemicals();
    bool isPlacable(int rows, int columns);
    string suitablePlacement(int row, int column);
    void addChemical(int row, int column, string chemtype, int id);
    void removeSingleChemical(int chemID);
    void removeCabinet();
    void getChemicalLocation(int id);
    void removeAllChemicals(int cabID);
    Cabinet& operator=(const Cabinet& other);
    bool isChemicalPresent(int rows, int columns);
    string suitablePlacementforR(int rows, int columns);


private:
    Chemical** chemical;
    int id;
    int row;
    int column;
    int numberOfFreeSlots;
    int numOfChemicals;
    string rowLetters = "ABCDEFGHI";
    string colNum = "123456789";

};
#endif

