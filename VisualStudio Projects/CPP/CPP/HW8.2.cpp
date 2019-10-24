#include <iostream>
#include <string>
using namespace std;

// date class definition
class Date {
private:
	int day, month, year;
public:
	Date();
	Date(const int iday, const int imonth, const int iyear);
	int getDay()const;
	int getMonth()const;
	int getYear()const;
	void setDay(int iday);
	void setMonth(int imonth);
	void setYear(int iyear);
	friend ostream& operator<<(ostream& output, const Date funcDate);
};

// date default constructor
Date::Date() {
	day = 0;
	month = 0;
	year = 0;
}

// date parameterized constructor
Date::Date(int iday, int imonth, int iyear) {
	day = iday;
	month = imonth;
	year = iyear;
}

// getters
int Date::getDay()const {
	return day;
}

int Date::getMonth()const {
	return month;
}

int Date::getYear()const {
	return year;
}

// setters
void Date::setDay(int iday) {
	day = iday;
}

void Date::setMonth(int imonth) {
	month = imonth;
}

void Date::setYear(int iyear) {
	year = iyear;
}

// time class definition
class Time {
private:
	int hour, minute, second;
public:
	Time();
	Time(const int ihour, const int iminute, const int isecond);
	int getHour()const;
	int getMinute()const;
	int getSecond()const;
	void setHour(int ihour);
	void setMinute(int iminute);
	void setSecond(int isecond);
	friend ostream& operator<<(ostream& output, const Time funcTime);
};

// time default constructor
Time::Time() {
	hour = 0;
	minute = 0;
	second = 0;
}

// time parameterized constructor
Time::Time(int ihour, int iminute, int isecond) {
	hour = ihour;
	minute = iminute;
	second = isecond;
}

// getters
int Time::getHour()const {
	return hour;
}

int Time::getMinute()const {
	return minute;
}

int Time::getSecond()const {
	return second;
}

// setters
void Time::setHour(int ihour) {
	hour = ihour;
}

void Time::setMinute(int iminute) {
	minute = iminute;
}

void Time::setSecond(int isecond) {
	second = isecond;
}

//event class definition
class Event {
private:
	string description;
	Date classDate;
	Time classTime;
public:
	Event(string idescription, int iday, int imonth, int iyear, int ihour, int iminute, int isecond);
	Event(string idescription, Date funcDate, Time funcTime);
	friend ostream& operator<<(ostream& output, Event funcEvent);
};

// event individual parameter constructor definition
Event::Event(string idescription, int iday, int imonth, int iyear, int ihour, int iminute, int isecond) {
	description = idescription;
	classDate.setDay(iday);
	classDate.setMonth(imonth);
	classDate.setYear(iyear);
	classTime.setHour(ihour);
	classTime.setMinute(iminute);
	classTime.setSecond(isecond);
}

// event constructor definition with date and time classes in parameters
Event::Event(string idescription, Date funcDate, Time funcTime) {
	description = idescription;
	classDate.setDay(funcDate.getDay());
	classDate.setMonth(funcDate.getMonth());
	classDate.setYear(funcDate.getYear());
	classTime.setHour(funcTime.getHour());
	classTime.setMinute(funcTime.getMinute());
	classTime.setSecond(funcTime.getSecond());
}

// operator << overloaded function definition that prints date in format mm/dd/yy
// friend of the date function
ostream& operator<<(ostream& output, Date funcDate) {
	output << funcDate.month << " / " << funcDate.day << " / " << funcDate.year;
	return output;
}

// operator << overloaded function defintiion that prints time in format hh:mm:ss
// friend of the time function
ostream& operator<<(ostream& output, Time funcTime) {
	output << funcTime.hour << ":" << funcTime.minute << ":" << funcTime.second;
	return output;
}

// operator << overloaded function definition that prints the even data
// 
ostream& operator<<(ostream& output, Event funcEvent) {
	output << "Event description: " << funcEvent.description << endl;
	output << "Event Date: " << funcEvent.classDate << endl;
	output << "Event Time: " << funcEvent.classTime << endl;
	return output;
}

// main function
int main() {
	string tempDescription;
	int tempDay, tempMonth, tempYear, tempHour, tempMinute, tempSecond;

	cout << "Enter event name: ";
	getline(cin, tempDescription);
	cout << "Enter Day: ";
	cin >> tempDay;
	cout << "Enter Month: ";
	cin >> tempMonth;
	cout << "Enter Year: ";
	cin >> tempYear;
	cout << "Enter Hour: ";
	cin >> tempHour;
	cout << "Enter Minute: ";
	cin >> tempMinute;
	cout << "Enter Second: ";
	cin >> tempSecond;

	Event event1(tempDescription, tempDay, tempMonth, tempYear, tempHour, tempMinute, tempSecond);

	Date date1(tempDay, tempMonth, tempYear);
	Time time1(tempHour, tempMinute, tempSecond);
	Event event2(tempDescription, date1, time1);

	cout << "-----Event 1-----" << endl << event1;
	cout << "-----Event 2----- " << endl << event2;

}

