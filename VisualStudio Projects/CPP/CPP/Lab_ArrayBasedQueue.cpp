#include <iostream>
using namespace std;

class ArrayBasedQueue {
public:
	ArrayBasedQueue();
	void enqueue(int num);
	int dequeue();
	bool isEmpty();
	void printQueue();

private:
	const int maxSize = 10;
	int qArray[10] = {};
	int count, front, back;
};

ArrayBasedQueue::ArrayBasedQueue() : count(0), front(0), back(0) {}
void ArrayBasedQueue::enqueue(int num) {
	if (back == maxSize) {
		cout << "Queue is full!" << endl;
		//back = 0;				// Side note for wrapping around the array. This is confusing? added this method in case, not clear
		//qArray[back] = num;	// Uncomment these lines to make it wrap around?
		return;					
	}
	else {
		qArray[back] = num;									// Set back array element to parameter
		// cout << "Enqueued " << qArray[back] << endl;		// Debug cout
		back++;
		count++;
	}

}

int ArrayBasedQueue::dequeue() {
	if (count == 0) {
		cout << "Queue is empty!" << endl;
		return 0;
	}
	else {
		int returnNum = qArray[front];
		for (int i = 0; i < back - 1; i++) {		
			qArray[i] = qArray[i + 1];				// Shift all elements back 1
		}
		back--;										
		count--;									
		return returnNum;							
	}
}

bool ArrayBasedQueue::isEmpty() {
	if (count == 0) {
		return true;
	}
	else {
		return false;
	}
}

void ArrayBasedQueue::printQueue() {
	cout << "Print Queue: ";
	for (int i = 0; i < count; i++) {
		cout << qArray[i] << " ";
	}
	cout << endl;
}

int main() {
	ArrayBasedQueue aQueue;

	// Testing isEmpty, and check if empty check on dequeue function
	cout << "isEmpty: " << aQueue.isEmpty() << endl;
	aQueue.printQueue();	
	aQueue.dequeue();		
	cout << endl << endl;	

	// Testing enqueue functionality
	aQueue.enqueue(5);
	aQueue.enqueue(7);
	aQueue.enqueue(12);
	aQueue.enqueue(15);
	cout << "isEmpty: " << aQueue.isEmpty() << endl;
	aQueue.printQueue();
	cout << endl;

	aQueue.enqueue(55);
	aQueue.enqueue(25);
	aQueue.enqueue(52);
	aQueue.enqueue(31);
	aQueue.enqueue(125);
	aQueue.enqueue(5151);
	aQueue.printQueue();
	cout << endl;

	// Testing enqueue function check if full
	aQueue.enqueue(25);
	aQueue.printQueue();
	cout << endl;

	cout << "Dequeued: " << aQueue.dequeue() << endl;
	cout << "Dequeued: " << aQueue.dequeue() << endl;
	cout << "Dequeued: " << aQueue.dequeue() << endl;
	aQueue.printQueue();

}