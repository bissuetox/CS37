// Using Vectors and iterators
#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int> &vInts);

int main() {
	vector<int> ivec1;
	int elements, unum;
	cout << "Vector size: " << ivec1.size() << endl; // SIze - member function of vector
	cout << "Capacity: " << ivec1.capacity() << endl; // Capacity - member function of vector
	cout << "How many integers for the vector? (<5) ";
	cin >> elements;

	for (int j = 0; j < elements; j++) {
		cout << "Enter integer #" << j + 1 << ": ";
		cin >> unum;
		ivec1.push_back(unum); // push_back adds an element to array
	}
	cout << "\nVector contains: " << endl;
	print(ivec1);
	cout << "Vector size: " << ivec1.size() << endl;
	cout << "Vector Capacity: " << ivec1.capacity() << endl;

	vector<int> ivec2(ivec1);

	if (ivec1 == ivec2)
		cout << "Vectors are equal." << endl;
	else
		cout << "Vectors are NOT equal." << endl;
	try {
		cout << "Access nonexistent element." << endl;
		cout << ivec1.at(99) << endl;
	}

	catch (out_of_range& vrexception) {
		cout << "Exception: " << vrexception.what() << endl;
	}
}

void print(const vector<int>& vInts) { // vInts is a CONST vector - therefore we need a const iterator
	// Not the preffered method
	cout << "Output using array syntax." << endl;
	for (int i = 0; i < vInts.size(); i++) {
		cout << vInts[i] << " ";
	}
	cout << endl;
	// Preferred method
	cout << "Output using iterator: " << endl;
	// *container we are working on*<type of container>::iterator (pointer) *iterator name*
	vector<int>::const_iterator pIdx; // Since vInts is a const vector, we need a const iterator
	// Not const iterator, but const_interator - const doesn't make it unmodifiable, but qualifies the type of container 
	// the iterator is working on
	for (pIdx = vInts.cbegin(); pIdx != vInts.cend(); pIdx++) {
		// pIdx(pointer) gets set to the beginning of vInts with the begin member function of vector (set to a pointer)
		// vInts.end() - end is set to the vector address AFTER the last member
		cout << *pIdx << " ";
	}
	cout << endl;
}