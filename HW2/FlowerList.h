//Izaan Aamir
//22001488
#pragma once
#include "Flower.h"
#include <string>
class FlowerList {
public:
	FlowerList();
	FlowerList(const FlowerList& aList);
	~FlowerList();
	bool isEmpty() const;
	int getLength() const;
	bool retrieve(string flowerName, Flower& flower) const;
	bool add(string flowerName);
	bool remove(string flowerName);
	bool find(string flowerName) const;
	void printFlowerlist() const;
	void removeFeature(string feature, string name);
	void addFeature(string feature, string name);
	void printFlowerFeatures(string name) const;
	string findFlowerFeatures(string features) const;
private:
	struct FlowerNode {
		Flower f;
		FlowerNode* next;
	};
	int size;
	FlowerNode* head; //the flowers are stored in a sorted singly linear linked list
	// ...
	//you may define additional member functions and data members, if necessary
};