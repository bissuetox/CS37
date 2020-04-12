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
/*
Depth First Search without recursion (iterative)

void BST::preOrder() {
	// First check if root is not null (empty tree)
	if (root == NULL) {
		cout << "Tree is empty!" << endl;
		return;
	}

	cout << "Preorder Traversal:" << endl;
	stack<Node*> s;
	s.push(root);


	while (!s.empty()) {
		Node* current = s.top();
		s.pop();

		cout << current->name << " - " << current->weight << endl;

		if (current->right != NULL) {
			s.push(current->right);
		}

		if (current->left != NULL) {
			s.push(current->left);
		}
	}
	cout << endl;
}

void BST::inOrder() {
	// Check if the root is null first
	if (root == NULL) {
		cout << "Tree is empty!" << endl;
		return;
	}

	cout << "Inorder Traversal:" << endl;
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
			cout << current->name << " - " << current->weight << endl;

			// Now iterate to the right side
			current = current->right;
		}

	}
	cout << endl;
}

void BST::postOrder() {
	stack<Node*> s;
	s.push(root);

	cout << "Postorder Traversal:" << endl;
	stack<Node*> output;

	while (!s.empty()) {
		Node* current = s.top();
		s.pop();

		output.push(current);

		if (current->left != NULL) {
			s.push(current->left);
		}

		if (current->right != NULL) {
			s.push(current->right);
		}
	}

	while (!output.empty()) {
		cout << output.top()->name << " - " << output.top()->weight << endl;
		output.pop();
	}
	cout << endl;
}

*/