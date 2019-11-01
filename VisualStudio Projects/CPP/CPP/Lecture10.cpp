

// Example of simple inheritance
#include <iostream>
#include <string>
using namespace std;

class Base {
public:
	Base(string myString, int myInt);
	void bprint()const;
protected:
	string bstring;
	int bint;
};

class Derived : public Base { // class derivation list. - after : is the list of classes we inherit from
public:
	Derived(string myString, int myInt, float myFloat);
	void dprint()const;
private:
	float dfloat;
};

Base::Base(string myString, int myInt) {
	bstring = myString;
	bint = myInt;
}

void Base::bprint()const {
	cout << "Base string: " << bstring << endl;
	cout << "Base int: " << bint << endl;
}

Derived::Derived(string myString, int myInt, float myFloat) : Base(myString, myInt) { // if this base construction initializer list wasn't called
	// then you would need a default constructor. But because we do call it, we do not need a default constructor
	dfloat = myFloat;
}

void Derived::dprint()const {
	cout << "Derived string: " << bstring << endl;
	cout << "Derived int: " << bint << endl;
	cout << "Derived float: " << dfloat << endl;
}

int main() {
	Derived d1("first", 5, 2.5);
	d1.dprint();

	Base b1("ass", 2);
	b1.bprint();
}