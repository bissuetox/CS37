#include <iostream>
using namespace std;


// Indirect Recursion
int MethodA(int n) {
	return (MethodB(n));
}

int MethodB(int x) {
	return (MethodA(x - 1)); // It is only indirect recursion when atleast one 
							//other method is called before the recursive call happens
}



int main() {
	int [][] = 

	return 0;
}