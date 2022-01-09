#pragma once
#ifndef __LABORGANIZER_H
#define __LABORGANIZER_H

#include <string>

using namespace std;
#include "Cabinet.h"

class LabOrganizer {
public:
    LabOrganizer();
    ~LabOrganizer();
    void addCabinet(int id, int rows, int columns);
    void removeCabinet(int id);
    void listCabinets();
    void cabinetContents(int id);
    void placeChemical(int cabinetId, string location, string chemType, int chemID);
    void findChemical(int id);
    void removeChemical(int id);
    // ...
    //you may define additional member functions and data members, if necessary
private:
    Cabinet* data;
    int numberOfCabinets;
};
#endif