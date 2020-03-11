#include <iostream>
using namespace std;

struct TwoThreeNode {
	int data1, data2, numValues;
	TwoThreeNode* left, * mid, * right, * parent;
	TwoThreeNode(int x1){
		data1 = x1;
		data2 = 0;
		left = NULL;
		mid = NULL;
		right = NULL;
		parent = NULL;
		numValues = 0;
	}
};

/*
While node does not have 3 nodes
	If node has no children
		Insert value into node (adjust w/ larger on right)
			Might have to handle switching L/R
		Else
			Traverse left, mid or right
				Left = value is < node left value
				Mid = value is left < x < right
				Right = value is > right

If Node has 3 values
	Adjust(node)
		split left and right values in new separate nodes
		set parent node's L/R pointers to new nodes
		If parent has 3 nodes
			Adjust(parent)

*/

int hasChildren(TwoThreeNode* node) {
	return (node->left != NULL || node->mid != NULL || node->right != NULL);
}

int largestNode(TwoThreeNode* node1, TwoThreeNode* node2, TwoThreeNode* node3) {
	TwoThreeNode* largest1, largest2;
	if ()
}

void insert(TwoThreeNode* node, int value) {
	TwoThreeNode* target = node;
	if (node == NULL) {
		node = new TwoThreeNode(value);
		return;
	}

	while (target->numValues != 3)
	{
		if (!hasChildren(target)) {
			if (target->numValues == 0) {			// If the node has 0 items
				target->data1 = value;				// Set the left most value to the key
				target->numValues = 1;
			}
			else if (target->numValues == 1) {		// If the node has 1 item
				if (target->data1 > value) {		// If the left data is > than value
					target->data2 = target->data1;	// Move data right
					target->data1 = value;			// Replace it with passed value
					target->numValues = 2;
				}
			}
			else if (target->numValues == 2) {

			}
		}
		else {
			target = target->
		}
	}
}

int main() {
	int hello = NULL;
	cout << hello;
}