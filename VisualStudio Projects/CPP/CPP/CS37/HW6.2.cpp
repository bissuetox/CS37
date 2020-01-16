#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// point class with private vars x and y, and two constructor prototypes and other member function prototypes
class Point {
public: 
	Point();
	Point(float xfunc, float yfunc, float zfunc);
	void setX(float xfunc);
	void setY(float yfunc);
	void setZ(float zfunc);
	float getX();
	float getY();
	float getZ();
	float distOrigin();
	Point operator+(const Point& funcPoint);
	int operator!();

private:
	float x;
	float y;
	float z;
};

// function definition for Point constructor with out any arguments
Point::Point() {
	x = 0;
	y = 0;
	z = 0;
}

// function definition for Point constructor with 2 arguments
Point::Point(float xfunc, float yfunc, float zfunc) {
	x = xfunc;
	y = yfunc;
	z = zfunc;
}

// function definition for setX, sets argument to class variable x
void Point::setX(float xfunc) {
	x = xfunc;
}
// function definition for setY, sets argument to class variable y
void Point::setY(float yfunc) {
	y = yfunc;
}

// function definition for setZ, sets argument to class variable z
void Point::setZ(float zfunc) {
	z = zfunc;
}

// returns class variable x
float Point::getX(){
return x;
}

// returns class variable y
float Point::getY() {
	return y;
}

// returns class variable z
float Point::getZ() {
	return z;
}

// returns class variables x and y's distance from origin
float Point::distOrigin() {
	return sqrt((x*x) + (y*y));
}

// Using the passed Point class pointer, calls the class' setX and setY functions and sets x and y to 7 and 4 per homework instructions
void updatePoint(Point *point) {
	point->setX(7.0);
	point->setY(4.0);
}

// + operator overload function that initializes a temp pointer, adds the called and passed Point into the values of the temp Point, and returns it
Point Point::operator+(const Point& funcPoint) {
	Point tempPoint;
	tempPoint.x = x + funcPoint.x;
	tempPoint.y = y + funcPoint.y;
	tempPoint.z = z + funcPoint.z;
	return tempPoint;
}

// operator ! function that returns true if the point called is the origin, and false if it is
int Point::operator!() {
	if (x == 0) {
		if (y == 0) {
			if (z == 0) {
				return 0;
			}
		}
	}
	else
		return 1;
}

// main funct that initalizes 3 points, sets 2 of them to values with setters, adds the two to equal the third point, then default initializes a fourth and prints if it's the origin or not
int main() {
	Point p1, p2, p3;
	p1.setX(3);
	p1.setY(5);
	p1.setZ(7);
	p2.setX(10);
	p2.setY(15);
	p2.setZ(20);
	p3 = p1 + p2;

	cout << "Point 1: " << p1.getX() << ", " << p1.getY() << ", " << p1.getZ() << endl;
	cout << "Point 2: " << p2.getX() << ", " << p2.getY() << ", " << p2.getZ() << endl;
	cout << "Point 3: " << p3.getX() << ", " << p3.getY() << ", " << p3.getZ() << endl;

	Point p4;
	if (!p4) 
		cout << "Point 4 is not at the origin." << endl;
	else
		cout << "Point 4 is at the origin." << endl;

}