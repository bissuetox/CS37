#include <iostream>
using namespace std;

// Base materials class definition
class Materials {
public:
	virtual double calcCost()const = 0; // Pure Virtual Function - calculate cost
	virtual double getDeliveryCost()const = 0; // Pure Virtual Function - delivery cost
};

// By Weight Class Definition
class byWeight : public Materials {
public:
	byWeight(const double& iWeight);
	virtual double calcCost()const;
	virtual double getDeliveryCost()const;
protected:
	double weight;
};

// Construtor definition
byWeight::byWeight(const double& iWeight) : weight(iWeight) {}

// byWeight calcCost function definition
double byWeight::calcCost()const {
	return .05 * weight;
}

// byWeight Delivery Cost Function definition
double byWeight::getDeliveryCost()const {
	double count = 0, tempWeight = weight;
	while (tempWeight > 0) {
		count++;
		tempWeight -= 1000;
	}
	return 100 + 10 * count;
}

// By Volume Class Definition - Is a Material
class byVolume : public Materials {
public:
	byVolume(const double& iVolume);
	virtual double calcCost()const;
	virtual double getDeliveryCost()const;
protected:
	double volume;
};

// Constructor Definition
byVolume::byVolume(const double& iVolume) : volume(iVolume) {}

// byVolume calcCost function definition
double byVolume::calcCost()const {
	return 0.12 * volume;
}

// byVolume Delivery Cost function Definition
double byVolume::getDeliveryCost()const {
	double count = 0, tempVolume = volume;
	while (tempVolume > 0) {
		count++;
		tempVolume -= 750;
	}
	return 50 + 8 * count;
}

// By Quantity Class Definition - Is a Material
class byQuantity : public Materials {
public:
	byQuantity(const double& iQuantity);
	virtual double calcCost()const;
	virtual double getDeliveryCost()const;
protected:
	double quantity;
};

// Constructor Definition
byQuantity::byQuantity(const double& iQuantity) : quantity(iQuantity) {}


// byQuantity calcCost function definition
double byQuantity::calcCost()const {
	
	if (quantity >= 1 && quantity <= 10) {
		return 0.11 * quantity;
	}
	else if (quantity < 50 && quantity >= 11) {
		return 0.09 * quantity;
	}
	else if (quantity >= 51) {
		return 0.06 * quantity;
	}
	else
		cout << "Invalid Quantity" << endl;
		
}

// byQuantity Delivery Cost function definition
 double byQuantity::getDeliveryCost()const {
	 return 50;
}

// polymorphism global function prototypes
double globalCost(Materials* iMaterial);
double globalDelivery(Materials* iMaterial);

// Main Function
int main() {

	// Class object instantiation
	byWeight item1(2345);
	byVolume item2(6550);
	byQuantity item3(343);

	// Polymorphism pointer instantiations
	Materials* item1Ptr = &item1;
	Materials* item2Ptr = &item2;
	Materials* item3Ptr = &item3;

	// Print statements
	cout << "By Weight Cost: " << globalCost(item1Ptr) << endl;
	cout << "By Volume Cost: " << globalCost(item2Ptr) << endl;
	cout << "By Quantity Cost: " << globalCost(item3Ptr) << endl;
	cout << endl;
	cout << "By Weight Delivery Cost: " << globalDelivery(item1Ptr) << endl;
	cout << "By Volume Delivery Cost: " << globalDelivery(item2Ptr) << endl;
	cout << "By Quantity Delivery Cost: " << globalDelivery(item3Ptr) << endl;
	return 0;
}

// polymorphism cost function definition
double globalCost(Materials* iMaterial) {
	return iMaterial->calcCost();
}

// Polymorphism delivery function definition
double globalDelivery(Materials* iMaterial) {
	return iMaterial->getDeliveryCost();
}