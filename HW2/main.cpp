#include <iostream>
using namespace std;
#include "FlowerLibrary.h"
#include "FlowerList.h"

int main() {
	FlowerLibrary L;
	// Testing add flower
	L.listFlowers();
	cout << "Testing add flower" << endl;
	cout << endl;
	L.addFlower("Magnolia");
	L.addFlower("SCARLET PIMPERNEL");
	L.addFlower("verbascum");
	cout << endl;
	L.addFlower("Magnolia");
	L.addFlower("magnolia");
	L.addFlower("Lily");
	L.addFlower("White Lily");
	cout << endl;
	L.listFlowers();
	cout << endl;
	// Testing remove flower
	cout << endl;
	cout << "Testing remove flower" << endl;
	cout << endl;
	L.removeFlower("Magnolia");
	L.removeFlower("lantana");
	cout << endl;
	L.removeFlower("LANTANA");
	L.removeFlower("VERBASCUM");
	L.removeFlower("oleander");
	cout << endl;
	L.addFlower("verbascum");
	cout << endl;
	L.listFlowers();
	cout << endl;
	// Testing add feature
	cout << endl;
	cout << "Testing add feature" << endl;
	cout << endl;
	L.addFlower("calla lilly");
	cout << endl;
	L.listFeatures("magnolia");
	cout << endl;
	L.addFeature("verbascum", "yellow");
	L.addFeature("verbascum", "biennial");
	L.addFeature("verbascum", "Perennial");
	L.addFeature("calla lilly", "ornamental");
	cout << endl;
	L.addFeature("calla lilly", "ornamental");
	L.addFeature("Magnolia", "ornamental");
	cout << endl;
	L.addFlower("magnolia");
	L.addFeature("Magnolia", "ornamental");
	L.addFeature("Magnolia", "citronella scented");
	L.listFeatures("magnolia");
	cout << endl;
	L.listFeatures("calla lilly");
	cout << endl;
	// Testing remove feature
	cout << endl;
	cout << "Testing remove feature" << endl;
	cout << endl;
	L.removeFeature("magnolia", "citronella scented");
	L.removeFeature("magnolia", "yellow");
	L.listFeatures("magnolia");
	// Testing finding flowers
	cout << endl;
	cout << "Testing finding flowers" << endl;
	cout << endl;
	L.findFlowers("ornamental");
	L.findFlowers("yellow");
	cout << endl;
	L.findFlowers("white");
	L.listFlowers();
	L.removeFlower("verbasCum");
	L.listFlowers();
	L.listFeatures("verbasCum");
	return 0;
}