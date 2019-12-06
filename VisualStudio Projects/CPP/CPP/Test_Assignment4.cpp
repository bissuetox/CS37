// Test program to exercise Animal hierarchy

#include <iostream>
#include "Animal.h"

using namespace std;

void displayInfo(Animal& aref);

int main()
{
	Mammal oneM("Fred", "Milk", 25, 100);
	displayInfo(oneM);
	
	Bird oneB("Lapa", "Seed", 1.7);
	displayInfo(oneB);
	
	Fish oneF("Tilapia", "Crickets", 50);
	displayInfo(oneF);
	
	Reptile oneR("Fer de Lance", "Mice");
	displayInfo(oneR);

	Amphibian oneA("Toad", "Mosquitoes");
	displayInfo(oneA);

	return 0;
}

//Display data for a single animal
void displayInfo(Animal& aref)
{
	aref.display();
	cout << "\nFood Amount: " << aref.calcFoodAmt() << endl;
	cout << "Vet Cost: " << aref.calcVetCost() << endl << endl << endl;
}

/*
Name: Fred
Type: Mammal
Food: Milk

Food Amount: 21900.0 lbs
Vet Cost: 100.00


Name: Lapa
Type: Bird
Food: Seed

Food Amount: 620.5 lbs
Vet Cost: 250.00


Name: Tilapia
Type: Fish
Food: Crickets

Food Amount: 547.5 lbs
Vet Cost: 0.00


Name: Fer de Lance
Type: Reptile
Food: Mice

Food Amount: 104.0 lbs
Vet Cost: 175.00


Name: Toad
Type: Amphibian
Food: Mosquitoes

Food Amount: 182.5 lbs
Vet Cost: 0.00
*/