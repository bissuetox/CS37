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

void sortInsert(Node** head_ref, int value);
void printLL(Node* head);

int main() {
	int input;
	Node* head = NULL;

	cout << "Enter an integer: ";
	cin >> input;
	while (input != -1) {
		sortInsert(&head, input);
		cout << "Enter an integer: ";
		cin >> input;
	}
	printLL(head);
}

void sortInsert(Node** head_ref, int value) {
	Node* newNode = new Node(value);
	Node* current = *head_ref;
	if (*head_ref == NULL || value < (*head_ref)->data) {		// If there is no head node or value is less than head node
		newNode->next = (*head_ref);
		*head_ref = newNode;
	}

	else {
		current = *head_ref;
		while (current->next != NULL && value > current->next->data) {
			// Continue iterating until we reach a node where the value is not greater than it's data
			current = current->next;
		}
		newNode->next = current->next;		// Then insert newNode in between that greater node and after current node;
		current->next = newNode;
	}
}

void printLL(Node* head) {
	cout << "Printing LL: " << endl;
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

/*
while check if current node->value is greater than value 
*/