#include <iostream>
#include <iomanip>
using namespace std;

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
	int compare(const Time iTime);
};

Time::Time() {
	hours = 0;
	minutes = 0;
	seconds = 0;
}

Time::Time(int ihours, int iminutes, int iseconds) {
	hours = ihours;
	minutes = iminutes;
	seconds = iseconds;
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

int Time::getHours() {
	return hours;
}

int Time::getMinutes() {
	return minutes;
}

int Time::getSeconds() {
	return seconds;
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

