#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// point class with private vars x and y, and two constructor prototypes and other member function prototypes
class Point {
public: 
	Point();
	Point(float xfunc, float yfunc);
	void setX(float xfunc);
	void setY(float yfunc);
	float getX();
	float getY();
	float distOrigin();
private:
	float x;
	float y;
};

// function definition for Point constructor with out any arguments
Point::Point() {
	x = 0;
	y = 0;
}

// function definition for Point constructor with 2 arguments
Point::Point(float xfunc, float yfunc) {
	x = xfunc;
	y = yfunc;
}

// function definition for setX, sets argument to class variable x
void Point::setX(float xfunc) {
	x = xfunc;
}
// function definition for setY, sets argument to class variable y
void Point::setY(float yfunc) {
	y = yfunc;
}

// returns class variable x
float Point::getX(){
return x;
}

// returns class variable y
float Point::getY() {
	return y;
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

// main funct that initalizes a point with arguments constructor, then updates the points to 7 and 4, then prints the updated points' distance from (0,0)
int main() {
	Point p1(5, 10);
	cout << "Point p1 initialized: " << p1.getX() << " and " << p1.getY() << endl; // 
	Point* p1Ptr = &p1;
	updatePoint(p1Ptr);
	cout << "Point p1 updated to: " << p1.getX() << " and " << p1.getY() << endl;
	cout << "Distance from origin is: " << p1.distOrigin() << endl;
}