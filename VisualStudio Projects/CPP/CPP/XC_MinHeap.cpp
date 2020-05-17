#include <iostream>
using namespace std;
#define SIZE 30

class MinHeap {
private:
	int dataArray[SIZE], count;
public:
	MinHeap() {
		for (int i = 0; i < SIZE; i++) {
			dataArray[i] = 0;
		}
		count = 0;
	}
	void Add(int data){
		dataArray[count] = data;
		bubbleUp(count);
		count++;
	}
	int Delete() {
		// If nothing in the heap, can't delete
		if (count == 0) {
			return -404;
		}
		// Override root with last element in array and bubble it down
		int result = dataArray[0];
		dataArray[0] = dataArray[count - 1];
		count--;
		bubbleDown(0);
		return result;
	}

	void bubbleUp(int index) {
		// If index is 0, root is hit - catches end of recursion - Exit function
		if (index == 0) {
			return;			
		}

		int parentIndex = (index - 1) / 2;

		// If data is smaller than parent, we're violating min heap rule
		if (dataArray[index] < dataArray[parentIndex]) { 
			int temp = dataArray[parentIndex];
			dataArray[parentIndex] = dataArray[index];
			dataArray[index] = temp;
			bubbleUp(parentIndex);
			// Recurse until min heap rule is satisfied up to the root
		}
	}

	void bubbleDown(int index) {
		int leftIndex = 2 * index + 1;
		int rightIndex = 2 * index + 2;
		int minIndex = index;

		// Check if left child exists (not higher than count), else exit function
		if (leftIndex >= count) {
			return;
		}

		// If left child data is less than index data, select it as min
		if (dataArray[leftIndex] < dataArray[index]) {
			minIndex = leftIndex;
		}

		// If right child data is less than min index data and is less than count (not last spot, since we select left child as smaller value)
		if (dataArray[rightIndex] < dataArray[minIndex] && rightIndex < count) {
			minIndex = rightIndex;
		}
		
		// Check if min index was changed, otherwise no switch needs to be made
		if (minIndex != index) {
			int temp = dataArray[index];
			dataArray[index] = dataArray[minIndex];
			dataArray[minIndex] = temp;
			bubbleDown(minIndex);
		}
	}

	void Print() {
		if (count == 0) {
			cout << "Array empty!" << endl;
		}
		for (int i = 0; i < count; i++) {
			cout << dataArray[i] << " ";
		}
		cout << endl;
	}
};



int main() {
	MinHeap minHeap;
	int choice = 0, value, result;
	while (choice != 4) {
		cout << "\n1. Add Value\n2. Pop Value\n3. Print\n4. Exit\n";
		cin >> choice;
		switch (choice) {
			case 1: {
				cout << "Enter value to insert: ";
				cin >> value;
				minHeap.Add(value);
				break;
			}
			case 2: {
				result = minHeap.Delete();
				if (result == -404) {
					cout << "Array empty!" << endl;
				}
				else {
					cout << "Popped " << result;
				}
				break;
			}
			case 3: {
				cout << endl;
				minHeap.Print();
				break;
			}

			case 4: {
				return 0;
			}

			default: {
				cout << "Invalid Choice!" << endl;
				break;
			}

		}
	}


}