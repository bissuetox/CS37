#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left, * right;
	Node(int x) {
		data = x;
		left = right = NULL;
	}
};

int max(int x, int y) {
	return (x > y) ? x : y;
}

int height(Node* node) {
	int h = 0;
	if (node != NULL) {
		int l_height = height(node->left);			// Gets/traverses height of L/R node. Once it hits a leaf it'll return up
		int r_height = height(node->right);
		int max_height = max(l_height, r_height);	// Gets the bigger of the two
		h = max_height + 1;							// Sets the height to it + 1 because ???
	}
	return h;
}

int difference(Node* node) {
	int l_height = height(node->left);		// Height of left child
	int r_height = height(node->right);		// Height of right child
	int b_factor = l_height - r_height;		// Difference between the is the balancing factor
	return b_factor;						// returns it
}

Node* rr_rotate(Node* parent) {
	Node* t;
	t = parent->right;
}


int main() {
	Node* root = NULL;

}