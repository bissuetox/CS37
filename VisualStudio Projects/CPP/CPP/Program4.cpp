#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#define TABLE_SIZE 100
#define TOKEN_SIZE 50
#define FILE_NAME "Program4Input.txt"
using namespace std;

class Node {
public:
	string key;
	int value, scope;
	Node* next;
	Node(string k, int v, int s) {
		key = k;
		value = v;
		scope = s;
		next = NULL;
	}
};

class HashTable {
private:

	Node* table[TABLE_SIZE];
	int hash(string str) {
		int total = 0;
		for (int i = 0; i < str.size(); i++) {
			total += str.at(i) * (i + 1);
			//cout << str.at(i) << " - " << i + 1 << " -- " << str.at(i) * (i + 1) << endl;
		}
		//cout << "------" << total % TABLE_SIZE << endl;
		return total % TABLE_SIZE;
	}

public:
	// Constructor
	HashTable() {
		for (int i = 0; i < TABLE_SIZE; i++) {
			table[i] = NULL;
		}
	}

	// Deconstructor to free all dynamically allocated memory
	~HashTable() {
		for (int i = 0; i < TABLE_SIZE; i++) {
			delete table[i];
		}
	}

	// Inserts key into hash table - assumes key does not already exist!
	void keyInsert(string str, int val, int scp) {
		int hashed = hash(str);
		Node* current = table[hashed];
		Node* newNode = new Node(str, val, scp);

		// Check if current is empty, and if it is set it
		if (current == NULL) {
			table[hashed] = newNode;
			return;
		}

		// Iterate to empty node (chaining collision resoltion)
		while (current->next != NULL) {
			current = current->next;
		}
		// Set empty node to new node
		current->next = newNode;
	}
	
	// Updates key value passed - assumes key exists!
	void keyUpdate(string str, int val, int scp) {
		int hashed = hash(str);
		Node* current = table[hashed];

		while (current != NULL) {
			if (current->key == str && current->scope <= scp) {
				current->value = val;
				return;
			}
			current = current->next;
		}
		cout << "INVALID FUNCTION USAGE - key not found, no update has occured." << endl;
		exit(1);
	}

	// Adjusts key value by increment
	void keyAdjustment(string str, int direction, int scp) {
		int hashIdx = hash(str);
		Node* current = table[hashIdx];

		while (current != NULL) {
			if (current->key == str && current->scope <= scp) {
				if (direction == 1) {
					current->value++;
					return;
				}
				else if (direction == 0) {
					current->value--;
					return;
				}
			}
		}
	}

	// Returns bool indicating if key exists in hash table
	bool keyExists(string str, int scp) {
		int hashed = hash(str);
		Node* current = table[hashed];

		while (current != NULL) {
			if (current->key == str && current->scope <= scp) {
				return true;
			}
			current = current->next;
		}
		return false;
	}

	// Returns key value
	int keyGet(string str, int scp) {
		int hashed = hash(str);
		Node* current = table[hashed];
		while (current != NULL) {
			if (current->key == str) {
				return current->value;
			}
			current = current->next;
		}
		cerr << "INVALID FUNCTION USAGE - Key not found." << endl;
	}
};

class BORG {
private:
	HashTable ht;
	int scope, lineNum;

public:
	BORG() {
		scope = 0;
		lineNum = 0;
	}

	void execute(const char* fileName);
	void process(string line);
	int expression(int num1, int num2, string op);
};

void BORG::execute(const char* fileName) {
	ifstream fileIn(fileName);
	string tempLine;

	if (!fileIn.is_open()) {
		cerr << "Could not open file!" << endl;
		exit(1);
	}
	while (!fileIn.eof()) {
		getline(fileIn, tempLine);
		//cout << "Read Line: " << tempLine << endl;
		process(tempLine);
		lineNum++;
	}
}

void BORG::process(string line) {
	string tokens[TOKEN_SIZE], temp;
	istringstream iss(line);
	for (int i = 0; getline(iss, temp, ' '); (temp == "") ? i : i++ ){
		tokens[i] = temp;
	}
	string keyword = tokens[0];

	if (keyword == "START") scope++;			// Increase scope #
	else if (keyword == "FINISH") scope--;		// Decrease scope #
	else if (keyword == "COM") {		
		return;									// Comment - do nothing
	}
	else if (keyword == "VAR") {				// Var declaration with current scope #
		string key = tokens[1];
		int val = stoi(tokens[3]);
		ht.keyInsert(key, val, scope);
	}

	else if (ht.keyExists(keyword, scope)) {	// General var handling,

		if (tokens[1] == "=") {					// var = value - update value
			if (tokens[3] == "") {				// No expression
				ht.keyUpdate(keyword, stoi(tokens[2]), scope);
			}
			else {								// Expression
				int result = expression(stoi(tokens[2]), stoi(tokens[4]), tokens[3]);
				ht.keyUpdate(keyword, result, scope);
			}
		}

		else if (tokens[1] == "++") {			// Increment value
			ht.keyAdjustment(keyword, 1, scope);
		}
		else if (tokens[1] == "--") {			// Decrement value
			ht.keyAdjustment(keyword, 0, scope);
		}
	}

	else if (keyword == "PRINT") {
		if (ht.keyExists(tokens[1], scope)) {
			int varValue = ht.keyGet(tokens[1], scope);

			if (tokens[2] == "") {					// No expression after variable
				cout << tokens[1] << " IS " << varValue << endl;
			}
			else {									// Expression after variable
				int result = expression(varValue, stoi(tokens[3]), tokens[2]);
				cout << tokens[1] << " " << tokens[2] << " " << tokens[3] << " IS " << result << endl;
			}
		}
		else {
			cout << tokens[1] << " IS UNDEFINED ON LINE " << lineNum << endl;
		}
	}
}

int BORG::expression(int num1, int num2, string op) {
	int result = 0;
	if (op == "+") {
		result = num1 + num2;
	}
	else if (op == "-") {
		result = num1 - num2;
	}
	else if (op == "*") {
		result = num1 * num2;
	}
	else if (op == "/") {
		result = num1 / num2;
	}
	else if (op == "%") {
		result = num1 % num2;
	}
	else if (op == "^") {
		result = int(pow(num1, num2));
	}

	return result;
}

int main() {
	BORG b;
	b.execute(FILE_NAME);
}

/*
Output Custom
NUM1 IS 50
NUM1 IS 100
NUM2 IS UNDEFINED ON LINE 10
NUM1 IS 101


Output Assignment Sample
BORAMIR IS 25
LEGOLAS IS 101
GANDALF IS UNDEFINED ON LINE 8
BORAMIR * 2 IS 52
GANDALF IS 49
BORAMIR IS 26
GANDALF IS UNDEFINED ON LINE 18
LEGOLAS IS 1000
LEGOLAS IS 1000
LEGOLAS IS 999

Custom Program Syntax
COM HERE IS MY PROGRAM
START
   VAR NUM1 = 50
   PRINT NUM1
   START
	  NUM1 = 100
	  NUM
	  VAR NUM2 = 500
	  PRINT NUM1
   FINISH
   PRINT NUM2
   NUM1 ++
   PRINT NUM1

FINISH
*/