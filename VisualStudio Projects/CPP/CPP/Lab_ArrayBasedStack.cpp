#include <iostream>
using namespace std;

class ArrayBasedStack {
public:
	ArrayBasedStack();
	void push(int x);
	int pop();
	int peek();

private:
	const int MaxSize = 10;
	int count;
	int sArray[10];
};

ArrayBasedStack::ArrayBasedStack() : MaxSize(10), count(0) {}

void ArrayBasedStack::push(int x) {
	if (count != MaxSize) {
		sArray[count] = x;
		cout << "Pushed: " << sArray[count] << endl;
		count++;
	}
	else {
		throw exception("Stack is full!");
	}
}

int ArrayBasedStack::pop() {
	count--;
	cout << "Popped: " << sArray[count] << endl;
	return sArray[count];
}

int ArrayBasedStack::peek() {
	return sArray[count];
}


int main() {
	ArrayBasedStack stack1;
	stack1.push(3);
	stack1.push(5);
	stack1.pop();

	cout << "Peek: " << stack1.peek() << endl;
}