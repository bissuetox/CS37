#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*
class Fraction {
private:
	int num, denom;
public:
	friend ostream& operator<<(ostream& output, const Fraction frac); // friendship granted to operator<< global function, allowing it to access private members
	Fraction(); // constructor prototypes
	Fraction(int inum, int idenom);
	void setNum(const int& inum); // demonstrates data 
	void setDenom(int idenom);
	int getNum()const;
	int getDenom()const;

};

Fraction::Fraction() {
	num = 0;
	denom = 0;
}
Fraction::Fraction(int inum, int idenom) {
	num = inum;
	denom = idenom;
}
void Fraction::setNum(const int &inum) { // this call transforms into void Fraction::setNum(Fraction * const this, const int &inum
	num = inum;
	// translates in compiler to
	// this->num = inum

}
void Fraction::setDenom(int idenom) {
	denom = idenom;
}
int Fraction::getNum()const {
	return num;
}
int Fraction::getDenom()const {
	return denom;
}

ostream& operator<<(ostream& output, const Fraction frac) {
	output << frac.getNum() << "/" << frac.getDenom();
	// if this function is prototyped in Fraction class using: friend <prototype declaration> we can use the below
	output << frac.num << "/" << frac.denom;
	return output;
}

*/

class Time {
public:
	Time();
	Time& setHours(const int& newHrs);
	Time& setMinutes(const int& newMins);
	Time& setSeconds(const int& newSeconds);
private:
	int hours, minutes, seconds;
};

Time::Time() {
	hours = 0;
	seconds = 0;
	minutes = 0;
}

Time& Time::setHours(const int& newHrs) { // return type is Time& because we want to return an object 
	hours = newHrs;
	return *this; // must dereference "this" - it is a pointer to the Time object
	// returns a t1 object so t1.setMins(14) can be legally called
}

int Fraction::

int main() {
	Time t1;
	t1.setHours(12).setMins(14).setSeconds(30);
	// setHours above needs to return a t1 object for the cascade function call to work
}