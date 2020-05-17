#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#define TABLE_SIZE 100
#define TOKEN_SIZE 15
#define FILE_NAME "P42.txt"
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
	int scope, lineNum;

public:
	BORG() {
		scope = 0;
		lineNum = 1;
	}

	void execute(const char* fileName);
	void process(ifstream &fileIn, HashTable &ht);
	int expression(int num1, int num2, string op);
};

void BORG::execute(const char* fileName) {
	ifstream fileIn(fileName);
	string tempLine;
	int lineNum = 1;

	if (!fileIn.is_open()) {
		cerr << "Could not open file!" << endl;
		exit(1);
	}

	// Base level hash table
	HashTable initialHT;
	process(fileIn, initialHT);
}

void BORG::process(ifstream &fileIn, HashTable &ht) {
	string tokens[TOKEN_SIZE], strLine, tempTok;

	while (!fileIn.eof()) {
		for (int i = 0; i < TOKEN_SIZE; i++) {
			tokens[i] = "";
		}
		getline(fileIn, strLine);
		
		istringstream iss(strLine);
		for (int i = 0; getline(iss, tempTok, ' '); (tempTok == "") ? i : i++) {
			tokens[i] = tempTok;
		}
		string keyword = tokens[0];

		if (keyword == "START") {
			HashTable newHT = ht;
			process(fileIn, newHT);						// Enter new scope with duplicate of hash table
		}
		else if (keyword == "FINISH") {
			return;										// Exit out of process function
		}
		else if (keyword == "COM") {
			continue;									// Comment - do nothing
		}
		else if (keyword == "VAR") {					// Var declaration with current scope #
			string key = tokens[1];
			int val = stoi(tokens[3]);
			if (ht.keyExists(key, scope)) {
				ht.keyUpdate(key, val, scope);
			}
			else {
				ht.keyInsert(key, val, scope);
			}
		}

		else if (ht.keyExists(keyword, scope)) {	// General var handling,
			if (tokens[1] == "=") {					// var = value - update value
				if (tokens[3] == "") {				// No expression after variable
					ht.keyUpdate(keyword, stoi(tokens[2]), scope);
				}
				else {								// Expression after variable
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
		lineNum++;
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
Program Specification:

Build a hash table using chaining as the collision resolution technique. keyInsertions into the hash table will correspond to declarations of
variables and values in a program, searches will be requests for the value of a variable. Some variables will be local and have a narrow scope while some variables will be global.

The program will take input from a file, another program written in the omnipotent programming language BORG (Bionicly Omnipotent Resistance Grinders)
and generate output from this program.

The BORG language has the following commands (keywords):

1)START-FINISH blocks. Indicating different scopes.
2)COM - Single line comments: Text should be ignored if on the same line
3) VAR varName – Variable Declaration, adds “varName” to the hash table.
4) variable = expression – Assignment statements, ie GEORGE = 122. Find GEORGE in the hash table and assign 122 to it.
5) ++ - increment operator, syntax: VARIABLE ++
6) -- - decrement operator, syntax: VARIABLE --
7) expressions, expressions are limited to unary and binary arithmetic, or variable names
8) supported operators: +  -  /  *  %  ^ (plus, minus, divide, multiple, modulo, exponent)
9) PRINT – syntax PRINT expression. If the expression is a variable, and this variable is not in scope, then an error message indicating unknown variable x at line number y.
The value printed if there is a variable in scope should be the variable with the closest scope.
10) Errors – other than the print statements, our interpreter will not be responsible for detecting errors, syntax errors should
be disregarded if encountered, assume that the source file is correct.

Our hash function: sum the ordinal values of the characters of the variable multiplied by their position in the string (1-indexing), then taking the modulo by TABLESIZE.

The variable ABC = (65 * 1 + 66 * 2 + 67 * 3) % TABLESIZE - pick 100 for table size

All tokens are separated by one space or a new line.

Output: for this assignment, run your interpreter on this sample source program as well as a program of your own, and turn in the output from both, as well
as the source code from your BORG program as well as source code of the assignment and its executable.

X-Credit. Each student may implement one additional feature to the language, such as adding if, methods, more capable print statements.
Only one student may implement a given extension to the language, and each extension must first be cleared with me.

*/