#include <iostream>
using namespace std;


//Point const example
/*
class Point {
private:
	int x, y;

public:
	void getData(int& nx, int& ny) {
		nx = x;
		ny = y;
	}
	void setX(const int& nx) // using reference is beneficial for speed - if a large user defined type is passed, no no memory needs to be allocated for that var
	{
		nx = 5; // if we accidentally try to set nx to something, it won't go through
		x = nx; 
	}
};

*/

class Cuboid {
private: 
	int height, length, width;
public:
	Cuboid();
	Cuboid(int iheight, int ilength, int iwidth);
	Cuboid operator+(const Cuboid& tcuboid); // prototype for + operator overloaded function. called when you use + operator between two cuboids
};

Cuboid::Cuboid() {
	height = 0;
	length = 0;
	width = 0;
}

Cuboid::Cuboid(int iheight, int ilength, int iwidth) {
	height = iheight;
	length = ilength;
	width = iwidth;
}


Cuboid Cuboid::operator+(const Cuboid& tcuboid) { // when the operator + is called, this function is called
	int nheight = height + tcuboid.height; // height is the member of cube, tcuboid is anothercube
	int nwidth = width + tcuboid.width;
	int nlength = length + tcuboid.length;
	Cuboid temp(nheight, nwidth, nlength);
	return temp;
}

int main() {
	Cuboid cube(3,5,7);
	Cuboid anothercube;
	Cuboid yetAnotherCube;
	anothercube = cube; // this is perfectly legal because of class scope - both objects are of the same class.
	yetAnotherCube = cube + anothercube; // not allowed... unless? We make a operator+ function 
	// equivalent is yetAnotherCube = cube.operator+(anotherCube);




	// 

}
