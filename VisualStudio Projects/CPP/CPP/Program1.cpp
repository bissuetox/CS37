#include <iostream>
#include <string>
#define NUM_EXPRESSIONS 40
#define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT (x) cout << x << endl
#else
#define DEBUG_PRINT (x) do {} while (0)
#endif
using namespace std;



class Node {	// Node Class definition
public:
	Node();
	float value;	// Value declaration
	Node* next;	// Next pointer declaration
};

Node::Node() : value(0), next(NULL) {}

class NodeStack {
public:
	void push(float fValue);
	float pop();
	float peek();
	int isEmpty();
	Node *TOS;
};

void NodeStack::push(float fValue) {
	Node* new_node = new Node();	// Create new node
	new_node->value = fValue;		// Set passed value into new node
	new_node->next = TOS;			// Set new node pointer to old TOS position (previous TOS element)
	TOS = new_node;					// Set new TOS position to new node
}

int NodeStack::isEmpty() {
	return TOS == NULL;			// Returns 1 if TOS pointer is null, 0 if it points to something
}

float NodeStack::peek() {
	if (!isEmpty()) {			// If stack is not empty
		return TOS->value;		// Return TOS value
	}
	else {
		cout << "Stack is empty!" << endl;
		//exit(1);				// Else exit program
	}
}

float NodeStack::pop() {
	if (!isEmpty()) {									// If stack is not empty
		//Node* temp = TOS;								// Copy the current TOS object into temp
		float temp = TOS->value;
		TOS = TOS->next;								// Set the TOS to the next object in stack
		//cout << "Returned " << temp << endl;			// Debug cout	
		return temp;									// Return the temp node
	}
	else {
		cout << "Stack is empty!" << endl;
		// exit(1)
	}
}

void tokenize(string tokens[], string input);			// Prototype
void rpExpression(NodeStack& stack, string tokens[]);	// Prototype
int isOperator(string str);

int main() {
	NodeStack stack;
	string tokens[NUM_EXPRESSIONS] = {};
	string input;

	cout << "Enter Reversh Polish Expression: " << endl;
	getline(cin, input);

	tokenize(tokens, input);

	rpExpression(stack, tokens);

}

void tokenize(string tokens[], string input) {
	string delimiter = " ";								// Delimiter
	size_t start = 0;									// Index of start of word
	size_t end = input.find(delimiter);					// index of end of word
	int i = 0;											// Declare i outside of for loop
	while (end != string::npos) {						// While end index isn't at end of string
		tokens[i] = input.substr(start, end - start);	// Set i-th tokens array element to token
		start = end + delimiter.length();				// Set start of word to 1 after the space 
		end = input.find(delimiter, start);				// Set end to index of next space 
		i++;											// Manually iterate i
	}
	tokens[i] = input.substr(start, end - start);		// Manual assignment to final element since for loop stops after last check
}

void rpExpression(NodeStack& stack, string tokens[]) {
	size_t operators = 0, operands = 0;
	int i = -1;
	string error = "";

	string current_token;
	do {
		i++;													// Iterate i manually
		current_token = tokens[i];								// Set current token to ith token

		if (isOperator(current_token)){							// If operator is hit
			float num1 = stack.pop();
			float num2 = stack.pop();
			if (current_token == "+") {							// If + operator, add and push result
				stack.push(num1 + num2);
			}
			else if (current_token == "-") {
				stack.push(num1 - num2);
			}
			else if (current_token == "*") {
				stack.push(num1 * num2);
			}
			else if (current_token == "/") {
				if (num2 == 0) {
					error = "Error: Divide by 0!";
				}
			}
		}
		else if (tokens[i] == "="){
			break;
		}
		else {
			// stack.push(stof(current_token));
			cout << "pushed " << stof(current_token) << endl;
			operands++;
		}
	} while (current_token != "=" && i != NUM_EXPRESSIONS);
}

	int isOperator(string str) {
		return (str == "+" || str == "-" || str == "*" || str == "/");
	}

	/*
	while "=" hasnt been hit
		if an operator & operands = 2
			pop last two into a and b
			switch (operator)
				case +
					add them and push back to stack

				case -
					subtract them and push back to stack

				case /
					check divide by zero
						throw exception if caught
					divide themand push back to stack

				case *
				multiply them and push back to stack
		else if a number
			convert to float
			push to stack
			operands ++ 
		i++

	pop "=" and print the result
	*/