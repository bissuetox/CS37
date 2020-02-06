#include <iostream>
using namespace std;

class ArrayBasedStack {		// Array Base Stack Class Definition
public:
	ArrayBasedStack();		// Member Function prototypes
	void push(int x);
	int pop();
	int peek();
	int isEmpty();

private:
	const int MaxSize;		// Variable declarations
	int count;				// Count = position of top of stack starting at 1, 0 is empty
	int sArray[10];
};

ArrayBasedStack::ArrayBasedStack() : MaxSize(10), count(0) {}	// Constructor def and Initializer list - Count set to 0 - empty

void ArrayBasedStack::push(int x) {							// Push Function definition
	if (count != MaxSize) {									// If count is not at max size
		count++;											// Increase count by 1
		// cout << "Count: " << count << endl;				// Debug Display
		sArray[count - 1] = x;								// Set array element (count - 1) to x
		cout << "Pushed: " << sArray[count - 1] << endl;	// Debug Display
	}
	else {
		throw exception("Stack is full!");					// If count is at max size, throw exception
	}
}

int ArrayBasedStack::pop() {								// Pop Function definition
	if (count == 0) {										// If array is empty
		throw exception("Stack is empty!");					// Throw exception with description 
	}
	else {													// If not empty
		//cout << "Count: " << count << endl;				// Debug Count
		count--;											// Decrease count by 1 - count now = appropriate element in array
		cout << "Popped: " << sArray[count] << endl;		// Debug array element
		return sArray[count];								// Return popped element
	}
}
	
int ArrayBasedStack::peek() {								// Peek Function definition
	//cout << "Peek Count: " << count << endl << endl;		// Debug Count
	return sArray[count - 1];								// Return array element (count - 1)
}

int ArrayBasedStack::isEmpty() {	// Is Empty Function definition
	if (count == 0) {				// If array is empty
		return 1;					// Return 1 (true)
	}
	else {
		return 0;					// Return 0 (false)
	} 
}


int main() {
	ArrayBasedStack stack1;
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
	return 0;
}