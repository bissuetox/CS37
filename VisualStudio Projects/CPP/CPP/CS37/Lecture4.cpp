#include <iostream>
#include <string>
using namespace std;

/*
struct Product {
	int sku;
	float price;
}; 

int main() {
	Product toy; // instantiation of an object
	toy.sku = 5;
	toy.price = 55.55;

	cout << "Toy:" << toy.sku << endl << toy.price;
	system("pause");
} */



// wrong way to do it
/*
class Rectangle {
public: 
	int height, length;
};
*/

// class and functions by reference------------

/*
class Rectangle {
	
public:
	//sets height and length
	void setDims(int ihgt, int ilen) {
		height = ihgt;
		length = ilen;
	}
	// displays the dimensions
	void displayDims() {
		cout << "Height: " << height;
		cout << "Length: " << length;
	}
private:
	int height, length;
};

void loadRectangle(Rectangle &shape); // pointer option: void loadRectangle(Rectangle *shape)

int main() {
	Rectangle rect1; // instantiating an object
	loadRectangle(rect1); // pointer option : loadRectangle(&rect1)
	rect1.displayDims(); 
	
	system("pause");
}

void loadRectangle(Rectangle &shape) // pointer option: void loadRectangle(Rectangle *shape)
{
	int uhgt, ulen;
	cout << "Enter the height:";
	cin >> uhgt;
	cout << "Enter the lengh: ";
	cin >> ulen;
	shape.setDims(uhgt, ulen); // pointer option: (*shape).setDims(uhgt, ulen);
}
*/

// class and functions by pointer (object array)

class Rectangle {

public:
	//sets height and length
	void setDims(int ihgt, int ilen) {
		height = ihgt;
		length = ilen;
	}
	// displays the dimensions
	void displayDims() {
		cout << "Height: " << height << endl;
		cout << "Length: " << length << endl;
	}
private:
	int height, length;
};

void loadRectangle(Rectangle* shape); // or Rectangle shape[]

int main() {
	Rectangle rect1[3]; // instantiating an object array
	loadRectangle(rect1);
	for (int i = 0; i < 3; i++) {
		rect1[i].displayDims();
	}

	system("pause");
}

void loadRectangle(Rectangle *shape) // or Rectangle shape[]
{
	for (int i = 0; i < 3; i++) {

		int uhgt, ulen;
		cout << "Enter the height:";
		cin >> uhgt;
		cout << "Enter the lengh: ";
		cin >> ulen;
		shape[i].setDims(uhgt, ulen); // pointer option: (*shape).setDims(uhgt, ulen);
	}
}