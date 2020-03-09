#include <iostream>
using namespace std;

int prime(int x) {
	for (int i = 2; i < x; i++) {
		cout << x << "%" << i << " = " <<  x % i << endl;
		if (x % i == 0) {
			
			return 0;
		}
	}
	return 1;
}

int main() {
	int num;
	cout << "Enter an integer: ";
	cin >> num;
	while (num != -1) {
		cout << "Prime: " << prime(num) << endl;
		cout << "Enter an integer: ";
		cin >> num;
	}
	
}