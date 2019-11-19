#include <iostream>
using namespace std;

// Vehicle class definition
class Vehicle {
public:
	Vehicle(const int& iRunningTime);
	virtual double getCO2()const; // Polymorphism function 
protected:
	int runningTime;
};

// Vehicle Parameterized Constructor Definition
Vehicle::Vehicle(const int& iRunningTime) : runningTime(iRunningTime) {}

// Vehicle Polymorphism Function definition
double Vehicle::getCO2()const {
	return 0;
}

// Bicycle class definition
class Bicycle : public Vehicle {
public:
	Bicycle(const int& iRunningTime);
	virtual double getCO2()const; // Polymorphism w
};

// Bicycle Parameterized Constructor definition
Bicycle::Bicycle(const int& iRunningTime) : Vehicle(iRunningTime) {}
// Bicycle polymorphism function definition
double Bicycle::getCO2()const {
	return 0;
}

// Car class definition
class Car : public Vehicle {
public:
	Car(const int& iRunningTime, const float& iWeight);
	virtual double getCO2()const;
private:
	float weight;
};

// Car Parameterized Constructor definition
Car::Car(const int& iRunningTime, const float& iWeight) : Vehicle(iRunningTime), weight(iWeight) {}
// Car polymorphism function definition
double Car::getCO2()const {
	if (weight < 2000) {
		return runningTime / 200 * 3;
	}
	else if (weight >= 2000) {
		return runningTime / 200 * 5;
	}
}

// Truck class definition
class Truck : public Vehicle {
public:
	Truck(const int& iRunningTime, const int& iHP);
	virtual double getCO2()const;
private:
	int HP;
};

// Truck Parameterized Constructor definition
Truck::Truck(const int& iRunningTime, const int& iHP) : Vehicle(iRunningTime), HP(iHP) {}
// Truck polymorphism function definition
double Truck::getCO2()const {
	if (HP < 150) {
		cout << "HP < 150" << endl;
		cout << "returning " << runningTime / 200 * 3 << endl;
		return runningTime / 200 * 3;
	}
	else if (HP >= 150) {
		cout << "HP >= 150" << endl;
		cout << "returning " << runningTime / 200 * 5 << endl;
		return runningTime / 200 * 5;
	}
}

// Train Class definition
class Train : public Vehicle {
public:
	Train(const int& iRunningTime, const int& iYearsOld);
	virtual double getCO2()const;
private:
	int yearsOld;
};

// Train Paramterized Constructor Definition
Train::Train(const int& iRunningTime, const int& iYearsOld) : Vehicle(iRunningTime), yearsOld(iYearsOld) {}
// Train polymorphism function definition
double Train::getCO2()const {
	if (yearsOld < 4) {
		return runningTime / 2000 * 60;
	}
	else if (yearsOld >= 4) {
		return runningTime / 2000 * 100;
	}
}

// Global polymorphism function definition - returns carbon footprint of any Vehicle inherited class object
double getCarbonFootprint(Vehicle* vehicle);

int main() {
	Car car1(500, 2345);
	Truck truck1(750, 300);
	Train train1(17000, 10);
	Vehicle* carPtr = &car1;
	Vehicle* truckPtr = &truck1;
	Vehicle* trainPtr = &train1;

	cout << "Car Carbon Footprint: " << getCarbonFootprint(carPtr) << endl;
	cout << "Truck Carbon Footprint: " << getCarbonFootprint(truckPtr) << endl;
	cout << "Train Carbon Footprint: " << getCarbonFootprint(trainPtr) << endl;
	
}

double getCarbonFootprint(Vehicle* vehicle) {
	return vehicle->getCO2();
}