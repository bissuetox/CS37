#include <iostream>
using namespace std;

// Base materials class definition
class Materials {
public:
	virtual int calcCost()const = 0; // Pure Virtual Function
};

class byWeight : public Materials {
public:
	byWeight(const int& iWeight);
	virtual int calcCost()const;
protected:
	int weight;
};

byWeight::byWeight(const int& iWeight) : weight(iWeight) {}

int byWeight::calcCost()const {
	return int(.05 * weight);
}

class byVolume : public Materials {
public:
	byVolume(const int& iVolume);
	virtual int calcCost()const;
protected:
	int volume;
};

byVolume::byVolume(const int& iVolume) : volume(iVolume) {}

int byVolume::calcCost()const {
	return int(0.12) * volume;
}

class byQuantity : public Materials {
public:
	byQuantity(const int& iQuantity);
	virtual int calcCost()const;
protected:
	int quantity;
};

byQuantity::byQuantity(const int& iQuantity) : quantity(iQuantity) {}

int byQuantity::calcCost()const {
	if (quantity >= 1 && quantity <= 10) {
		return int(0.11) * quantity;
	}
	else if (quantity < 50 && quantity >= 11) {
		return int(0.09) * quantity;
	}
	else if (quantity >= 51) {
		return int(0.06) * quantity;
	}
	else
		cout << "Invalid Quantity" << endl;
}

int globalCost(Materials* iMaterial);

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

int globalCost(Materials* iMaterial) {
	iMaterial->calcCost();
}