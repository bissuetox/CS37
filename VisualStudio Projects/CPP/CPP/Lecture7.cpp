#include <iostream>
using namespace std;


// point class example with operator+ overloaded functions in global and class scope

class Point {
private:
	int x, y;
public:
	Point();
	Point(int mx, int my);
	Point operator+(const int& iInt);
	int getX()const;
	int getY()const;
	int setX(int mx);
	int setY(int my);
};

Point::Point() {
	x = 0;
	y = 0;
}

Point::Point(int mx, int my) {
	x = mx;
	y = my;
}

int Point::getX()const {
	return x;
}

int Point::getY()const {
	return y;
}

int Point::setX(int mx) {
	x = mx;
}

int Point::setY(int my) {
	y = my;
}

Point Point::operator+(const int& nInt) {
	int tx, ty;
	tx = x + nInt;
	ty = y + nInt;
	return Point(tx, ty); 
	// you could use Point newpoint(tx, ty) then return newpoint, but above step is a shortcut
}

Point operator+(const int& nInt, const Point& pRH) {
	int tx, ty;
	tx = nInt + pRH.getX();
}

istream& operator>>(istream& input, Point& newPt) { // input is another name for cin, 
	// we want to use istream as reference & so that we can maintain the same cin stream, not a copy of cin
	int tx, ty;
	input.ignore();
	input >> tx;
	input.ignore();
	input >> ty;
	input.ignore();
	newPt.setX(tx);
	newPt.setY(ty);
	return input; // returns input AKA cin, so if we have multipled insertion operations the same cin will be extracted from
 }

ostream& operator<<(ostream& output, Point &pRH

int main() {
	Point p1, p2, p3;
	p2 = p1 + 3; // AKA p2 = p1.operator+(3) this is legal because p1 is a member of the class
	p2 = 3 + p1; // AKA  p2 = 3.operator+(p1) however this is not legal because and 3 is not a member of the class
	// with the addition of the overloaded operator+ global function above, equal to p2 = operator+(3, p1)

	// if we were to do
	p2 = 3 + 3 + p1; // due to associativity and precedence, it would add 3+3, then evaluate 6 + p1
	// + order of operators is left to right

	cout << "Enter a point in the form (x,y): ";
	cin >> p3; // same thing as operator>>(cin, p3);

}

