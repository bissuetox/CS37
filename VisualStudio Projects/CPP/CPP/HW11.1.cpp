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

// Hardware Class definition - Is an Asset
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

// Software class definition - Is an Asset
class Software : public Asset {
public:
	Software(const std::string& iManufacturer, const std::string iDate, const float& iCost, const std::string& iTitle);
	std::string getTitle()const;
private:
	std::string title;
};

// Software Class definition - Is an Asset 
Software::Software(const std::string& iManufacturer, const std::string iDate, const float& iCost, const std::string& iTitle) : Asset(iManufacturer, iDate, iCost), title(iTitle) {}
std::string Software::getTitle()const {
	return title;
}

// Computer Class Definition - Is Hardware
class Computer : public Hardware {
public:
	Computer(const std::string& iManufacturer, const std::string iDate, const float& iCost, const std::string& iModel, const std::string& iOS);
	std::string getOS()const;
protected:
	std::string OS;
};

// Laptop Class Function Definitions
Computer::Computer(const std::string& iManufacturer, const std::string iDate, const float& iCost, const std::string& iModel, const std::string& iOS) :
	Hardware(iManufacturer, iDate, iCost, iModel), OS(iOS) {}
std::string Computer::getOS()const {
	return OS;
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

// Chair Class definition - Is Furniture
class Chair : public Furniture {
public:
	Chair(const std::string& iManufacturer, const std::string iDate, const float& iCost, const std::string iSKU, const int& iOfficeNum);
	int getOfficeNum()const;
private:
	int officeNum;
};

// Chair Class Function Definitions
Chair::Chair(const std::string& iManufacturer, const std::string iDate, const float& iCost, const std::string iSKU, const int& iOfficeNum) :
	Furniture(iManufacturer, iDate, iCost, iSKU), officeNum(iOfficeNum) {}
int Chair::getOfficeNum()const {
	return officeNum;
}

// Laptop Class definition - Is a computer
class Laptop : public Computer {
public:
	// Parameterized Constructor definition
	Laptop(const std::string& iManufacturer, const std::string iDate, const float& iCost, const std::string& iModel, const std::string& iO, const float& iScreensize);
	// Getter prototype
	float getScreensize()const;
private:
	float screensize;
};

// Constructor definition
Laptop::Laptop(const std::string& iManufacturer, const std::string iDate, const float& iCost, const std::string& iModel, const std::string& iOS, const float& iScreensize) :
	Computer(iManufacturer, iDate, iCost, iOS, iModel), screensize(iScreensize) {}
// Getter definition
float Laptop::getScreensize()const {
	return screensize;
}

// Server Class Definition - Is a computer
class Server : public Computer {
public:
	Server(const std::string& iManufacturer, const std::string iDate, const float& iCost, const std::string& iModel, const std::string& iOS, const int iMemory);
	int getRAM()const;
private:
	int memory;
};

// Server Function Definitions
Server::Server(const std::string& iManufacturer, const std::string iDate, const float& iCost, const std::string& iModel, const std::string& iOS, const int iMemory) :
	Computer(iManufacturer, iDate, iCost, iModel, iOS), memory(iMemory) {}
int Server::getRAM()const {
	return memory;
}

// Printer Class Definition
class Printer : public Hardware {
public:
	Printer(const std::string& iManufacturer, const std::string iDate, const float& iCost, const std::string& iModel, const int& iTraySize);
	int getTraySize()const;
private:
	int traySize;
};

// Printer Class Function Defintions
Printer::Printer(const std::string& iManufacturer, const std::string iDate, const float& iCost, const std::string& iModel, const int& iTraySize) :
	Hardware(iManufacturer, iDate, iCost, iModel), traySize(iTraySize) {}
int Printer::getTraySize()const {
	return traySize;
}

// Cubicle Class Definition - Is Furniture
class Cubicle : public Furniture {
public:
	Cubicle(const std::string& iManufacturer, const std::string iDate, const float& iCost, const std::string iSKU, const float& length, const float& width);
	float getLength()const;
	float getWidth()const;
	float getArea()const;
private:
	float length, width, area;
};

// Cubicle Class Function Definitions
Cubicle::Cubicle(const std::string& iManufacturer, const std::string iDate, const float& iCost, const std::string iSKU, const float& iLength, const float& iWidth) :
	Furniture(iManufacturer, iDate, iCost, iSKU), length(iLength), width(iWidth), area(iLength* iWidth) {}
float Cubicle::getLength()const {
	return length;
}
float Cubicle::getWidth()const {
	return width;
}
float Cubicle::getArea()const {
	return area;
}

int main() {
	Cubicle cubicle1("Meow Industries", "Oct 10, 2019", 650, "ST-133-25", 5, 7);
	Laptop laptop1("Razer", "August 1, 2018", 1200, "Stealth 2.0", "Windows", 29.5);

	std::cout <<  "\tCubicle:" << std::endl;
	std::cout << "Manufacturer: " << cubicle1.getManufacturer() << std::endl;
	std::cout << "Date: " << cubicle1.getDate() << std::endl;
	std::cout << "Cost: " << cubicle1.getCost() << std::endl;
	std::cout << "SKU: " << cubicle1.getSKU() << std::endl;
	std::cout << "Area: " << cubicle1.getArea() << std::endl;

	std::cout << std::endl << "\tLaptop:" << std::endl;
	std::cout << "Manufacturer: " << laptop1.getManufacturer() << std::endl;
	std::cout << "Date: " << laptop1.getDate() << std::endl;
	std::cout << "Cost: " << laptop1.getCost() << std::endl;
	std::cout << "Model: " << laptop1.getModel() << std::endl;
	std::cout << "Operator System:: " << laptop1.getOS() << std::endl;
	std::cout << "Screen Size: " << laptop1.getScreensize() << std::endl;
}