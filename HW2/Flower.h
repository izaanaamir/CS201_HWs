//IZAAN AAMIR
//22001488

#pragma once
#ifndef __CHEMICAL_H
#define __CHEMICAL_H
#include <string>

using namespace std;

class Flower {
public:
	Flower();
	Flower(string flowerName);
	Flower(const Flower& aFlower);
	~Flower();
	bool isEmpty() const;
	int getLength() const;
	bool add(string feature);
	bool remove(string feature);
	string printFlower() const;
	void setName(string name);
	string getName();
	void getFeature();
	bool checkFeature(string feature);
private:
	struct FeatureNode {
		string feature;
		FeatureNode* next;
	};
	int size;
	string flowerName;
	FeatureNode* head; //the features are stored in a sorted singly linear linked list
	// ...
	//you may define additional member functions and data members, if necessary
};
#endif
