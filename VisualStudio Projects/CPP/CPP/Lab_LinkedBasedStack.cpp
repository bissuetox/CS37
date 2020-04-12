#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int x) {
		next = NULL;
		data = x;
	}
};

class LinkBasedStack {		// Array Base Stack Class Definition
public:
	LinkBasedStack();		// Member Function prototypes
	void push(int x);
	int pop();
	int peek();
	int isEmpty();

private:
	Node* top;
	int count;
};

LinkBasedStack::LinkBasedStack() : count(0), top(NULL) {}	// Constructor def and Initializer list - Count set to 0 - empty

void LinkBasedStack::push(int x) {		// Push Function definition
	if (top == NULL) {
		top = new Node(x);
		cout << "Created stack w/ " << x << endl;
	}
	else {
		Node* temp = new Node(x);			// Place new node on top of stack
		temp->next = top;				
		top = temp;
		cout << "Pushed: " << x << endl;	// Debug Print
	}
	count++;
}

int LinkBasedStack::pop() {						// Pop Function definition
	if (count == 0 || top == NULL) {			// If count is 0
		cerr << "Stack is empty!" << endl;		// Emit error msg
	}
	else {										// If not empty
		int num = top->data;					// Retrieve data from TOS
		count--;								// Decrement count
		Node* del = top;						// Copy TOS address 
		top = top->next;						// Moves TOS down
		delete del;								// Removes previous TOS memory
		cout << "Popped: " << num << endl;		// Debug Print
		return num;								// Return the previous TOS data
	}
}
	
int LinkBasedStack::peek() {								// Peek Function definition
	//cout << "Peek Count: " << count << endl << endl;		// Debug Count
	return top->data;										
}

int LinkBasedStack::isEmpty() {	// Is Empty Function definition
	if (count == 0) {				// If array is empty
		return 1;					// Return 1 (true)
	}
	else {
		return 0;					// Return 0 (false)
	} 
}


int main() {
	LinkBasedStack stack1;
	stack1.push(3);
	stack1.push(5);
	stack1.push(23);

	cout << endl;

	stack1.pop();
	stack1.pop();
	cout << "Peek: " << stack1.peek() << endl;
	cout << "Is empty: " << stack1.isEmpty() << endl;

	stack1.pop();
	cout << "Is empty: " << stack1.isEmpty() << endl;
	stack1.pop();
	 
	return 0;
}