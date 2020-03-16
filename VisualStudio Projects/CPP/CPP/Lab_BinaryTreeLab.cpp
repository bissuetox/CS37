#include <iostream>
using namespace std;
#define ARR_CNT 20

class BinaryTree {

public:
	int count;					
	BinaryTree() : count(0) {}	

	void add(int x) {
		data[count] = x;		
		count++;
		//cout << "Added " << x << " to count #" << count - 1 << endl;		// Debug
	}
	void print() {
		for (int i = 0; i < count; i++) {
			cout << data[i] << " ";
		}
	}
private:
	int data[ARR_CNT] = {};
};

int main() {
	BinaryTree asd;
	asd.add(5);
	asd.add(10);
	asd.print();
}

