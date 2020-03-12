#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int data;
	Node* left, * right;
	Node(int x) : data(x), left(NULL), right(NULL) {}
};

/*
push root into queue
While queue is not empty
	-remove item from queue
	-visit item (or print or whatever)
	-if left child is not null
		-push left into queue
	-if right child is not null
		-push right into queue
*/
void BreadthFirstSearch(Node* root);
Node* insert(Node* node, int value);

int main() {
	Node* root = NULL;
	root = insert(root, 5);
	root = insert(root, 12);
	root = insert(root, 10);
	root = insert(root, 3);
	root = insert(root, 4);
	root = insert(root, 8);
	root = insert(root, 16);
	root = insert(root, 1);
	BreadthFirstSearch(root);
}

void BreadthFirstSearch(Node* root) {
	queue<Node*> myQueue;

	if (root == NULL) {
		cout << "Root is null." << endl;
		return;
	}

	myQueue.push(root);
	//cout << "Pushed " << root->data << endl;
	while (myQueue.size() != 0) {
		Node* traverse = myQueue.front();
		myQueue.pop();
		//cout << "Popped: " << traverse->data << endl;
		cout << traverse->data << " ";
		if (traverse->left != NULL) {
			myQueue.push(traverse->left);
			//cout << "Pushed: " << traverse->left->data << endl;
		}
		if (traverse->right != NULL) {
			myQueue.push(traverse->right);
			//cout << "Pushed: " << traverse->right->data << endl;
		}
	}
}

Node* insert(Node* node, int value) {
	if (node == NULL) {
		return new Node(value);
	}

	if (value < node->data) {
		node->left = insert(node->left, value);
	}
	else if (value > node->data) {
		node->right = insert(node->right, value);
	}

	// All else fails return unchanged node
	return node;
}