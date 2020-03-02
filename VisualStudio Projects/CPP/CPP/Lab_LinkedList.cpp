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

void printNodes(Node* front);

int main() {
	int input;
	Node* frontNode = NULL;
	cout << "Enter a number: ";
	cin >> input;
	while (input != -1) {						// While user has not typed -1
		Node* newNode = new Node(input);		// Instantiate new node
		newNode->next = frontNode;				// Set new node's next to the front node(remains null if front node is NULL)
		frontNode = newNode;					// set front node to the new node
		cout << "Enter a number: ";
		cin >> input;
	}
	printNodes(frontNode);						// Print all the nodes
}

void printNodes(Node* front) {
	while (front != NULL) {
		cout << front->data << " ";
		front = front->next;
	}
}