#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left, *right;
	Node(int x) : data(x), left(NULL), right(NULL) {}

};

void preOrder(Node* node);
void inOrder(Node* node);
void postOrder(Node* node);


int main() {
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	cout << "\npre-order: ";
	preOrder(root);

	cout << "\nIn-Order: ";
	inOrder(root);

	cout << "\nPost-Order: ";
	postOrder(root);
}

void preOrder(Node* node) {
	if (node == NULL) {
		return;
	}
	// Preorder is VLR - visit, left, right
	cout << node->data << " ";	// Visit
	preOrder(node->left);		// Left
	preOrder(node->right);		// Right
	// The recursion goes until it hits the leaf of that branch
}

void inOrder(Node* node) {
	if (node == NULL) {
		return;
	}
	// Inorder is LVR - left, visit, right
	inOrder(node->left);
	cout << node->data << " ";
	inOrder(node->right);
}

void postOrder(Node* node) {
	if (node == NULL) {
		return;
	}
	// Postorder is LRV

	postOrder(node->left);
	postOrder(node->right);
	cout << node->data << " ";
}

