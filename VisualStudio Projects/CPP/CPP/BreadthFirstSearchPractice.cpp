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

int main() {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	BreadthFirstSearch(root);
}

void BreadthFirstSearch(Node* root) {
	queue<Node*> myQueue;

	if (root == NULL) {
		cout << "Root is null." << endl;
		return;
	}

	myQueue.push(root);
	cout << "Pushed " << root->data << endl;
	while (myQueue.size() != 0) {
		Node* traverse = myQueue.front();
		myQueue.pop();
		cout << "traverse: " << traverse->data << endl;
		cout << "Popped: " << traverse->data << endl;
		//cout << traverse->data << " ";
		if (traverse->left != NULL) {
			myQueue.push(traverse->left);
			cout << "Pushed: " << traverse->left->data << endl;
		}
		if (traverse->right != NULL) {
			myQueue.push(traverse->right);
			cout << "Pushed: " << traverse->right->data << endl;
		}
	}
}