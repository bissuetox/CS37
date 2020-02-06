#include <iostream>
#include <string>
using namespace std;


class Node {	// Node Class definition
public:
	Node();
	int value;	// Value declaration
	Node* next;	// Next pointer declaration
};

Node::Node() : value(0), next(NULL) {}

class NodeStack {
public:
	void push(int fValue);
	int pop();
	int peek();
	int isEmpty();
	Node *TOS;
};

void NodeStack::push(int fValue) {
	Node* new_node = new Node();	// Create new node
	new_node->value = fValue;		// Set passed value into new node
	new_node->next = TOS;			// Set new node pointer to old TOS position (previous TOS element)
	TOS = new_node;					// Set new TOS position to new node
}

int NodeStack::isEmpty() {
	return TOS == NULL;			// Returns 1 if TOS pointer is null, 0 if it points to something
}

int NodeStack::peek() {
	if (!isEmpty()) {			// If stack is not empty
		return TOS->value;		// Return TOS value
	}
	else {
		cout << "Stack is empty!" << endl;
		//exit(1);				// Else exit program
	}
}

int NodeStack::pop() {
	if (!isEmpty()) {									// If stack is not empty
		//Node* temp = TOS;								// Copy the current TOS object into temp
		int temp = TOS->value;
		TOS = TOS->next;								// Set the TOS to the next object in stack
		cout << "Returned " << temp << endl;			// Debug cout	
		return temp;									// Return the temp node
	}
	else {
		cout << "Stack is empty!" << endl;
		// exit(1)
	}
}

void tokenize(string tokens[], string input);		// Prototype

int main() {
	NodeStack stack;
	string tokens[40];
	string input;

	cout << "Enter Reversh Polish Expression: " << endl;
	getline(cin, input);

	tokenize(tokens, input);


}

void tokenize(string tokens[], string input) {
	string delimiter = " ";


}