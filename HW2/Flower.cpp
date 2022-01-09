//Izaan Aamir	
//22001488

#include "Flower.h"
#include <string>
#include <iostream>

using namespace std;

Flower::Flower(){
	size = 0;
	flowerName = "";
	head = NULL;
}

Flower::Flower(string flowerName){
	size = 0;
	this->flowerName = flowerName;
	head = NULL;
}

Flower::Flower(const Flower& aFlower){
	size = 0;
	if (aFlower.head == NULL) {
		head = NULL;
	}
	else {
		head = new FeatureNode;
		head->feature = aFlower.head->feature;
		FeatureNode *tempPtr = head;
		for (FeatureNode* orPtr = aFlower.head->next; orPtr != NULL; orPtr = orPtr->next)
		{
			tempPtr->next = new FeatureNode;
			tempPtr = tempPtr->next;
			tempPtr->feature = orPtr->feature;

		}
		tempPtr->next = NULL;

	}
}

Flower::~Flower(){
	FeatureNode* temp = head;
	while (head != NULL)
	{
		temp = head->next;
		delete head;
		head = temp;
	}
}

bool Flower::isEmpty() const{
	return size == 0;
}

int Flower::getLength() const{
	return size;
}

bool Flower::add(string feature){
	FeatureNode* temp = head;
	for (int i = 0; i < getLength(); i++)
	{
		if (temp->feature == feature)
		{
			return false;
		}
		temp = temp->next;
	}
	temp = head;
	FeatureNode* newNode = new FeatureNode();
	newNode->feature = feature;
	FeatureNode* prev = head;
	if (head == NULL)
	{
		newNode->next = head;
		head = newNode;
		size++;
		return true;
	}
	if (head->feature[0] > feature[0])
	{
		newNode->next = temp;
		head = newNode;
		size++;
		return true;
	}
	while (temp != NULL) {
		if (temp->feature[0] > feature[0])
		{
			newNode->next = temp;
			prev->next = newNode;
			size++;
			return true;
		}
		prev = temp;
		temp = temp->next;

	}
	prev->next = newNode;
	newNode->next = NULL;
	size++;
	return true;
}

bool Flower::remove(string feature){
	FeatureNode* temp = head;
	FeatureNode* prevTemp = head;
	for (int i = 0; i < getLength(); i++)
	{

		if (temp->feature == feature)
		{
			if (head->feature == feature)
			{
				temp = head->next;
				delete head;
				head = temp;
				size--;
				return true;
			}

			while (temp->feature != feature) {
				prevTemp = temp;
				temp = temp->next;
			}
			prevTemp->next = temp->next;
			delete temp;
			size--;
			return true;

		}
		temp = temp->next;
	}
	return false;
}

string Flower::printFlower() const{
	return flowerName;
}

void Flower::setName(string name) {
	flowerName = name;
}

string Flower::getName() {
	return flowerName;
}

void Flower::getFeature() {
	FeatureNode* temp = head;
	if (temp == NULL)
	{
		cout << "no features";
		return;
	}
	while(temp != NULL)
	{
		cout << temp->feature << " | ";
		temp = temp->next;
	}
}

bool Flower::checkFeature(string feature) {
	FeatureNode* temp = head;
	for (int i = 0; i < getLength(); i++)
	{
		if (temp->feature == feature)
		{
			return true;
		}
		temp = temp->next;
	}
	return false;
}
