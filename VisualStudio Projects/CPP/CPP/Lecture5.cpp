#include <iostream>
#include <string>
using namespace std;


/*
//Rectangle class w/ constructors and other stuff--------------------
class Rectangle {
public:
	Rectangle(); // overloaded functions - regular constructor - does not need a return type because it is constructor - special case
	Rectangle(int ihgt, int ilen); // parameterized constructor - so you can instantiate an object with or without parameters
	// alternatively, using default arguments, you could combine these two and do:
	// Rectangle(int ihgt = 0, int ilen = 0);
	void setHeight(int ihgt); // standard function prototypes
	void setLength(int ilen);
	int getHeight();
	int getLength();
private:
	int height, length; // you can technically set default values to these as of C++ standard 11 or 14.
};

// constructor definition - so when an object of the class is instantiated, it sets default values of 0 to height and length
Rectangle::Rectangle() // uses scope operator :: to notify that you're defining a function inside of the Rectangle class 
{
	height = 0; // not declaring, these are setting values to height and length
	length = 0; // height and length were already declared inside of the class, which this function is a member of using the :: operator (scope operator)
}
Rectangle::Rectangle(int ihgt, int ilen) {
	height = ihgt; 
	length = ilen;
}

// you could combine both the Rectangle() and Rectangle(int ihgt, int ilen) functions by using default arugments
//Rectangle::Rectangle(int ihgt = 0, int ilen = 0) - you technically only have to set default parameters in the prototype, you can leave out default in the definition
//{
//	height = ihgt;
//	length = ilen;
//}
//

void Rectangle::setHeight(int ihgt) {
	height = ihgt;
}

void Rectangle::setLength(int ilen) {
	length = ilen;
}

int Rectangle::getHeight() {
	return height;
}

int Rectangle::getLength() {
	return length;
}

int main() {
	Rectangle myR1;
	Rectangle myR2(3, 7);
}

*/

class Rectangle {
private:
	int* height, * length; // these pointers do not yet point to anywhere in memory
public:
	Rectangle(int ihgt, int ilen) {
		height = new int;
		length = new int; // gets memory address from the heap and puts it into the pointer
		*height = ihgt;
		*length = ilen;
	}

	~Rectangle() {
		delete height;
		delete length; // once destructor is called, it deletes the heap memory values stored in height and length
	}
};

int main() {
	showRectangle();
}

void showRectangle() {
	Rectangle myR1(3, 5);
}