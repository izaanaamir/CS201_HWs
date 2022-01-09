#pragma once
#ifndef __CHEMICAL_H
#define __CHEMICAL_H
#include <string>

using namespace std;
class Chemical {
public:
    Chemical(int id, int row, int column, string chemType);
    Chemical();
    int getID();
    char getChemType();
    void removeChemicalFromList();
    bool chemicalExists();
    void setID();
    string getLoc();
    int getRow();
    int getColumn();
    Chemical& operator=(const Chemical& other);

private:
    int id;
    int row;
    int column;
    char chemType;
    bool chemPresent = false;

};
#endif
