#include <iostream>
#include <string>
#include <stack>
#include <list>
using namespace std;

class Node {
public:
	string name;
	int weight;
	Node* left, * right;
	Node(string fName, int fWeight) {
		name = fName;
		weight = fWeight;
		left = right = NULL;
	}
};

class BST {
public:
	Node* root;
	void preOrder(Node* node);
	void inOrder(Node* node);
	void postOrder(Node* node);
	void addNode(string fName, int fWeight);
	void getData();
	int getHeight(Node* node);
	int getLeafCount(Node* node);
	void searchName(string fName);
	void lowestWeight();
	void firstAlphaName();

	BST() {
		root = NULL;
	}
};

void BST::preOrder(Node* node) {
	if (node == NULL) {
		return;
	}

	// Preorder is VLR - visit, left, right
	cout << node->name << " - " << node->weight << endl;
	preOrder(node->left);		// Left
	preOrder(node->right);		// Right
	// The recursion goes until it hits the leaf of that branch
}

void BST::inOrder(Node* node) {
	if (node == NULL) {
		return;
	}
	// Inorder is LVR - left, visit, right
	inOrder(node->left);
	cout << node->name << " - " << node->weight << endl;
	inOrder(node->right);
}

void BST::postOrder(Node* node) {
	if (node == NULL) {
		return;
	}
	// Postorder is LRV

	postOrder(node->left);
	postOrder(node->right);
	cout << node->name << " - " << node->weight << endl;
}

void BST::addNode(string fName, int fWeight) {
	// Check if root is null, if so then set it
	if (root == NULL) {
		root = new Node(fName, fWeight);
		return;
	}

	// Search is search node, prev keeps track of node before
	Node* search = root, * prev = NULL;

	while (search != NULL) {
		prev = search;
		if (fName < search->name) {			// If x is <, iterate left
			search = search->left;
		}
		else if (fName > search->name) {	// If x is >, iterate right
			search = search->right;
		}
	}

	// Using prev, set the left or right node accordingly
	if (fName < prev->name) {
		prev->left = new Node(fName, fWeight);
	}
	else if (fName > prev->name) {
		prev->right = new Node(fName, fWeight);
	}
}

void BST::getData() {
	string name;
	int weight;
	for (int i = 0; i < 15; i++) {
		cout << "Enter name and weight on separate lines." << endl;
		getline(cin, name);
		cin >> weight;
		cin.ignore();
		addNode(name, weight);
	}
}

int BST::getHeight(Node* node) {
	// If recursion hits a null node, return 0
	if (node == NULL) {
		return 0;
	}
	else {
		// Recurse through left and right nodes
		int lHeight = getHeight(node->left);
		int rHeight = getHeight(node->right);
		
		// Return the bigger height + 1
		if (lHeight > rHeight) {
			return (lHeight + 1);
		}
		else {
			return (rHeight + 1);
		}
	}
}

int BST::getLeafCount(Node* node) {
	// If passed node is null, return 0 and continue to else statements
	if (node == NULL) {
		return 0;
	}
	// Check if both children are null, if so, leaf is found and return 1
	else if (node->left == NULL && node->right == NULL) {
		return 1;
	}
	// Else recursively check both children nodes for leafs
	else {
		return getLeafCount(node->left) + getLeafCount(node->right);
	}
}

void BST::searchName(string fName) {
	Node* current = root;

	// While a null node is not hit
	while (current != NULL) {
		// If name is found
		if (current->name == fName) {
			cout << "Weight of " << fName << ": " << current->weight << endl;
			return;
		}

		// If name is < the current name, traverse left
		if (fName < current->name) {
			current = current->left;
		}
		else {
			// Else traverse right
			current = current->right;
		}

	}
	// If name is not found
	cout << fName << " not found in tree." << endl;
}

void BST::lowestWeight() {
	if (root == NULL) {
		cout << "Tre is empty!" << endl;
		return;
	}

	stack<Node*> s;
	stack<Node*> output;
	s.push(root);
	Node* lowest = root;

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
		if (output.top()->weight < lowest->weight) {
			lowest = output.top();
		}
		output.pop();
	}
	cout << "Lowest weight: " << lowest->name << " - " << lowest->weight << endl;
}

void BST::firstAlphaName() {
	// Firstly check if the tree is populated
	if (root == NULL) {
		cout << "Tree is empty!" << endl;
		return;
	}

	// Iterate to very left most node (since it's a BST) to find first alphabetical name
	Node* current = root;
	while (current->left != NULL) {
		current = current->left;
	}
	cout << "First name in alphabetical order: " << current->name << endl;
}

int main() {
	BST tree;
	tree.getData();

	cout << endl << "Pre-Order:" << endl << "----------" << endl;
	tree.preOrder(tree.root);
	cout << endl << "In-Order:" << endl << "----------" << endl;
	tree.inOrder(tree.root);
	cout << endl << "Post-Order:" << endl << "----------" << endl;
	tree.postOrder(tree.root);

	cout << endl;
	cout << "Height: " << tree.getHeight(tree.root) << endl;
	cout << "Leaf count: " << tree.getLeafCount(tree.root) << endl;

	cout << "Searching for Abe: ";
	tree.searchName("Abe");
	cout << "Searching for Bradley: ";
	tree.searchName("Bradley");

	tree.lowestWeight();
	tree.firstAlphaName();
}

/*
Enter name and weight on separate lines.
Jim
150
Enter name and weight on separate lines.
Tom
212
Enter name and weight on separate lines.
Michael
174
Enter name and weight on separate lines.
Abe
199
Enter name and weight on separate lines.
Richard
200
Enter name and weight on separate lines.
April
117
Enter name and weight on separate lines.
Claire
124
Enter name and weight on separate lines.
Bobby
109
Enter name and weight on separate lines.
Bob
156
Enter name and weight on separate lines.
Kevin
145
Enter name and weight on separate lines.
Jason
182
Enter name and weight on separate lines.
Brian
150
Enter name and weight on separate lines.
Chris
175
Enter name and weight on separate lines.
Steven
164
Enter name and weight on separate lines.
Annabelle
99

Pre-Order:
----------
Jim - 150
Abe - 199
April - 117
Annabelle - 99
Claire - 124
Bobby - 109
Bob - 156
Brian - 150
Chris - 175
Jason - 182
Tom - 212
Michael - 174
Kevin - 145
Richard - 200
Steven - 164

In-Order:
----------
Abe - 199
Annabelle - 99
April - 117
Bob - 156
Bobby - 109
Brian - 150
Chris - 175
Claire - 124
Jason - 182
Jim - 150
Kevin - 145
Michael - 174
Richard - 200
Steven - 164
Tom - 212

Post-Order:
----------
Annabelle - 99
Bob - 156
Chris - 175
Brian - 150
Bobby - 109
Jason - 182
Claire - 124
April - 117
Abe - 199
Kevin - 145
Steven - 164
Richard - 200
Michael - 174
Tom - 212
Jim - 150

Height: 7
Leaf count: 6
Searching for Abe: Weight of Abe: 199
Searching for Bradley: Bradley not found in tree.
Lowest weight: Annabelle - 99
First name in alphabetical order: Abe
*/
