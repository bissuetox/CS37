#include <iostream>
using namespace std;
#define ARR_CNT 20

class BinaryTree {

public:
	int count;					
	BinaryTree() : count(0) {}	
	void add(int x);
	void print();
	void Preorder(int fCount);
	void Inorder(int fCount);
	void Postorder(int fCount);

private:
	int data[ARR_CNT] = {};
};

void BinaryTree::add(int x) {
	data[count] = x;
	count++;
	//cout << "Added " << x << " to count #" << count - 1 << endl;		// Debug
}

void BinaryTree::print() {
	for (int i = 0; i < count; i++) {
		cout << data[i] << " ";
	}
}

void BinaryTree::Preorder(int fCount) {
	if (fCount >= count) {
		return;
	}

	cout << data[fCount] << " ";
	Preorder(2 * fCount + 1);
	Preorder(2 * fCount + 2);
}

void BinaryTree::Inorder(int fCount) {
	if (fCount >= count) {
		return;
	}
	Inorder(2 * fCount + 1);
	cout << data[fCount] << " ";
	Inorder(2 * fCount + 2);
}

void BinaryTree::Postorder(int fCount) {
	if (fCount >= count) {
		return;

	}
	Postorder(2 * fCount + 1);
	Postorder(2 * fCount + 2);
	cout << data[fCount] << " ";
}

int main() {
	BinaryTree asd;
	asd.add(5);
	asd.add(10);
	asd.add(3);
	asd.add(4);
	asd.add(12);
	asd.add(11);
	asd.Preorder(0);
	cout << endl;
	asd.Inorder(0);
	cout << endl;
	asd.Postorder(0);
	cout << endl;
}

