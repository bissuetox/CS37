//Show order of constructor/destructor completion when using inheritance
#include <iostream>
#include <string>

using namespace std;

class One {
public:
	One();
	~One();
};

//Display message for constructor completion
One::One() {
	cout << "Class One Constructor completed" << endl;
}

//Destructor invoked
One::~One() {
	cout << "Class One Destructor completed" << endl;
}

class Two : public One {
public:
	Two();
	~Two();
};

//Display constructor
Two::Two() {
	cout << "Class Two Constructor completed" << endl;
}

// Display destructor
Two::~Two() {
	cout << "Class Two Destructor completed" << endl;
}

class Three : public Two {
public:
	Three();
	~Three();
};

//Display constructor
Three::Three() {
	cout << "Class Three Constructor completed" << endl;
}

// Display destructor
Three::~Three() {
	cout << "Class Three Destructor completed" << endl;
}

int main() {
	cout << "Instantiating object1 of type One" << endl;
	One object1;
	cout << endl;

	cout << "Instantiating object2 of type Two" << endl;
	Two object2;
	cout << endl;

	cout << "Instantiating object3 of type Three" << endl;
	Three object3;
	cout << endl;
}