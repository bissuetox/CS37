#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
	int data;
	Node* left, * right;
	Node(int x) {
		data = x;
		left = right = NULL;
	}
};

class BinarySearchTree {
public:
	Node* root;
	void Add(int x);
	void Print();	// Using inorder traversal
	BinarySearchTree() {
		root = NULL;
	}
};

void BinarySearchTree::Add(int x) {
	// Check if root is null, if so then set it
	if (root == NULL) {
		root = new Node(x);
		return;
	}

	// Search is search node, prev keeps track of node before
	Node* search = root, * prev = NULL;

	while (search != NULL) {
		prev = search;
		if (x < search->data) {			// If x is <, iterate left
			search = search->left;
		}
		else if (x > search->data) {	// If x is >, iterate right
			search = search->right;
		}
	}
	
	// Using prev, set the left or right node accordingly
	if (x < prev->data) {
		prev->left = new Node(x);
	}
	else if (x > prev->data) {
		prev->right = new Node(x);
	}
}

// Inorder traversal
void BinarySearchTree::Print() {
	// Check if the root is null first
	if (root == NULL) {
		cout << "Tree is empty!" << endl;
		return;
	}
	
	cout << endl << endl;

	Node* current = root;
	stack<Node*> s;
	// Keep looping while current is not null or the stack is not empty
	while (current != NULL || s.empty() == false) {
		
		// Iterate to the left most node, pushing the nodes onto stack
		if (current != NULL) {
			s.push(current);
			current = current->left;
		}
		else {
			// Current is now NULL, so set it to the top node and pop it
			current = s.top();
			s.pop();

			// Visit the node
			cout << current->data << " ";

			// Now iterate to the right side
			current = current->right;
		}

	}
}

int main() {
	BinarySearchTree bst;
	bst.Add(5);
	bst.Add(10);
	bst.Add(2);
	bst.Add(6);
	bst.Add(7);
	bst.Print();

}