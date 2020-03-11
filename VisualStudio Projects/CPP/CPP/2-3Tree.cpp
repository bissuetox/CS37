#include <iostream>
using namespace std;

struct TwoThreeNode {
	int data1, data2, data3;
	TwoThreeNode* left, * mid, * right, * parent;
	TwoThreeNode(int x1) : data1(x1), left(NULL), mid(NULL), right(NULL) {}
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

void insert(TwoThreeNode* node, int value) {
	if (node == NULL) {
		node = new TwoThreeNode(value);
		return;
	}
	if (!hasChildren(node)) {

	}
}