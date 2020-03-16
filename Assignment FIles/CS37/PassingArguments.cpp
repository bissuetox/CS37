// 3 ways of passing arguments to a function
#include<iostream>
#include <iomanip>


using namespace std;

// prototypes
void swapbyPtr(int* pnum1, int* pnum2);
void swapbyRef(int& rnum1, int& rnum2);
void swapbyValue(int vnum1, int vnum2);

int main()
{
	int num1, num2, keep1, keep2;

	cout << "Enter two numbers: ";
	cin >> num1 >> num2;
	keep1 = num1;
	keep2 = num2;

	//Swap by Value
	cout << endl << endl << "Before swap by VALUE:" << endl;
	cout << left << setw(12) << "Variable" << setw(12) << "Value" << "Memory Address" << endl;
	cout << setw(12) << "num1" << setw(12) << num1 << &num1 << endl;
	cout << setw(12) << "num2" << setw(12) << num2 << &num2 << endl;
	swapbyValue(num1, num2);
	cout << "After swap by VALUE:" << endl;
	cout << setw(12) << "num1" << setw(12) << num1 << &num1 << endl;
	cout << setw(12) << "num2" << setw(12) << num2 << &num2 << endl;

	//Swap by PTR
	cout << endl << endl << "Before swap by PTR/ADDRESS:" << endl;
	cout << left << setw(12) << "Variable" << setw(12) << "Value" << "Memory Address" << endl;
	cout << setw(12) << "num1" << setw(12) << num1 << &num1 << endl;
	cout << setw(12) << "num2" << setw(12) << num2 << &num2 << endl;
	swapbyPtr(&num1, &num2);
	cout << "After swap by PTR/ADDRESS:" << endl;
	cout << setw(12) << "num1" << setw(12) << num1 << &num1 << endl;
	cout << setw(12) << "num2" << setw(12) << num2 << &num2 << endl;

	num1 = keep1;
	num2 = keep2;

	//Swap by Reference
	cout << endl << endl << "Before swap by Reference:" << endl;
	cout << left << setw(12) << "Variable" << setw(12) << "Value" << "Memory Address" << endl;
	cout << setw(12) << "num1" << setw(12) << num1 << &num1 << endl;
	cout << setw(12) << "num2" << setw(12) << num2 << &num2 << endl;
	swapbyRef(num1, num2);
	cout << "After swap by Reference:" << endl;
	cout << setw(12) << "num1" << setw(12) << num1 << &num1 << endl;
	cout << setw(12) << "num2" << setw(12) << num2 << &num2 << endl;

	system("pause");
}

// Swap values of arguments passed by pointer/address.
void swapbyPtr(int* pnum1, int* pnum2)
{
	cout << "In swap by PTR/ADDRESS:" << endl;
	cout << setw(12) << "pnum1" << setw(12) << *pnum1 << &pnum1 << endl;
	cout << setw(12) << "pnum2" << setw(12) << *pnum2 << &pnum2 << endl;

	int temp = *pnum1;
	*pnum1 = *pnum2;
	*pnum2 = temp;
}

// Swap values of arguments passed by reference.
void swapbyRef(int& rnum1, int& rnum2)
{
	cout << "In swap by REFERENCE:" << endl;
	cout << setw(12) << "rnum1" << setw(12) << rnum1 << &rnum1 << endl;
	cout << setw(12) << "rnum2" << setw(12) << rnum2 << &rnum2 << endl;

	int temp = rnum1;
	rnum1 = rnum2;
	rnum2 = temp;
	
}

// Swap values of arguments passed by value (no swapping takes place, why?).
void swapbyValue(int vnum1, int vnum2)
{
	cout << "In swap by VALUE:" << endl;
	cout << setw(12) << "vnum1" << setw(12) << vnum1 << &vnum1 << endl;
	cout << setw(12) << "vnum2" << setw(12) << vnum2 << &vnum2 << endl;

	int temp = vnum1;
	vnum1 = vnum2;
	vnum2 = temp;
}