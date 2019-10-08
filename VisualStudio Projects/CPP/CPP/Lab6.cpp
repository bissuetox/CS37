#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
	int hours, minutes, seconds;
public:
	Time();
	void setHours(int ihours);
	void setMinutes(int iminutes);
	void setSeconds(int iseconds);
	void displayTime24();
	void displayTime12();
};

Time::Time() {
	hours = 0;
	minutes = 0;
	seconds = 0;
}

void Time::setHours(int ihours) {
	hours = ihours;
}

void Time::setMinutes(int iminutes) {
	minutes = iminutes;
}

void Time::setSeconds(int iseconds) {
	seconds = iseconds;
}

void Time::displayTime24() {
	cout << hours << ":" << minutes << ":" << setw(2) << setfill('0') << seconds << endl;
}

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

int main() {
	Time currentTime;
	int tempHours, tempMinutes, tempSeconds;

	for (int i = 0; i < 4; i++) {
		cout << "Enter hours, minutes and seconds: ";
		cin >> tempHours >> tempMinutes >> tempSeconds;
		currentTime.setHours(tempHours);
		currentTime.setMinutes(tempMinutes);
		currentTime.setSeconds(tempSeconds);

		currentTime.displayTime24();
		currentTime.displayTime12();
	}

	system("pause");
}

