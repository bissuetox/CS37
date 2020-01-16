#include <iostream>
using namespace std;

// Base - Derived simple example

class Base {
public:
	Base(const int& iBaseInt);
	virtual void display()const; // Virtual Keyword - indicates that it is expected to be overridden in a derived class
	// If this Base class function is marked virtual, it will not be inherited into the derived class
protected:
	int baseInt;
};

Base::Base(const int& iBaseInt) : baseInt(iBaseInt) {}

void Base::display()const {
	cout << "Base data: " << baseInt << endl;
}

class Derived : public Base {
public:
	Derived(int iBaseInt, float iDerivedFloat);
	virtual void display()const; // Virtual keyword 
	// If this is not specified, it will inherit the virtual base class function
private:
	float derivedFloat;
};

Derived::Derived(int iBaseInt, float iDerivedFloat) : Base(iBaseInt), derivedFloat(iDerivedFloat) {}

void Derived::display()const {
	cout << "Derived data: " << derivedFloat << endl; // This is redefinition - redefines the display function over Base's display function
}

int main() {
	Base b1(5); // Base class
	Derived d2(10, 6.9); // Derived object
	b1.display(); // Calls Base class display function
	d2.display(); // Calls Redefined Derived display function

	Base *bptr = &d2; // This pointer points to the the Base class inherited into the Derived class
	// Base type pointer points to a Derived type object
	bptr->display(); 
	// Without virtual keyword in prototypes; Calls the display function from the Base class - counterexample
	// With virtual keyword in prototypes; Calls display function from Derived Class - Use this for polymorphism

	// This allows us to make a function that takes a Base class pointer, in which we can create many different inherited class objects
	//  to pass into it. 
} 



class Mammal {
public:
	virtual void talk()const;
};

void Mammal::talk()const {
	cout << "Mammaml says 'hi!'" << endl;
}

class Cat : public Mammal {
public:
	virtual void talk()const;
};

void Cat::talk()const {
	cout << "Cat says 'meow'" << endl;
}

void globalTalk(Mammal *mptr) // or Mammal &mref

int main() {
	Mammal oneM;
	Cat oneC;
	cout << "Mammal objct --" << endl;
	oneM.talk();

	cout << "Cat object -- " << endl;
	oneC.talk();

	cout << endl << endl;

	Mammal* mptr = &oneM; // mptr points to Mammal Object
	cout << "Mammal objct --" << endl;
	mptr->talk();

	mptr = &oneC; // mptr now points to the Cat Object
	cout << "Cat object -- " << endl;
	mptr->talk();

	cout << "Global talk of Cat--" << endl;
	globalTalk(mptr);
}

void globalTalk(Mammal *mptr) {
	mptr->talk();
	// or mref.talk();
}