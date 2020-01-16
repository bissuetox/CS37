#include <iostream>
#include <iomanip>
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

 // Sand class definition - is sold by weight
 class Sand : public byWeight {
 public:
	 virtual double calcCost()const;
	 Sand(const double& iWeight);
 };

 // Constructor definition
 Sand::Sand(const double& iWeight) : byWeight(iWeight) {}

 // Sand calcCost function definition - 10% discount if weight is over 2000 lbs
 double Sand::calcCost()const {
	 double tempCost = weight * .05;
	 if (weight > 2000) {
		 return tempCost * .9;
	 }
	 else
		 return tempCost;
 }

 // WoodChips class definition - is sold by volume
 class WoodChips : public byVolume {
 public:
	 virtual double calcCost()const;
	 WoodChips(const double& iVolume);
 };


 // WoodChips constructor Definition
 WoodChips::WoodChips(const double& iVolume) : byVolume(iVolume) {}

 // Wood Chips calcCost function definition
 double WoodChips::calcCost()const {
	 double fVolume = volume, count = 0, fCost = volume * .12;
	 if (volume > 1000) {
		 while (fVolume > 500) {
			 count += 1;
			 fVolume -= 500;
		 }
		 return fCost - count;
	 }
	 else {
		 return fCost;
	 }
 }

// polymorphism global function prototypes
double globalCost(Materials* iMaterial);
double globalDelivery(Materials* iMaterial);

// Main Function
int main() {

	// Class Object instantiation
	Sand sand1(18550);
	WoodChips woodchips1(4300);

	// Polymorphism Pointer Object Instantiation
	byWeight* sand1Ptr = &sand1;
	byVolume* woodchips1Ptr = &woodchips1;

	// Printing Info
	cout << "Sand Cost: $" << fixed << setprecision(2) << globalCost(sand1Ptr) << endl;
	cout << "Sand Delivery Cost: $" << globalDelivery(sand1Ptr) << endl;
	cout << "Wood Chips Cost: $" << globalCost(woodchips1Ptr) << endl;
	cout << "Wood Chips Delivery Cost: $" << globalDelivery(woodchips1Ptr) << endl;
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