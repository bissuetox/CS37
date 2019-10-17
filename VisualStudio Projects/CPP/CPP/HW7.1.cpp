#include <iostream>
using namespace std;

// program that gets input for two fractions prints out addition of two fractions, addition and subtraction of integer and fraction,
// and addition and subtraction of fraction and integer
class Fraction {
private:
	int num, denom;
public:
	Fraction(); // constructor prototypes
	Fraction(int inum, int idenom);
	void setNum(int inum); // member function prototypes
	void setDenom(int idenom);
	int getNum()const;
	int getDenom()const;
	Fraction operator+(const Fraction frac); // operator overloaded function prototypes
	Fraction operator-(const Fraction frac);
	Fraction operator+(const int number);
	Fraction operator-(const int number);
};

// default constructor function definition
Fraction::Fraction() {
	num = 0;
	denom = 0;
}

// parameterized constructor function definition
Fraction::Fraction(int inum, int idenom) {
	num = inum;
	denom = idenom;
}

// setter for the class numerator
void Fraction::setNum(int inum) {
	num = inum;
}

// setter for class denominator
void Fraction::setDenom(int idenom) {
	denom = idenom;
}

// getter for class variable numerator
int Fraction::getNum()const {
	return num;
}

// getter for class variable denominator
int Fraction::getDenom()const {
	return denom;
}

// operator + overloaded function definition for addition of two fractions
Fraction Fraction::operator+(const Fraction frac) {
	int inum, idenom;
	inum = num * frac.getDenom() + denom * frac.getNum();
	idenom = denom * frac.getDenom();
	return Fraction(inum, idenom);
}

// operator - overloaded function definition for subtraction of two fractions
Fraction Fraction::operator-(const Fraction frac) {
	int inum, idenom;
	inum = num * frac.getDenom() - denom * frac.getNum();
	idenom = denom * frac.getDenom();
	return Fraction(inum, idenom);
}

// operator + overloaded function definition for addition of fraction and integer
Fraction Fraction::operator+(const int jnumber) {
	int inum, idenom, jnum, jdenom;
	jnum = denom * jnumber;
	jdenom = denom;
	inum = num + jnum;;
	idenom = denom;
	return Fraction(inum, idenom);
}

// operator - overloaded function definition for subtraction of fraction and integer
Fraction Fraction::operator-(const int jnumber) {
	int inum, idenom, jnum, jdenom;
	jnum = denom * jnumber;
	jdenom = denom;
	inum = num - jnum;;
	idenom = denom;
	return Fraction(inum, idenom);
}

// operator + overloaded function definition for addition of integer and fraction 
Fraction operator+(const int jnumber, const Fraction frac) {
	int inum, idenom, jnum, jdenom;
	jnum = frac.getDenom() * jnumber;
	jdenom = frac.getDenom();
	inum = frac.getNum() + jnum;;
	idenom = frac.getDenom();
	return Fraction(inum, idenom);
}

// operator - overloaded function definition for subtraction of integer and fraction 
Fraction operator-(const int jnumber, const Fraction frac) {
	int inum, idenom, jnum, jdenom;
	jnum = frac.getDenom() * jnumber;
	jdenom = frac.getDenom();
	inum = jnum - frac.getNum();
	idenom = frac.getDenom();
	return Fraction(inum, idenom);
}

// stream insertion operator overloaded function that prints in format x/y
ostream& operator<<(ostream& output, const Fraction frac);

int main() {
	Fraction f1(3, 5), f2(4,7);
	int tnum, tdenom;

	cout << "Fraction 1: " << f1 << endl;
	cout << "Fraction 2: " << f2 << endl;

	// printing fraction addition and subtraction operations according to prompt
	cout << f1 << " + " << f2 << " = " << f1 + f2 << endl;
	cout << f1 << " - " << f2 << " = " << f1 - f2 << endl;
	cout << f1 << " + " << "5" << " = " << f1 + 5 << endl;
	cout << "3" << " + " << f2 << " = " << 3 + f2 << endl;
	cout << f1 << " - " << "5" << " = " << f1 - 5 << endl;
	cout << "3" << " - " << f2 << " = " << 3 - f2 << endl;

	system("pause");
	return 0;
}

// stream insertion operator overloaded function definition
ostream& operator<<(ostream& output, const Fraction frac) {
	output << frac.getNum() << "/" << frac.getDenom();
	return output;
}

