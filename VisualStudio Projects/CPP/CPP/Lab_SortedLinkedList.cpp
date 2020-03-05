#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next = NULL;
	Node(int x) {
		data = x;
	}
};

void sortInsert(Node* head, int value);

int main() {
	int input;
	Node* head = NULL;

	cout << "Enter an integer: ";
	cin >> input;
	while (input != -1) {
		sortInsert(head, input);
		cout << "Enter an integer: ";
		cin >> input;
	}

}

void sortInsert(Node* head, int value) {
	int previous = -1, current = 0;
	if (head == NULL) {						// If there is no head node, hence list is empty
		Node* newNode = new Node(value);	// Set value to head node
		head = newNode;
	}

	else {
		Node* previous = head;
		Node* current = head->next;

		if (value < head->data) {				// Firstly check if < than head
			Node* newHead = new Node(value);	// If so, replace it 
			
		}
		else {
			while (current != NULL) {
				if (value < current->data) {
					Node* newNode = new Node(value);

				}
			}
		}
		
		


	}
}

/*
while check if current node->value is greater than value 

*/