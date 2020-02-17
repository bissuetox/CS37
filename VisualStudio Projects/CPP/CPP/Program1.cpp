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
		//cout << "popped " << temp << endl;			// Debug cout	
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

	while (input != "0") {
		tokenize(tokens, input);
		rpExpression(stack, tokens);
		cout << "Enter Reversh Polish Expression: " << endl;
		getline(cin, input);
	}
	

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
			operators++;
			if (!(operands >= 2)) {								// If operator is hit when there is not more than 2 operators
				error = "Too many operators!";
				break;											// Set error msg and break loop
			}

			float num2 = stack.pop();
			float num1 = stack.pop();							// Pop last two floats off of stack and store in local varibales
			operands = operands - 1;							// Technically remove 2 operands, then add 1 more after below calculations.
			if (current_token == "+") {							// If + operator, add and push result
				stack.push(num1 + num2);
				//cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;		// Debug 
			}
			else if (current_token == "-"){						// If - operator, subtract and push result
				stack.push(num1 - num2);
				//cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;		// Debug 
			}
			else if (current_token == "*") {					// If * operator, multiply and push result
				stack.push(num1 * num2);
				//cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;		// Debug 
			}
			else if (current_token == "/") {					// If / operator, divide and push result
				if (num2 == 0) {
					error = "Error: Division by zero";				// Check for division by zero	
					break;
				}
				stack.push(num1 / num2);
				//cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;		// Debug 
			}
			else {
				cout << "Invalid Operator" << endl;
				exit(1);
			}
			operators--;										// Decrease operators after operation pushed onto stack
		}
		else if (tokens[i] == "="){								// If an equal sign is hit
			break;
		}
		else {													// If a number is hit
			stack.push(stof(current_token));					// Push onto the stack
			//cout << "pushed " << stof(current_token) << endl;	// Debug Print
			operands++;											// Incrase operands
		}
	} while (current_token != "=" && i != NUM_EXPRESSIONS);		// While has not hit & hasn't exceeded the array size in case

	if (operands >= 2) {										// If there are still operands that were not calculated after = was hit
		error = "Too many operands!";
	}

	if (error != "") {											// If error message was not set
		cout << "Error: " << error << endl;
	}
	
	else {														// Else print and pop the last answer - this leaves the stack empty
		cout << stack.pop() << endl;
	}
	//cout << "Operators: " << operators << endl;
	//cout << "Operands: " << operands << endl;
	//cout << "TOS: " << stack.TOS->value << endl;
}

int isOperator(string str) {											// Function to check if a string is an operator
	return (str == "+" || str == "-" || str == "*" || str == "/");
}

/*
OUTPUT
Enter Reversh Polish Expression:
10 15 + =
25
Enter Reversh Polish Expression:
25 35 - 30 * =
-300
Enter Reversh Polish Expression:
2.5 6.6 * =
16.5
Enter Reversh Polish Expression:
6 2 * 50 50 / + =
13
Enter Reversh Polish Expression:
10 30 50 + =
Error: Too many operands!
Enter Reversh Polish Expression:
10 20 * - =
Error: Too many operators!
Enter Reversh Polish Expression:
0
*/