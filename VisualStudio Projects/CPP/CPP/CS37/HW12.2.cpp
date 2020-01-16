#include <iostream>
#include <iomanip>
using namespace std;

// Base Insurance class definition
class Insurance {
public:
	Insurance(const int& iValue);
	virtual float calcPremium()const = 0; // = 0 means this is an abstract class
	virtual float calcComission()const = 0; // Polymorphism functions
protected:
	int value;
};


// Home Insurance class definition
class HomeInsurance : public Insurance {
public:
	HomeInsurance(const int& iValue);
	virtual float calcPremium()const;
	virtual float calcComission()const; // Polymorphism functions
	
};

// Home Insurance member function defintiions
HomeInsurance::HomeInsurance(const int& iValue) : Insurance(iValue) {}
float HomeInsurance::calcPremium()const {
	return value * .005; // 0.5% per prompt
}

float HomeInsurance::calcComission()const {
	return value * .002; // 0.2% 
}

// Life Insurance class definition
class LifeInsurance : public Insurance {
public:
	LifeInsurance(const int& iValue);
	virtual float calcPremium()const;
	virtual float calcComission()const; // Polymorphism functions
};

// Life Insurance Member Function definitions
LifeInsurance::LifeInsurance(const int& iValue) : Insurance(iValue) {}

float LifeInsurance::calcPremium()const {
	return value * .01; // 1%
}

float LifeInsurance::calcComission()const {
	return value * .01; // 1%
}

// Vehicle Insurance class definition
class VehicleInsurance : public Insurance {
public:
	VehicleInsurance(const int& iValue);
	virtual float calcPremium()const;
	virtual float calcComission()const; // Polymorphism functions
};

// Vehicle Insurance member function definitions
VehicleInsurance::VehicleInsurance(const int& iValue) : Insurance(iValue) {}

float VehicleInsurance::calcPremium()const {
	return value * .05; // 0.5%
}

float VehicleInsurance::calcComission()const {
	return value * .005; // 0.5%
}

// Global Polymorphism Function prototypes

float getPremium(Insurance* fInsurance);
float getComission(Insurance* fInsurance);

int main() {
	HomeInsurance home1(457999.00);
	LifeInsurance life1(1000000.00);
	VehicleInsurance vehicle1(25000);
	Insurance* home1Ptr = &home1;
	Insurance* life1Ptr = &life1;
	Insurance* vehicle1Ptr = &vehicle1;

	cout << "Home Insurance" << endl;
	cout << "Premium: $" << fixed << setprecision(2) << getPremium(home1Ptr) << endl;
	cout << "Commission: $" << getComission(home1Ptr) << endl << endl;

	cout << "Life Insurance" << endl;
	cout << "Premium: $" << getPremium(life1Ptr) << endl;
	cout << "Commission: $" << getComission(life1Ptr) << endl << endl;

	cout << "Vehicle Insurance" << endl;
	cout << "Premium: $" << getPremium(vehicle1Ptr) << endl;
	cout << "Commission: $" << getComission(vehicle1Ptr) << endl << endl;


}

float getPremium(Insurance* fInsurance) {
	return fInsurance->calcPremium();
}
float getComission(Insurance* fInsurance) {
	return fInsurance->calcComission();
}