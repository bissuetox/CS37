#include <iostream>
using namespace std;

class Node {
public:
	Node* next;
	int value;

	// Constructor definitions
	Node(int x) {
		next = NULL;
		value = x;
	}
	Node() {
		next = NULL;
		value = 0;
	}
};

class Queue {
public:
	Node* front, * end;
	int count;

	Queue() {
		front = end = NULL;
		count = 0;
	}

	void Enqueue(int data) {
		Node* newNode = new Node(data);
		if (count == 0){
			front = end = newNode;
		}
		else {
			end->next = newNode;
			end = newNode;
		}
		count++;
	}

	int Dequeue() {
		if (count == 0) {
			cout << endl << "Queue is empty!" << endl;
			return -1;
		}

		int value = front->value;

		// Delete front and end data if last item in queue
		if (count == 1) {
			Node* delFront = front, *delEnd = end;
			delete delFront, delEnd;
			front = end = NULL;
		}
		// Else dequeue normally
		else {
			Node* del = front;
			front = front->next;
			delete del;
		}

		count--;
		return value;
	}

	bool isEmpty() {
		return (count == 0) ? true : false;
	}
};

int main() {
	Queue aQueue;
	int choice;
	int value;
	while (1) {
		cout << endl << "1. Enqueue\n2. Dequeue\n3. IsEmpty\n4. Exit" << endl;
		cin >> choice;
		switch (choice) {
			case(1): {
				cout << "Enter value to enqueue: ";
				cin >> value;
				aQueue.Enqueue(value);
				break;
			}
			case(2): {
				value = aQueue.Dequeue();
				if (value == -1) break;
				cout << "Dequeued: " << value << endl;
				break;
			}
			case(3): {
				cout << "Empty: " << (aQueue.isEmpty() ? "Yes" : "No") << endl;
				break;
			}
			case(4): {
				return 0;
			}
		}
	}

}