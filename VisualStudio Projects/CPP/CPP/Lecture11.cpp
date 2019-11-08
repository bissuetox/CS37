#include <iostream>
#include <string>

class Base {
public:
	void display();
};

class Derived : public Base {
public:
	void display();
};

// If you wanted to access the Base class display function, you can use the scope resolution operator ::
void Derived::display() {
	Base::display(); // Specifying the base class using :: 
}

int main() {
	Derived d2;
	d2.Base::display(); // This calls the derived class display member function. 
	// The base class display function is not in our scope and was Redefined over by the Derived Display()
}