//----------------------------------------------------------------------------//
// Name: Chris Kruki                                                          //
// Student ID: 1132759                                                        //
// Assignment: #4                                                             //
//----------------------------------------------------------------------------//

#include <iostream>
#include <string>
using namespace std;

// Animal Class Definition
class Animal {
public:
	Animal(const string& iName, const string& iFood, const string& iType); // Constructor Prototype
	void display()const; // Base display function - this will be the same in all derived classes so no need to be redefined
	virtual float calcFoodAmt()const = 0; // Pure Virtual Function Prototypes
	virtual float calcVetCost()const = 0;
protected:
	string name, food, type; // Variable Declarations
};

// Animal Constructor definition
Animal::Animal(const string& iName, const string& iFood, const string& iType) : name(iName), food(iFood), type(iType) {}

void Animal::display()const{
	cout << "Name: " << name << endl;
	cout << "Type: " << type << endl;
	cout << "Food: " << food << endl;
}

// Mammal Class Definition - is an animal
class Mammal : public Animal {
public:
	Mammal(const string& iName, const string& iFood, const int& iAge, const float& iWeight); // Constructor Prototype
	virtual float calcFoodAmt()const; // Virtual Function Prototypes
	virtual float calcVetCost()const;
private:
	int age;
	float weight;
};

// Mammal Constructor definition
Mammal::Mammal(const string& iName, const string& iFood, const int& iAge, const float& iWeight) : Animal(iName, iFood, "Mammal"), age(iAge), weight(iWeight) {}

// Mammal calcFoodAmt function definition
float Mammal::calcFoodAmt()const {
	float freq = 0, amt = 0;
	if (age >= 0 && age <= 12) {
		freq = 5 * 7 * 52; // Per Day - 7 Per Week - 52 Per Year
	}
	else if (age >= 13 && age <= 24) {
		freq = 4 * 7 * 52; // Per Day - 7 Per Week - 52 Per Year
	}
	else if (age > 24) {
		freq = 3 * 7 * 52; // Per Day - 7 Per Week - 52 Per Year
	}

	amt = weight * 0.2; // 1 lb for every 5 lbs of weight

	return freq * amt; // Returns Amount of Food * Frequency
}

// Mammal calcVetCost function definition
float Mammal::calcVetCost()const {
	if (age >= 0 && age <= 12) {
		return 200;
	}
	else if (age >= 13 && age <= 96) {
		return 100;
	}
	else if (age > 96) {
		return 500;
	}
	else
		return 0;
}

// Bird Class Definition - is an animal
class Bird : public Animal {
public:
	Bird(const string& iName, const string& iFood, const float& iWeight);
	virtual float calcFoodAmt()const; // Virtual Function Prototypes
	virtual float calcVetCost()const;
protected:
	float weight;
};

// Bird Constructor Definition
Bird::Bird(const string& iName, const string& iFood, const float& iWeight) : Animal(iName, iFood, "Bird"), weight(iWeight) {}

// Bird calcFoodAmt Function Definition
float Bird::calcFoodAmt()const {
	float freq = 0, amt = 0;
	if (weight <= 0.5) {
		freq = 3 * 7 * 52; // Per Day - 7 Per Week - 52 Per Year
	}
	else if (weight > 0.5) {
		freq = 2 * 7 * 52; // Per Day - 7 Per Week - 52 Per Year
	}
	else {
		cerr << "Invalid Weight Entered." << endl;
		exit(1);
	}
	amt = weight * 0.5; // 0.5 lbs for every lb of weight
	return amt * freq;
}

// Bird calcVetCost Function Definition
float Bird::calcVetCost()const {
	if (weight <= 0.5) {
		return 100;
	}
	else if (weight > 0.5) {
		return 250;
	}
	else {
		cerr << "Invalid Weight Entered" << endl;
		exit(1);
	}
}

// Fish Class Definition - is an animal
class Fish : public Animal {
public:
	Fish(const string& iName, const string& iFood, const float& iLength); // Constructor Prototype
	virtual float calcFoodAmt()const;// Virtual Function Prototypes
	virtual float calcVetCost()const;
protected:
	float length;
};

// Fish Constructor Definition
Fish::Fish(const string& iName, const string& iFood, const float& iLength) : Animal(iName, iFood, "Fish"), length(iLength) {}

// Fish calcFoodAmt Function Definition
float Fish::calcFoodAmt()const {
	float freq = 0, amt = 0;
	if (length <= 30) {
		freq = 2 * 7 * 52; // Per Day - 7 Per Week - 52 Per Year
	}
	else if (length > 30) {
		freq = 1 * 7 * 52; // Per Day - 7 Per Week - 52 Per Year
	}
	else {
		cerr << "Invalid Length." << endl;
		exit(1);
	}
	amt = 1.5; // 1.5 lbs at each feeding
	return amt * freq;
}

// Fish calcVetCost Function Definition
float Fish::calcVetCost()const {
	return 0;
}

// Reptile Class Definition - is an animal
class Reptile : public Animal {
public:
	Reptile(const string& iName, const string& iFood); // Constructor Prototype
	virtual float calcFoodAmt()const;// Virtual Function Prototypes
	virtual float calcVetCost()const;
};

// Reptile Constructor Definition
Reptile::Reptile(const string& iName, const string& iFood) : Animal(iName, iFood, "Reptile") {}

// Reptile calcFoodAmt Function Definition
float Reptile::calcFoodAmt()const {
	return 2 * 52 * 1; // 2x Per week - 52 Per Year - 1 lb amount
}

// Reptile calcVetCost Function Definition
float Reptile::calcVetCost()const {
	return 175; // 175 fixed cost
}

// Amphibian Class Definition
class Amphibian : public Animal {
public:
	Amphibian(const string& iName, const string& iFood); // Constructor Prototype
	virtual float calcFoodAmt()const;// Virtual Function Prototypes
	virtual float calcVetCost()const;
};

Amphibian::Amphibian(const string& iName, const string& iFood) : Animal(iName, iFood, "Amphibian") {}
float Amphibian::calcFoodAmt()const {
	return 1 * 7 * 52 * 0.5; // 1x per Day - 7 Perk Week - 52 Per Year - 0.5 lbs flat rate
}

float Amphibian::calcVetCost()const {
	return 0;
}


/*
Arguments for the contructors should be passed in the following order:
Mammal:     name, food, age, weight
Bird:     name, food, weight
Fish:     name, food, weight
Reptile:     name, food
Amphibian:     name, food
*/