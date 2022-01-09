//Izaan Aamir
//22001488
#include "Flower.h"
#include <string>
#include "FlowerList.h"
#include "FlowerLibrary.h"
#include <cctype>
#include <iostream>
using namespace std;

FlowerLibrary::FlowerLibrary(){
	size = 0;
}
FlowerLibrary::~FlowerLibrary() {}
void FlowerLibrary::addFlower(string name) {
	int i = 0;
	string flowerName = "";
	char lowerName;
	while(name[i])
	{
		lowerName = tolower( name[i]);
		flowerName = flowerName + lowerName ;
		i++;
	}
	if (flowers.find(flowerName))
	{
		cout << flowerName << " cannot be added into the library because it already exists." << endl;
		return;
	}
	flowers.add(flowerName);
	cout << flowerName << " has been added into the library." << endl;
}
void FlowerLibrary::removeFlower(string name) {
	int i = 0;
	string flowerName = "";
	char lowerName;
	while (name[i])
	{
		lowerName = tolower(name[i]);
		flowerName = flowerName + lowerName;
		i++;
	}
	if (!flowers.find(flowerName))
	{
		cout << flowerName << " cannot be removed because it's not in the library." << endl;
		return;
	}
	flowers.remove(flowerName);
	cout << flowerName << " has been removed from the library." << endl;


}
void FlowerLibrary::listFlowers() const{

	flowers.printFlowerlist();
}
void FlowerLibrary::listFeatures(string name) const {
	int i = 0;
	string flowerName = "";
	char lowerName;
	while (name[i])
	{
		lowerName = tolower(name[i]);
		flowerName = flowerName + lowerName;
		i++;
	}

	if (!flowers.find(flowerName))
	{
		cout << flowerName << " isn't found in the library." << endl;
		return;
	}
	flowers.printFlowerFeatures(flowerName);
}
void FlowerLibrary::addFeature(string name, string feature){
	int i = 0;
	string flowerName = "";
	char lowerName;
	while (name[i])
	{
		lowerName = tolower(name[i]);
		flowerName = flowerName + lowerName;
		i++;
	}
	int j = 0;
	string featureName = "";
	char lowerFeatureName;
	while (feature[j])
	{
		lowerFeatureName = tolower(feature[j]);
		featureName = featureName + lowerFeatureName;
		j++;
	}

	if (!flowers.find(flowerName))
	{
		cout << flowerName << " is not in the library." << endl;
		return;
	}
	flowers.addFeature(featureName, flowerName);
}
void FlowerLibrary::removeFeature(string name, string feature){
	int i = 0;
	string flowerName = "";
	char lowerName;
	while (name[i])
	{
		lowerName = tolower(name[i]);
		flowerName = flowerName + lowerName;
		i++;
	}
	int j = 0;
	string featureName = "";
	char lowerFeatureName;
	while (feature[j])
	{
		lowerFeatureName = tolower(feature[j]);
		featureName = featureName + lowerFeatureName;
		j++;
	}

	if (!flowers.find(flowerName))
	{
		cout << flowerName << " is not in the library." << endl;
		return;
	}
	flowers.removeFeature(featureName, flowerName);
}
void FlowerLibrary::findFlowers(string feature) const{
	int j = 0;
	string featureName = "";
	char lowerFeatureName;
	while (feature[j])
	{
		lowerFeatureName = tolower(feature[j]);
		featureName = featureName + lowerFeatureName;
		j++;
	}

	cout << flowers.findFlowerFeatures(featureName) << endl;;
}