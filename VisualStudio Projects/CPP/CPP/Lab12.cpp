#include <iostream>
using namespace std;

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

class Dog : public Mammal {
public:
	virtual void talk()const;
};

void Dog::talk()const {
	cout << "Dog says 'bark' " << endl;
}

class Cow : public Mammal {
public:
	virtual void talk()const;
};

void Cow::talk()const {
	cout << "Cow says 'moo'" << endl;
}

class Tiger : public Cat {
public:
	virtual void talk()const;
};

void Tiger::talk()const {
	cout << "Tiger says 'rawr xD'" << endl;
}

void greeting(Mammal* mptr); // or Mammal &mref

int main() {
	Tiger oneTiger;
	Dog oneDog;
	Cow oneCow;
	Mammal* tptr = &oneTiger;
	Mammal* dptr = &oneDog;
	Mammal* cptr = &oneCow;

	// Tiger
	greeting(tptr);
	// Dog
	greeting(dptr);
	// Cow
	greeting(cptr);
}

void greeting(Mammal* mptr) {
	mptr->talk();
	// or mref.talk();
}