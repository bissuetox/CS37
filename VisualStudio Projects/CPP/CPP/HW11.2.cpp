#include <iostream>
#include <string>
using namespace std;

// Manufacturer Class Definition
class Manufacturer {
public:
	Manufacturer(const string& iManufacturer);
	string getManufacturer()const;
private:
	string manufacturer;
};

// Manufacturer Class Function Definitions
Manufacturer::Manufacturer(const string& iManufacturer) : manufacturer(iManufacturer) {}
string Manufacturer::getManufacturer()const {
	return manufacturer;
}
// Date Class Definition
class Date {
public:
	friend ostream& operator<<(ostream& output, Date iDate);
	Date(string sDate);
	string getDay()const;
	string getMonth()const;
	string getYear()const;
private:
	string day, month, year;
};

// Operator << overloaded for Date Class
ostream& operator<<(ostream& output, Date iDate) {
	output << iDate.day << "/" << iDate.month << "/" << iDate.year;
	return output;
}

//  Date Class Function Definitions
Date::Date(string sDate) {
	day = (sDate.substr(0, 2));
	month = (sDate.substr(3,2));
	year = (sDate.substr(6,2));
}
string Date::getDay()const {
	return day;
}
string Date::getMonth()const {
	return month;
}
string Date::getYear()const {
	return year;
}


// Asset class definition - Base class
class Asset {
public:
	// Parameterized Constructor prototype
	Asset(const string& iManufacturer, const string iDate, const float& iCost);
	// Getter prototypes
	string getManufacturer()const;
	Date getDate()const;
	float getCost()const;
protected:
	Date date; // Has a Date
	Manufacturer manufacturer; // Has a Manufacturer
	float cost;
};

// Constructor definition
Asset::Asset(const string& iManufacturer, const string iDate, const float& iCost) : manufacturer(iManufacturer), date(iDate), cost(iCost) {}
// Getter Definitions
string Asset::getManufacturer()const {
	return manufacturer.getManufacturer();
}
Date Asset::getDate()const {
	return date;
}
float Asset::getCost()const {
	return cost;
}


// Hardware Class definition - Is an Asset
class Hardware : public Asset {
public:
	// Parameterized Constructor prototype
	Hardware(const string& iManufacturer, const string iDate, const float& iCost, const string& iModel);
	// Getter prototype
	string getModel()const;
protected:
	string model;
};

// Constructor Defintiion
Hardware::Hardware(const string& iManufacturer, const string iDate, const float& iCost, const string& iModel) : Asset(iManufacturer, iDate, iCost), model(iModel) {}
// Getter definition
string Hardware::getModel()const {
	return model;
}

// Software class definition - Is an Asset
class Software : public Asset {
public:
	Software(const string& iManufacturer, const string iDate, const float& iCost, const string& iTitle);
	string getTitle()const;
private:
	string title;
};

// Software Class definition - Is an Asset 
Software::Software(const string& iManufacturer, const string iDate, const float& iCost, const string& iTitle) : Asset(iManufacturer, iDate, iCost), title(iTitle) {}
string Software::getTitle()const {
	return title;
}

// Computer Class Definition - Is Hardware
class Computer : public Hardware {
public:
	Computer(const string& iManufacturer, const string iDate, const float& iCost, const string& iModel, const string& iOS);
	string getOS()const;
protected:
	string OS;
};

// Laptop Class Function Definitions
Computer::Computer(const string& iManufacturer, const string iDate, const float& iCost, const string& iModel, const string& iOS) :
	Hardware(iManufacturer, iDate, iCost, iModel), OS(iOS) {}
string Computer::getOS()const {
	return OS;
}
// Furniture Class definition
class Furniture : public Asset {
public:
	// Parameterized Constructor prototype
	Furniture(const string& iManufacturer, const string iDate, const float& iCost, const string iSKU);
	// Getter prototype
	string getSKU()const;
private:
	string SKU;
};

// Constructor definition
Furniture::Furniture(const string& iManufacturer, const string iDate, const float& iCost, const string iSKU) : Asset(iManufacturer, iDate, iCost), SKU(iSKU) {}
// Getter definition
string Furniture::getSKU()const {
	return SKU;
}

// Chair Class definition - Is Furniture
class Chair : public Furniture {
public:
	friend ostream& operator<<(ostream& output, Chair iChair);
	Chair(const string& iManufacturer, const string iDate, const float& iCost, const string iSKU, const int& iOfficeNum);
	int getOfficeNum()const;
private:
	int officeNum;
};

// Chair Class Function Definitions
ostream& operator<<(ostream& output, Chair iChair) {
	output << "-----Chair-----" << endl;
	output << "Manufacturer: " << iChair.getManufacturer() << endl;
	output << "Date: " << iChair.getDate() << endl;
	output << "Cost: " << iChair.getCost() << endl;
	output << "SKU: " << iChair.getSKU() << endl;
	output << "Office Number: " << iChair.getOfficeNum() << endl;
	return output;
}
Chair::Chair(const string& iManufacturer, const string iDate, const float& iCost, const string iSKU, const int& iOfficeNum) :
	Furniture(iManufacturer, iDate, iCost, iSKU), officeNum(iOfficeNum) {}
int Chair::getOfficeNum()const {
	return officeNum;
}

// Laptop Class definition - Is a computer
class Laptop : public Computer {
public:
	friend ostream& operator<<(ostream& output, Laptop iLaptop);
	// Parameterized Constructor definition
	Laptop(const string& iManufacturer, const string iDate, const float& iCost, const string& iModel, const string& iOS, const float& iScreensize);
	// Getter prototype
	float getScreensize()const;
private:
	float screensize;
};

ostream& operator<<(ostream& output, Laptop iLaptop) {
	output << "-----Laptop-----" << endl;
	output << "Manufacturer: " << iLaptop.getManufacturer() << endl;
	output << "Date: " << iLaptop.getDate() << endl;
	output << "Cost: " << iLaptop.getCost() << endl;
	output << "Model: " << iLaptop.getModel() << endl;
	output << "Operating System: " << iLaptop.getOS() << endl;
	output << "Screen Size: " << iLaptop.getScreensize() << endl;
	return output;
}

// Constructor definition
Laptop::Laptop(const string& iManufacturer, const string iDate, const float& iCost, const string& iModel, const string& iOS, const float& iScreensize) :
	Computer(iManufacturer, iDate, iCost, iOS, iModel), screensize(iScreensize) {}
// Getter definition
float Laptop::getScreensize()const {
	return screensize;
}

// Server Class Definition - Is a computer
class Server : public Computer {
public:
	Server(const string& iManufacturer, const string iDate, const float& iCost, const string& iModel, const string& iOS, const int iMemory);
	int getRAM()const;
private:
	int memory;
};

// Server Function Definitions
Server::Server(const string& iManufacturer, const string iDate, const float& iCost, const string& iModel, const string& iOS, const int iMemory) :
	Computer(iManufacturer, iDate, iCost, iModel, iOS), memory(iMemory) {}
int Server::getRAM()const {
	return memory;
}

// Printer Class Definition
class Printer : public Hardware {
public:
	friend ostream& operator<<(ostream& output, Printer iPrinter);
	Printer(const string& iManufacturer, const string iDate, const float& iCost, const string& iModel, const int& iTraySize);
	int getTraySize()const;
private:
	int traySize;
};

// Printer Class Function Defintions
ostream& operator<<(ostream& output, Printer iPrinter) {
	output << "-----Printer-----" << endl;
	output << "Manufacturer: " << iPrinter.getManufacturer() << endl;
	output << "Date: " << iPrinter.getDate() << endl;
	output << "Cost: " << iPrinter.getCost() << endl;
	output << "Model: " << iPrinter.getModel() << endl;
	output << "Tray Size: " << iPrinter.getTraySize() << endl;
	return output;
}
Printer::Printer(const string& iManufacturer, const string iDate, const float& iCost, const string& iModel, const int& iTraySize) :
	Hardware(iManufacturer, iDate, iCost, iModel), traySize(iTraySize) {}
int Printer::getTraySize()const {
	return traySize;
}

// Cubicle Class Definition - Is Furniture
class Cubicle : public Furniture {
public:
	friend ostream& operator<<(ostream& output, Cubicle iCubicle);
	Cubicle(const string& iManufacturer, const string iDate, const float& iCost, const string iSKU, const float& length, const float& width);
	float getLength()const;
	float getWidth()const;
	float getArea()const;
private:
	float length, width, area;
};

// Cubicle Class Function Definitions
ostream& operator<<(ostream& output, Cubicle iCubicle) {
	output << "-----Cubicle-----" << endl;
	output << "Manufacturer: " << iCubicle.getManufacturer() << endl;
	output << "Date: " << iCubicle.getDate() << endl;
	output << "Cost: " << iCubicle.getCost() << endl;
	output << "SKU: " << iCubicle.getSKU() << endl;
	output << "Area: " << iCubicle.getArea() << endl;
	return output;
}
Cubicle::Cubicle(const string& iManufacturer, const string iDate, const float& iCost, const string iSKU, const float& iLength, const float& iWidth) :
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
	// Printer Object instantiation
	Printer epson69("Epson", "12/06/19", 600, "Inkjet 2000", 12);

	// Print the Object with operator<< overloaded function
	cout << epson69 << endl;


}