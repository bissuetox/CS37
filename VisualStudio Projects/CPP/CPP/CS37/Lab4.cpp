#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


class Circle {
public:
	void setRadius(double rad) {
		radius = rad;
	}
	double getRad() {
		return radius;
	}
private:
	double radius;
};

double calcArea(Circle &cir);

int main() {
	Circle cir1;
	double cirRadius, cirArea;
	cout << "Enter the radius of a circle: ";
	cin >> cirRadius;

	cir1.setRadius(cirRadius);

	cirArea = calcArea(cir1);

	cout << "Radius: " << cir1.getRad() << endl;
	cout << "Area: " << calcArea(cir1) << endl;

	system("pause");

}

double calcArea(Circle &cir) {
	return (cir.getRad() * cir.getRad()) * 3.14;
}