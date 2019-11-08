#include <iostream>
#include <string>

// Asset class definition - Base class
class Asset {
public:
	// Parameterized Constructor prototype
	Asset(const std::string& iManufacturer, const std::string iDate, const float& iCost);
	// Getter prototypes
	std::string getManufacturer()const;
	std::string getDate()const;
	float getCost()const;
protected:
	std::string manufacturer, date;
	float cost;
};

// Constructor definition
Asset::Asset(const std::string& iManufacturer, const std::string iDate, const float& iCost) : manufacturer(iManufacturer), date(iDate), cost(iCost) {}
// Getter Definitions
std::string Asset::getManufacturer()const {
	return manufacturer;
}
std::string Asset::getDate()const {
	return date;
}
float Asset::getCost()const {
	return cost;
}

// Hardware Class definition - Inherits Asset class
class Hardware : public Asset {
public:
	// Parameterized Constructor prototype
	Hardware(const std::string& iManufacturer, const std::string iDate, const float& iCost, const std::string& iModel);
	// Getter prototype
	std::string getModel()const;
protected:
	std::string model;
};

// Constructor Defintiion
Hardware::Hardware(const std::string& iManufacturer, const std::string iDate, const float& iCost, const std::string& iModel) : Asset(iManufacturer, iDate, iCost), model(iModel) {}
// Getter definition
std::string Hardware::getModel()const {
	return model;
}

// Software class definition - inherits Asset class
class Software : public Asset {
public:
	Software(const std::string& iManufacturer, const std::string iDate, const float& iCost, const std::string& iTitle);
	std::string getTitle()const;
private:
	std::string title;
};

// Software Class definition - Inherits 
Software::Software(const std::string& iManufacturer, const std::string iDate, const float& iCost, const std::string& iTitle) : Asset(iManufacturer, iDate, iCost), title(iTitle) {}
std::string Software::getTitle()const {
	return title;
}

// Furniture Class definition
class Furniture : public Asset {
public:
	// Parameterized Constructor prototype
	Furniture(const std::string& iManufacturer, const std::string iDate, const float& iCost, const std::string iSKU);
	// Getter prototype
	std::string getSKU()const;
private:
	std::string SKU;
};

// Constructor definition
Furniture::Furniture(const std::string& iManufacturer, const std::string iDate, const float& iCost, const std::string iSKU) : Asset(iManufacturer, iDate, iCost), SKU(iSKU) {}
// Getter definition
std::string Furniture::getSKU()const {
	return SKU;
}

// Chair Class definition
class Chair : public Furniture {
public:
	// Parameterized Constructor prototype
	Chair(const std::string& iManufacturer, const std::string iDate, const float& iCost, const std::string& iSKU, const std::string& iMaterial);
	// Getter prototype
	std::string getMaterial()const;
private:
	std::string material;
};

// Constructor defintion
Chair::Chair(const std::string& iManufacturer, const std::string iDate, const float& iCost, const std::string& iMaterial, const std::string& iSKU) : Furniture(iManufacturer, iDate, iCost, iSKU), material(iMaterial) {}
// Getter definition
std::string Chair::getMaterial()const {
	return material;
}

// Laptop Class definition
class Laptop : public Hardware {
public:
	// Parameterized Constructor definition
	Laptop(const std::string& iManufacturer, const std::string iDate, const float& iCost, const std::string& iModel, const float& iScreensize);
	// Getter prototype
	float getScreensize()const;
private:
	float screensize;
};

// Constructor definition
Laptop::Laptop(const std::string& iManufacturer, const std::string iDate, const float& iCost, const std::string& iModel, const float& iScreensize) : Hardware(iManufacturer, iDate, iCost, iModel), screensize(iScreensize) {}
// Getter definition
float Laptop::getScreensize()const {
	return screensize;
}