#include <iostream>
using namespace std;

class ArrayBasedStack {		// Array Base Stack Class Definition
public:
	ArrayBasedStack();		// Member Functions
	void push(int x);
	int pop();
	int peek();

private:
	const int MaxSize = 10;	// Vars
	int count;				// Count = position of stack starting at 1, 0 is empty
	int sArray[10];
};

ArrayBasedStack::ArrayBasedStack() : MaxSize(10), count(0) {}	// Constructor def and Initializer list - Count set to 0 - empty

void ArrayBasedStack::push(int x) {							// Push Function
	if (count != MaxSize) {									// If count is not at max size
		count++;											// Increase count by 1
		cout << "Count: " << count << endl;					// Debug Display
		sArray[count - 1] = x;								// Set array pos (count - 1) to x
		cout << "Pushed: " << sArray[count - 1] << endl;	// Debug Display
	}
	else {
		throw exception("Stack is full!");					// If count is at max size, throw exception
	}
}

int ArrayBasedStack::pop() {
	if (count == 0) {
		throw exception("Stack is empty!");
	}
	else {
		cout << "Count: " << count << endl;
		count--;
		cout << "Popped: " << sArray[count] << endl;
		return sArray[count];
	}
}

int ArrayBasedStack::peek() {
	cout << "Peek Count: " << count << endl;
	return sArray[count - 1];
}


int main() {
	ArrayBasedStack stack1;
	stack1.push(3);
	stack1.push(5);
	stack1.push(23);

	stack1.pop();
	stack1.pop();
	cout << "Peek: " << stack1.peek() << endl;
	cout << "Peek: " << stack1.peek() << endl;

	stack1.pop();
}