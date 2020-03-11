#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left, * right;
	Node(int x) : data(x), left(NULL), right(NULL) {}

};

Node* insert(Node* node, int value);
Node* search(Node* node, int value);
void inorder(Node* node);
void postorder(Node* node);
void preorder(Node* node);

int main() {
	Node* root = NULL;
	root = insert(root, 50);
	/*
	insert(root, 30);
	insert(root, 60);
	insert(root, 70);
	insert(root, 65);
	*/

	int choice;
	int num;
	
	while (1) {
		cout << "-------\n1) Insert\n2) Search\n3) Inorder print\n4) PreOrder print\n5) Postorder Print\n0 to quit" << endl;
		cin >> choice;
		switch (choice) {



		case 1: {
			cout << "Enter a number to insert: ";
			cin >> num;
			insert(root, num);
			break;
		}
		case 2: {
			cout << "Enter a number to search: ";
			cin >> num;
			Node* srch = search(root, num);
			if (srch == NULL) {
				cout << num << " not found" << endl;
			}
			else {
				cout << num << " found." << endl;
			}
			break;
		}
		case 3: {
			inorder(root);
			cout << endl;
			break;
		}
		case 4: {
			preorder(root);
			cout << endl;
			break;
		}
		case 5: {
			postorder(root);
			cout << endl;
			break;
		}
		case (0): {
			exit(1);
		}
		}
	}

}

Node* insert(Node* node, int value) {
	// If passed node is null, return a new node w/ value to caller
	if (node == NULL) {
		return (new Node(value));
	}

	if (node->data < value) {		// If value is greater than node
		node->right = insert(node->right, value);
	}
	else if (value < node->data) {	// If value is less than node
		node->left = insert(node->left, value);
	}

	// If none of the above pass, then return an unchanged node
	return node;
}

Node* search(Node* node, int value) {
	// If node is null or matches what we're searching for, return the node
	if (node == NULL || node->data == value) {
		return node;
	}

	if (value < node->data) {
		return search(node->left, value);
	}
	return search(node->right, value);
}

void inorder(Node* node) {
	if (node == NULL) return;
	inorder(node->left);
	cout << node->data << " ";
	inorder(node->right);
}

void postorder(Node* node) {
	if (node == NULL) return;
	inorder(node->left);
	inorder(node->right);
	cout << node->data << " ";
}

void preorder(Node* node) {
	if (node == NULL) return;
	cout << node->data << " ";
	inorder(node->left);
	inorder(node->right);
	
}