//Izaan Aamir
//22001488
#pragma once
#include "FlowerList.h"
#include <string>
class FlowerLibrary {
public:
	FlowerLibrary();
	~FlowerLibrary();
	void addFlower(string name);
	void removeFlower(string name);
	void listFlowers() const;
	void listFeatures(string name) const;
	void addFeature(string name, string feature);
	void removeFeature(string name, string feature);
	void findFlowers(string feature) const;
private:
	FlowerList flowers;
	int size;
	// ...
	//you may define additional member functions and data members, if necessary
};
