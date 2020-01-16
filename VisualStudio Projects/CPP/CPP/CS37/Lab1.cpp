#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	int yourAge, friendAge;
	cout << "Enter your age: ";
	cin >> yourAge;
	cout << "Enter your friend's age: ";
	cin >> friendAge;
	cout << "The ages are " << yourAge << " and " << friendAge << endl;

	if (yourAge > friendAge)
		cout << "You are older than your friend!";
	else
		if (yourAge < friendAge)
			cout << "Your friend is older than you!";
		else
			cout << "You are the same age!";

}