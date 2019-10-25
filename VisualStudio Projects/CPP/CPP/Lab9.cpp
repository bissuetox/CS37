#include <iostream>
#include <string>
#include <fstream>
#define sCount 3
using namespace std;

class Student {
private:
	string name;
	float grade;
public:
	Student();
	Student(string iname, float igrade);
	void setName(const string& iname);
	void setGrade(const float& igrade);
	string getName();
	float getGrade();
};

// default constructor
Student::Student() {
	name = "";
	grade = 0;
}

Student::Student(string iname, float igrade) {
	name = iname;
	grade = igrade;
}

// setter for name
void Student::setName(const string& iname) {
	name = iname;
}

// getter for grade
void Student::setGrade(const float& igrade) {
	grade = igrade;
}

// getter for name
string Student::getName() {
	return name;
}

// getter for grade
float Student::getGrade() {
	return grade;
}

void displayInfo(Student students[]);

int main() {
	ofstream fileOut("C:\\Users\\jovin\\Documents\\School\\CPP\\CS37\\Lab9.txt");
	Student students[3];

	if (fileOut.is_open()) {

		// for loop that prompts user for info and writes it into the file
		for (int i = 0; i < sCount; i++) {
			string tempName;
			float tempGrade;
			cout << "Enter name: ";
			getline(cin, tempName);
			cout << "Enter grade: ";
			cin >> tempGrade;
			cin.ignore();


		}
	}
	else {
		cerr << "File not open!" << endl;
		exit(1);
	}

		ifstream fileIn("C:\\Users\\jovin\\Documents\\School\\CPP\\CS37\\Lab9.txt");


		if (fileIn.good()) {
			// loops and etracts data from file into arrays
			for (int j = 0; j < sCount; j++) {
				string tempName[3];
				float tempGrade[3];

				getline(fileIn, tempName[j]);
				fileIn >> tempGrade[j];
				fileIn.ignore();
				students[j].setName(tempName[j]);
				students[j].setGrade(tempGrade[j]);
			}
		}
		else {
			cerr << "File not open!" << endl;
			exit(1);
		}


	displayInfo(students);
	


}

// function to print info
void displayInfo(Student students[]) {
	for (int k = 0; k < sCount; k++) {
		cout << "Name: " << students[k].getName() << endl;
		cout << "Grade: " << students[k].getGrade() << endl << endl;
	}
}

