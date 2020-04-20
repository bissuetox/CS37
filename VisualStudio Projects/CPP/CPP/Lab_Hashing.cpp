#include <iostream>
using namespace std;
const int SIZE = 27;
const int EMPTY = -1;

class HashTable {
private:
	int table[SIZE];

	int hash(int data) {
		return data % SIZE;
	}



public:
	// Constructor that sets all elements to -1 (empty)
	HashTable() {
		for (int i = 0; i < SIZE; i++) {
			table[i] = -1;
		}
	}

	// Add function to insert an int into the table
	bool add(int data) {
		int index = hash(data);

		// If table at index is empty, insert data
		if (table[index] == EMPTY) {
			//cout << "Initial: Inserting " << data << " into index " << index << endl;	// DEBUG
			table[index] = data;
			return true;
		}
		// Else probe to next index
		int probe = (index + 1) % SIZE;

		while (index != probe) {
			//cout << "Probing to index " << probe << endl;	// DEBUG
			// If probe index is empty insert
			if (table[probe] == EMPTY) {
				//cout << "Probe: Inserting " << data << " into index " << probe << endl;	// DEBUG
				table[probe] = data;
				return true;
			}
			// Else iterate probe index and check again
			probe = ++probe % SIZE;
		}
		// This is hit if the while loop exits - AKA no empty spots were hit
		cout << "Table is full!" << endl;
	}

	// Lookup function
	int hashLookup(int data) {
		for (int i = 0; i < SIZE; i++) {
			if (table[i] == data) {
				return i;
			}
		}
		return EMPTY;	// Else return -1 (empty)
	}
};

int main() {
	HashTable table;

	while (1) {
		int choice, value;
		cout << endl << "<====================>" << endl;
		cout << "1. Add value\n2. Lookup Value\n3. Exit\n";
		cin >> choice;
		switch (choice) {
			case(1): {
				cout << "Enter value to add: ";
				cin >> value;
				table.add(value);
				break;
			}
			case(2): {
				cout << "Enter value to lookup: ";
				cin >> value;
				int result = table.hashLookup(value);
				if (result == -1) cout << "Value not found." << endl;
				else {
					cout << value << " found at index " << result << endl;
				}
				break;
			}
			case(3): {
				return 0;
			}
		}
	}
}
