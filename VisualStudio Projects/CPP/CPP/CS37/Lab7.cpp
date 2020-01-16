#include <iostream>
using namespace std;

class Fraction {
private:
	int num, denom;
public:
	Fraction();
	Fraction(int inum, int idenom);
	void setNum(int inum);
	void setDenom(int idenom);
	int getNum()const;
	int getDenom()const;
	Fraction operator+(const Fraction frac);
	Fraction operator-(const Fraction frac);
};

Fraction::Fraction() {
	num = 0;
	denom = 0;
}

Fraction::Fraction(int inum, int idenom) {
	num = inum;
	denom = idenom;
}

void Fraction::setNum(int inum) {
	num = inum;
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

Fraction Fraction::operator+(const Fraction frac) {
	int inum, idenom;
	inum = num * frac.getDenom() + denom * frac.getNum();
	idenom = denom * frac.getDenom();
	return Fraction(inum, idenom);
}

Fraction Fraction::operator-(const Fraction frac) {
	int inum, idenom;
	inum = num * frac.getDenom() - denom * frac.getNum();
	idenom = denom * frac.getDenom();
	return Fraction(inum, idenom);
}

ostream& operator<<(ostream& output, const Fraction frac);

int main() {
	Fraction f1, f2;
	int tnum, tdenom;

	cout << "Enter fraction 1 numerator: ";
	cin >> tnum;
	f1.setNum(tnum);
	cout << "Enter fraction 1 denominator: ";
	cin >> tdenom;
	f1.setDenom(tdenom);

	cout << "Enter fraction 2 numerator: ";
	cin >> tnum;
	f2.setNum(tnum);
	cout << "Enter fraction 2 denominator: ";
	cin >> tdenom;
	f2.setDenom(tdenom);

	cout << "Fraction 1: " << f1 << endl;
	cout << "Fraction 2: " << f2 << endl;

	cout << f1 << " + " << f2 << " = " << f1 + f2 << endl;
	cout << f1 << " - " << f2 << " = " << f1 - f2 << endl;

	system("pause");
	return 0;
}

ostream& operator<<(ostream& output, const Fraction frac) {
	output << frac.getNum() << "/" << frac.getDenom();
	return output;
}