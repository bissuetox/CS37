#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int x) {
		data = x;
		next = NULL;
	}
};

int getMiddle(Node* head) {
	Node* p = head;
	int mid, n = 0, c = 0;

	while (p != NULL) {
		n++;
		p = p->next;
	}

	mid = n / 2 + 1;

	while (c < mid) {
		head = head->next;
	}

	return head->data;
		
	
}

int main() {

}