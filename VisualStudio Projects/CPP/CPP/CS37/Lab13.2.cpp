#include <iostream>
using namespace std;

// Base materials class definition
class Materials {
public:
	virtual double calcCost()const = 0; // Pure Virtual Function
};

class byWeight : public Materials {
public:
	byWeight(const double& iWeight);
	virtual double calcCost()const;
protected:
	double weight;
};

byWeight::byWeight(const double& iWeight) : weight(iWeight) {}

double byWeight::calcCost()const {
	return .05 * weight;
}

class byVolume : public Materials {
public:
	byVolume(const double& iVolume);
	virtual double calcCost()const;
protected:
	double volume;
};

byVolume::byVolume(const double& iVolume) : volume(iVolume) {}

double byVolume::calcCost()const {
	return 0.12 * volume;
}

class byQuantity : public Materials {
public:
	byQuantity(const double& iQuantity);
	virtual double calcCost()const;
protected:
	double quantity;
};

byQuantity::byQuantity(const double& iQuantity) : quantity(iQuantity) {}

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

double globalCost(Materials* iMaterial);

int main() {

	byWeight item1(2345);
	byVolume item2(6550);
	byQuantity item3(343);
	Materials* item1Ptr = &item1;
	Materials* item2Ptr = &item2;
	Materials* item3Ptr = &item3;

	cout << "By Weight: " << globalCost(item1Ptr) << endl;
	cout << "By Volume: " << globalCost(item2Ptr) << endl;
	cout << "By Quantity: " << globalCost(item3Ptr) << endl;
	return 0;
}

double globalCost(Materials* iMaterial) {
	return iMaterial->calcCost();

}