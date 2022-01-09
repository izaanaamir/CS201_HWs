//Izaan Aamir
//22001488
#include "Flower.h"
#include <string>
#include "FlowerList.h"
#include "Flower.h"
#include <iostream>
using namespace std;


FlowerList::FlowerList(){
	size = 0;
	head = NULL;
}
FlowerList::FlowerList(const FlowerList& aList){
	size = 0;
	if (aList.head == NULL) {
		head = NULL;
	}
	else {
		head = new FlowerNode;
		head->f = aList.head->f;
		FlowerNode* tempPtr = head;
		for (FlowerNode* orPtr = aList.head->next; orPtr != NULL; orPtr = orPtr->next)
		{
			tempPtr->next = new FlowerNode;
			tempPtr = tempPtr->next;
			tempPtr->f = orPtr->f;

		}
		tempPtr->next = NULL;
	}
}
FlowerList::~FlowerList(){
	FlowerNode* temp = head;
	while (head != NULL)
	{
		temp = head->next;
		delete head;
		head = temp;
	}

}
bool FlowerList::isEmpty() const { 
	return size == 0;
}
int FlowerList::getLength() const {
	return size;
}
bool FlowerList::retrieve(string flowerName, Flower& flower) const { 
	FlowerNode* temp = head;
	while (temp != NULL) {
		cout << temp->f.getName() << endl;
		if (temp->f.getName() == flowerName) {
			flower = temp->f;
			return true;
		}
		temp = temp->next;
	}
	return false;

}
bool FlowerList::add(string flowerName) { 
	FlowerNode* newNode = new FlowerNode();
	newNode->f.setName(flowerName);
	newNode->f = flowerName;
	FlowerNode* temp = head;
	FlowerNode* prev = head;
	if (head == NULL)
	{
		newNode->next = head;
		head = newNode;
		size++;
		return true;
	}
	if (head->f.getName()[0] > flowerName[0])
	{
		newNode->next = temp;
		head = newNode;
		size++;
		return true; 
	}
	while (temp != NULL) {
		if (temp->f.getName()[0] > flowerName[0])
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

bool FlowerList::remove(string flowerName) { 
	FlowerNode* temp = head;
	FlowerNode* prevTemp = head;

	if (head->f.getName() == flowerName)
	{
		temp = head->next;
		delete head;
		head = temp;
		size--;
		return true;
	}

	while (temp->f.getName() != flowerName) {
		prevTemp = temp;
		temp = temp->next;
	}
	prevTemp->next = temp->next;
	delete temp;
	size--;
	return true;
}

bool FlowerList::find(string flowerName) const{
	FlowerNode* temp = head;
	while (temp != NULL) {
		if (temp->f.getName() == flowerName) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}

void FlowerList::printFlowerlist() const{
	FlowerNode* temp = head;
	if (temp == NULL)
	{
		cout << "Library is empty." << endl;
	}
	while (temp != NULL) {
		cout << temp->f.printFlower() <<" : ";
		temp->f.getFeature();
		cout << endl;
		temp = temp->next;
	}
}

void FlowerList::removeFeature(string feature, string name) {
	FlowerNode* temp = head;
	for (int i = 0; i < getLength(); i++)
	{
		if (temp->f.getName() == name)
		{
			if (temp->f.remove(feature))
			{
				cout << feature << " is removed from " << name << endl;
				return;
			}
			else {
				cout << feature << " doesn't exist in " << name << endl;
				return;
			}

		}
		temp = temp->next;
	}
}

void FlowerList::addFeature(string feature, string name) {
	FlowerNode* temp = head;
	for (int i = 0; i < getLength(); i++)
	{
		if (temp->f.getName() == name)
		{
			if (temp->f.add(feature))
			{
				cout << feature << " is added into " << name << endl;
				return;
			}
			else {
				cout << feature << " already exists in " << name << endl;
				return;
			}

		}
		temp = temp->next;
	}

}

void FlowerList::printFlowerFeatures(string name) const{
	FlowerNode* temp = head;
	while (temp->f.getName() != name) {
		temp = temp->next;
	}
	cout << name << " : ";
	temp->f.getFeature();
}

string FlowerList::findFlowerFeatures(string features) const{
	FlowerNode* temp = head;
	string str = features + " flowers: ";
	bool status = false;
	for (int i = 0; i < getLength(); i++)
	{
			if (temp->f.checkFeature(features))
			{
				str = str + temp->f.getName() + "| ";
				status = true;
			}
			temp = temp->next;
	}
	if (status)
	{
		return str;
	}
	else {
		return features + " flowers: there is no such flower";
	}
}




