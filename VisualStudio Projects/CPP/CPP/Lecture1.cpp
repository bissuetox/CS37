// Display Hello world on the screen
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
using std::cout;
using std::cin;
using std::setw;
using std::getline;

/* first program
int main() {
	std::cout << "hello bitches" << std::endl;
	printf("FUck cout");
	return 0;
}
*/

/* second program

int main() {
	int yourAge, friendAge;
	int* ptr = &yourAge;
	cout << "Enter your age: ";
	cin >> yourAge;
	cout << "Enter your friend's age: ";
	cin >> friendAge;
	cout << "The ages are " << yourAge << " and " << friendAge;

}
*/

// manipulators practice

int main() {
	cout << setw(15) << "width of 15 - right" << endl;
	cout << setw(15) << left << "width of 15 - left" << endl;
	cout << setw(25) << left << setfill('*') << "width of 25 - left and fill *" << endl;


	string line;
	cout << "enter a string: ";
	getline(cin, line);
	cout << line;
}