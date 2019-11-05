// Program that creates a Person, Employee and Manager class, then inherits the Person class into the Employee, then Employee into Manager,
// Instantiates two objects, one of employee and another of manager, then prints out the data from two objects.
#include <iostream>
#include <string>
using namespace std;

// Person class definition
class Person {
public:
	// Function prototypes
	Person(const string& first, const string& last, const int& age);
	string getFirst()const;
	string getLast()const;
	int getAge()const;

protected:
	string first, last;
	int age;
};

// Parameterized constructor
Person::Person(const string& fFirst, const string& fLast, const int& fAge) : first(fFirst), last(fLast), age(fAge) {}

// Person Getters
string Person::getFirst()const {
	return first;
}
string Person::getLast()const {
	return last;
}
int Person::getAge()const {
	return age;
}

// Employee Class definition
class Employee : public Person {
public:
	// Function prototypes
	Employee(const string& fFirst, const string& fLast, const int& fAge, const float& fSalary);
	float getSalary()const;
protected:
	float salary;
};

// Employee constructo definition - loads variables into inherited Person member variables
Employee::Employee(const string& fFirst, const string& fLast, const int& fAge, const float& fSalary) : Person(fFirst, fLast, fAge), salary(fSalary) {}

// Salary Getter
float Employee::getSalary()const {
return salary;
}

// Manager class definition - inherits Employee
class Manager : public Employee {
public:
	// Function prototypes
	Manager(const string& fFirst, const string& fLast, const int& fAge, const float& fSalary, const float& fBonus); 
	float getBonus()const;
private:
	float bonus;
};

// Parameterized Constructor - Takes in variables to initialize the inherited Employee member variables,
Manager::Manager(const string& fFirst, const string& fLast, const int& fAge, const float& fSalary, const float& fBonus) : Employee(fFirst, fLast, fAge, fSalary), bonus(fBonus) {}

// Bonus getter
float Manager::getBonus()const {
	return bonus;
}

// Main function
int main() {
	// Instantiate objects of Employee and Manager
	Employee bob("bob", "hematoma", 45, 60000);
	Manager patricia("patricia", "thompson", 50, 80000, 5000);

	// Print info for both objects
	cout << "Employee: " << bob.getFirst() << " " << bob.getLast() << endl;
	cout << "Age: " << bob.getAge() << endl;
	cout << "Salary: " << bob.getSalary() << endl;

	cout << "Manager: " << patricia.getFirst() << " " << patricia.getLast() << endl;
	cout << "Age: " << patricia.getAge() << endl;
	cout << "Salary: " << patricia.getSalary() << endl;
	cout << "Bonus: " << patricia.getBonus() << endl;
}