#include <string>
#include <iostream>
using namespace std;

// Manufacturer class definition
class Manufacturer {
public:
	Manufacturer(const string& fName);
	string getName()const;
private:
	string name;
};

// Manufacturer class function definitions
Manufacturer::Manufacturer(const string& fName) : name(fName) {}
string Manufacturer::getName()const {
	return name;
}

// Electronics Class defintion - Base class
class Electronics {
public:
	Manufacturer manufacturer; // Has a manufacturer
	Electronics(const float& fPrice, const int& fWarranty, const string& fManufacturer);
	float getPrice()const;
	int getWarranty()const;
	string getName()const;

protected:
	float price;
	int warranty;
};

// Electronics class function defintiions
Electronics::Electronics(const float& fPrice, const int& fWarranty, const string& fManufacturer) :
	price(fPrice), warranty(fWarranty), manufacturer(fManufacturer){}
float Electronics::getPrice()const {
	return price;
}

int Electronics::getWarranty()const {
	return warranty;
}
string Electronics::getName()const {
	return manufacturer.getName();
}

// TV class definition - is an Electronic
class TV : public Electronics {
public:
	TV(const float& fPrice, const int& fWarranty, const string& fManufacturer, const float& fDisplaySize);
	float getDisplaySize()const;
private:
	float displaySize;
};

// TV Class function definitions
TV::TV(const float& fPrice, const int& fWarranty, const string& fManufacturer, const float& fDisplaySize) :
	Electronics(fPrice, fWarranty, fManufacturer), displaySize(fDisplaySize) {}
float TV::getDisplaySize()const {
	return displaySize;
}

// Computer class definition - Is an Electronic
class Computer : public Electronics {
public:
	Computer(const float& fPrice, const int& fWarranty, const string& fManufacturer, const float& fCPUSpeed);
	float getCPUSpeed()const;
private:
	float CPUSpeed;
};

// Computer class function definitions
Computer::Computer(const float& fPrice, const int& fWarranty, const string& fManufacturer, const float& fCPUSpeed) :
	Electronics(fPrice, fWarranty, fManufacturer), CPUSpeed(fCPUSpeed) {}
float Computer::getCPUSpeed()const {
	return CPUSpeed;
}

// Hair Dryer class definition - Is an Electronic
class HairDryer : public Electronics {
public:
	HairDryer(const float& fPrice, const int& fWarranty, const string& fManufacturer, const int& fWatts);
	int getWatts()const;
private:
	int watts;
};

// Hair Dryer class function definitions
HairDryer::HairDryer(const float& fPrice, const int& fWarranty, const string& fManufacturer, const int& fWatts) :
	Electronics(fPrice, fWarranty, fManufacturer), watts(fWatts) {}
int HairDryer::getWatts()const {
	return watts;
}

int main() {
	TV samsung(1199.99, 5, "Samsung", 80);
	cout << "TV:" << endl;
	cout << "Price: " << samsung.getPrice() << endl;
	cout << "Warranty (years): " << samsung.getWarranty() << endl;
	cout << "Manufacturer: " << samsung.getName() << endl;
	cout << "Screen Size: " << samsung.getDisplaySize() << endl;
}