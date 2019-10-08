#include <iostream>
#include <iomanip>
using namespace std;

// program that compares two times using 3 different methods, then prints the results

// time class with function delcaration
class Time {
private:
	int hours, minutes, seconds;
public:
	Time();
	Time(int ihours, int iminutes, int iseconds);
	void setHours(int ihours);
	void setMinutes(int iminutes);
	void setSeconds(int iseconds);
	int getHours();
	int getMinutes();
	int getSeconds();
	void displayTime24();
	void displayTime12();
	int compare(int ihours, int iminutes, int iseconds);
	int compare(Time iTime);
	int operator==(Time iTime);
};

// time constructor with no arguments - default 0 for all 3 variables
Time::Time() {
	hours = 0;
	minutes = 0;
	seconds = 0;
}

// time constructor with 3 arguments, sets initial values to passed arguments
Time::Time(int ihours, int iminutes, int iseconds) {
	hours = ihours;
	minutes = iminutes;
	seconds = iseconds;
}

// setter for hours
void Time::setHours(int ihours) {
	hours = ihours;
}

// setter for minutes
void Time::setMinutes(int iminutes) {
	minutes = iminutes;
}

// setter for seconds
void Time::setSeconds(int iseconds) {
	seconds = iseconds;
}

// getter for hours
int Time::getHours() {
	return hours;
}

// getter for minutes
int Time::getMinutes() {
	return minutes;
}

// getter for seconds
int Time::getSeconds() {
	return seconds;
}

// diplays time in 24 hour format
void Time::displayTime24() {
	cout << hours << ":" << minutes << ":" << setw(2) << setfill('0') << seconds << endl;
}

// displays time in 12 hour format with AM or PM
void Time::displayTime12() {
	if (hours == 0)
		cout << "12" << ":" << minutes << ":" << setw(2) << setfill('0') << seconds << " AM" << endl;
	else if (hours < 12)
		cout << hours << ":" << minutes << ":" << setw(2) << setfill('0') << seconds << " AM" << endl;
	else if (hours == 12)
		cout << hours << ":" << minutes << ":" << setw(2) << setfill('0') << seconds << " PM" << endl;
	else 
		cout << hours - 12 << ":" << minutes << ":" << setw(2) << setfill('0') << seconds << " PM" << endl;

}

// compare function with 3 arguments of hours, minutes and seconds
// returns 1 (true) if times are the same and 0 (false) if they are not
int Time::compare(int ihours, int iminutes, int iseconds) {
	if (ihours == hours) {
		if (iminutes = minutes) {
			if (iseconds = seconds) {
				return 1;
			}
		}
	}
	else
		return 0;
}

// compare function with Time object argument
// returns 1 (true) if times are the same and 0 (false) if they are not
int Time::compare(Time iTime) {
	if (iTime.getHours() == hours) {
		if (iTime.getMinutes() == minutes) {
			if (iTime.getSeconds() == seconds) {
				return 1;
			}
		}
	}
	else
		return 0;
}

// operator == overloaded function that compares the passed Time object's time variables to the object called time variables
// returns 1 (true) if times are the same and 0 (false) if they are not
int Time::operator==(Time iTime) {
	if (iTime.getHours() == hours) {
		if (iTime.getMinutes() == minutes) {
			if (iTime.getSeconds() == seconds) {
				return 1;
			}
		}
	}
	else
		return 0;
}


// main func - instantiates two time object, compares and prints results using operator== overloaded function, compare with 1 argument and compare function with 3 arguments
int main() {
	Time time1; // initiate time object with no parameters
	Time time2(4, 20, 35); // initiate time object with values
	int localHours, localMinutes, localSeconds; // local time variables

	// diplay times
	cout << "Time 1: ";
	time1.displayTime12();
	cout << "Time 1: ";
	time1.displayTime24();
	cout << "Time 2: ";
	time2.displayTime12();
	cout << "Time 2: ";
	time2.displayTime24();

	// compare check with operator== overloaded function
	if (time1 == time2)
		cout << "Operator== : Times are equal" << endl;
	else
		cout << "Operator== : Times are not equal" << endl;

	localHours = time1.getHours();
	localMinutes = time1.getMinutes();
	localSeconds = time1.getSeconds();

	// compare check with compare function with 3 arguments
	if (time2.compare(localHours, localMinutes, localSeconds) == 1)
		cout << "Compare 3 arg : Times are equal." << endl;
	else
		cout << "Compare 3 arg : Times are not equal." << endl;

	// compare check with compare function with 1 argument
	if (time1.compare(time2) == 1)
		cout << "Compare 1 arg : Times are equal." << endl;
	else
		cout << "Compare 1 arg : Times are not equal" << endl;


	// repeat after setting values equal
	time1 = time2;
	cout << " ---------------- " << endl;

	cout << "Time 1: ";
	time1.displayTime12();
	cout << "Time 1: ";
	time1.displayTime24();
	cout << "Time 2: ";
	time2.displayTime12();
	cout << "Time 2: ";
	time2.displayTime24();

	if (time1 == time2)
		cout << "Operator== : Times are equal" << endl;
	else
		cout << "Operator== : Times are not equal" << endl;

	localHours = time1.getHours();
	localMinutes = time1.getMinutes();
	localSeconds = time1.getSeconds();

	if (time2.compare(localHours, localMinutes, localSeconds) == 1)
		cout << "Compare 3 arg : Times are equal." << endl;
	else
		cout << "Compare 3 arg : Times are not equal." << endl;

	if (time1.compare(time2) == 1)
		cout << "Compare 1 arg : Times are equal." << endl;
	else
		cout << "Compare 1 arg : Times are not equal" << endl;


	system("pause");
}

