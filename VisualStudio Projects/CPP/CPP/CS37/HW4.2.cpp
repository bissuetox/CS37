#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

// program that retrieves info for 3 students, loads them into a student array, and prints them.

// class with private variables name and grade, public set info and print info
class Student {
private:
	string name;
	float grade;
public:
	void classSet(string outerName, float outerGrade) {
		name = outerName;
		grade = outerGrade;
	}
	void classPrint() {
		cout << "Name: " << name << endl;
		cout << "Grade: " << grade << endl;
	}
};
	

// global function that loops through the student array and retrieves the name and grade of a student
//  and load the data into the student using public function classSet
void globalSet(Student stud[]) {
	string name;
	float grade;

	for (int i = 0; i < 3; i++) {
		cout << "Enter a name: ";
		getline(cin, name);
		cout << "Enter a grade: ";
		cin >> grade;
		cin.ignore();
		stud[i].classSet(name, grade);
	}
}

// global function that loops through the student array and prints their info using the student public function printInfo
void globalDisplay(Student stud[]) {
	for (int i = 0; i < 3; i++) {
		stud[i].classPrint();
	}
}
// main function that declares an array of 3 students, calls global function to populate the private data 
// in the student classes, and prints them
int main() {
	Student studs[3];

	globalSet(studs);
	globalDisplay(studs);

	system("pause");
}