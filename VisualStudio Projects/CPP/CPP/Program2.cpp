#include <iostream>
#include <string>
#define PPL_CNT 15
using namespace std;

// Node class definition
struct Node {
	Node* nameNext, * weightNext;
	string name;
	int weight;
	
	Node(string n, int w) {
		nameNext = weightNext = NULL;
		name = n;
		weight = w;
	}
};

// Global function prototypes
void sortInsert(Node** name_head, Node** weight_head, string fName, int fWeight);
void namePrint(Node* head);
void weightPrint(Node* head);
void getData(Node** name_head, Node** weight_head);

int main() {
	Node* name_head = NULL, *weight_head = NULL;
	getData(&name_head, &weight_head);
	namePrint(name_head);
	weightPrint(weight_head);
	system("pause");
}

// Global function definitions
void sortInsert(Node** name_head, Node** weight_head, string fName, int fWeight) {
	Node* newNode = new Node(fName, fWeight);
	Node* name_cur = *name_head;
	Node* weight_cur = *weight_head;

	// Name sort
	if (*name_head == NULL || fName < (*name_head)->name) {							// If no head node or name is before head name
		newNode->nameNext = (*name_head);
		*name_head = newNode;
	}
	else {
		while (name_cur->nameNext != NULL && name_cur->nameNext->name < fName) {	// While the current name should come after the new name
			name_cur = name_cur->nameNext;											// Iterate the current node
		}
		newNode->nameNext = name_cur->nameNext;										// Insert the new node after current
		name_cur->nameNext = newNode;
	}

	// Weight Sort
	if (*weight_head == NULL || fWeight < (*weight_head)->weight) {					// If no head node or name is before head name
		newNode->weightNext = (*weight_head);
		*weight_head = newNode;
	}
	else {
		while (weight_cur->weightNext != NULL && weight_cur->weightNext->weight < fWeight) {	// While the current name should come after the new name
			weight_cur = weight_cur->weightNext;												// Iterate the current node
		}
		newNode->weightNext = weight_cur->weightNext;											// Insert the new node after current
		weight_cur->weightNext = newNode;
	}

}
void namePrint(Node* head) {
	cout << "Names and Weights sorted (ascending) by name: " << endl;
	while (head != NULL) {
		cout << head->name << " - " << head->weight << ", ";
		head = head->nameNext;
	}
	cout << endl;
}
void weightPrint(Node* head) {
	cout << "Names and Weights sorted (ascending) by weight: " << endl;
	while (head != NULL) {
		cout << head->name << " - " << head->weight << ", ";
		head = head->weightNext;
	}
	cout << endl;
}
void getData(Node** name_head, Node** weight_head) {
	string name; 
	int weight;
	cout << "Enter name and weight on separate lines: " << endl;
	for (int i = 0; i < PPL_CNT; i++) {
		getline(cin, name);
		cin >> weight;
		cin.ignore();
		sortInsert(name_head, weight_head, name, weight);
	}
}