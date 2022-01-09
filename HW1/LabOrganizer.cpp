#include <iostream>
#include <string>
using namespace std;
#include "LabOrganizer.h"


LabOrganizer::LabOrganizer() {
    numberOfCabinets = 0;
    data = NULL;
}
LabOrganizer::~LabOrganizer() {
        for (int i = 0; i < numberOfCabinets; i++)
        {
            data[i].removeCabinet();
        }
        numberOfCabinets = 0;
        delete[] data;
    }

void LabOrganizer::addCabinet(int id, int rows, int columns) {


    for (int i = 0; i < numberOfCabinets; i++)
    {
        if (data[i].getID() == id)
        {
            cout << "Cannot add the cabinet: ID "<< id<< " is already in the system\n";
            return;
        }
    }
    if (rows > 9 || columns > 9)
    {
        cout << "Cannot add the cabinet: dimensions are out of bound\n";
        return;
    }
    if (numberOfCabinets == 0)
    {
        data = new Cabinet[1];
        data[0] = Cabinet(id, rows, columns);
        cout << "Added a Cabinet: ID " << id << " and dimensions " << rows << " to " << columns << "\n";
        numberOfCabinets++;
    }
    else {
        Cabinet* temp = new Cabinet[numberOfCabinets];
        for (int i = 0; i < numberOfCabinets; i++) {
            temp[i] = data[i];

        }
        delete[] data;
        numberOfCabinets++;
        data = new Cabinet[numberOfCabinets];
        for (int i = 0; i < numberOfCabinets-1; i++)
        {
            data[i] = temp[i];
        }
        delete[] temp;
        data[numberOfCabinets - 1] = Cabinet(id, rows, columns);
        cout << "Added a Cabinet: ID " << id << " and dimensions " << rows << " to " << columns << "\n";
    }
}

void LabOrganizer::removeCabinet(int id) {
    int count = 0;

    for (int i = 0; i < numberOfCabinets; i++)
    {
        if (data[i].getID() == id) {
            data[i].removeAllChemicals(id);
            Cabinet* temp = new Cabinet[numberOfCabinets - 1];
            for (int j = 0; j < numberOfCabinets; j++)
            {
                if (j != i) {
                    temp[count] = data[j];
                    count++;
                }
            }
            numberOfCabinets--;
            data[i].removeCabinet();
            delete[] data;
            data = new Cabinet[numberOfCabinets];

            for (int i = 0; i < numberOfCabinets; i++)
            {
                data[i] = temp[i];
            }
            delete[] temp;
            cout << "Cabinet "<< id << " has been removed" << endl;
            return;
        }
    }
    cout << "Cabinet "<<id<< " does not exist in the system"<< endl;
}
void LabOrganizer::listCabinets() {
    if (numberOfCabinets == 0)
    {
        cout << "No Cabinets are present\n";
        return;
    }
    cout << "List of all cabinets"<<endl;

    for (int i = 0; i < numberOfCabinets; i++)
    {
        cout << "ID: " << data[i].getID() << ", Dim: " << data[i].getRow() << "x" << data[i].getColumn() << " , Number of Empty Slots: " << data[i].getNumOfFreeSlots() << endl;
    }

}
void LabOrganizer::cabinetContents(int id) {
    for (int i = 0; i < numberOfCabinets; i++)
    {
        if (data[i].getID() == id)
        {
            data[i].getCabinetItems();
            return;
        }
    }
    cout << "Cabinet "<< id<< " is not in the system" << endl;
    return;
}

void LabOrganizer::placeChemical(int cabinetId, string location, string chemType, int chemID) {
    int row = location[0] - 64;
    int col = location[1] - '0';
    
    for (int i = 0; i < numberOfCabinets; i++)
    {
        if (cabinetId == data[i].getID())
        {   
            if (data[i].isChemicalPresent(row-1,col-1))
            {
                cout << "Location "<< location<< " in cabinet "<< cabinetId<< " is already occupied. Nearest possible locations for this chemical: " <<data[i].suitablePlacementforR(row - 1, col - 1)<< endl;
                return;
            }
            for (int i = 0; i < numberOfCabinets; i++)
            {
                if (data[i].getChemicalID(chemID))
                {
                    cout << "Chemical with ID "<< chemID<<" already exists in the system" << endl;
                    return;
                }
            }
              
            if (chemType[0] == 'r')
            {
                data[i].addChemical(row-1, col-1, chemType, chemID);
                cout << chemType << " chemical with ID " << chemID << " has been placed at location " << location << " in cabinet " << cabinetId << endl;
                return;
            }
            if (chemType[0] == 'c') {
                if (data[i].isPlacable(row -1, col-1)) {
                    data[i].addChemical(row-1, col-1, chemType, chemID);
                    cout << chemType << " chemical with ID " << chemID << " has been placed at location " << location << " in cabinet " << cabinetId << endl;
                    return;
                }
                else {
                    cout << "Location " << location<< " in cabinet "<< cabinetId<<" is not suitable for a combustive chemical. Nearest possible locations for this chemical: ";
                    string suitablePlaces = data[i].suitablePlacement(row-1, col-1);
                    cout << suitablePlaces;
                    return;
                }
            }
            
        }
    }
    cout << "The Cabinet ID doesn't exist" << endl;
    return;
    }
    


void LabOrganizer::findChemical(int id) {

    for (int i = 0; i < numberOfCabinets; i++)
    {
        if (data[i].getChemicalID(id))
        {
            cout << "Chemical " << id << " is at location ";
            data[i].getChemicalLocation(id);
            cout<<" from Cabinet " << data[i].getID() << "\n";
            return;
        }

    }

    cout << "Chemical "<< id<<" is not in the system"<< endl;

}

void LabOrganizer::removeChemical(int id) {
    for (int i = 0; i < numberOfCabinets; i++)
    {
        if (data[i].getChemicalID(id)) {
            data[i].removeSingleChemical(id);
            return;
        }
    }
    cout << "Chemical " << id << " is not in the system \n";

}
