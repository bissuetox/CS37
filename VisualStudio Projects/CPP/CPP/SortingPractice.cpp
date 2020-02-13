#include <iostream>
using namespace std;


int binarySearch(int arr[], int l, int r, int x);	// l is left side index, r is right side index, x is what we're searching for
void bubbleSort(int arr[], int size);
void swap(int& num1, int& num2);
void printArray(int arr[], int size);
void insertionSort(int arr[], int size);
void selectionSort(int arr[], int size);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void merge(int arr[], int left, int mid, int right);


int main() {
	int arr[] = {1, 12, 3, 16, 14, 5, 7, 8 };
	int x = 3;								// Int to search for
	int n = sizeof(arr) / sizeof(arr[0]);	// Elements in array

	// Binary Search
	int result = binarySearch(arr, 0, n, x);	
	cout << "Binary Search index for 3: " << result << endl;

	
	cout << "Before" << endl;					
	printArray(arr, n);
	//bubbleSort(arr, n);					// Bubble Sort
	//insertionSort(arr, n);				// Insertion Sort
	//selectionSort(arr, n);				// Selection Sort
	quickSort(arr, 0, n - 1);
	cout << endl << "After" << endl;
	printArray(arr, n);



}

int binarySearch(int arr[], int l, int r, int x) {
	int mid = l + (r - l) / 2;		// Middle index is left + half of right index (right index is r - 1 since index starts at 0 and r is passed as # of elements)

	if (r >= 1) {					// If array has atleast 2 elements, otherwise array would be x
		if (arr[mid] == x) {
			return mid;
		}

		if (x < arr[mid]) {			// If middle element < x, Search the portion to the left of mid
			return binarySearch(arr, l, mid - 1, x);		
		}

		else {						// Else search the right side
			return binarySearch(arr, mid + 1, r, x);
		}
	}

	return -1;	// This will be reached if element is not present in array
}

void bubbleSort(int arr[], int size) {
	int i, j;

	for (i = 0; i < size - 1; i++) {			// Loop through whole array
		for (j = 0; j < size - i - 1; j++) {	// Loop through array - i - excludes ith elements at the end (largest get bumped to the end)
			if (arr[j] > arr[j + 1]) {			// if jth element is larger than j + 1 (elem to the right)
				swap(arr[j], arr[j + 1]);		// Swap them - this will eventually push largest to the right
			}
		}
	}


}

void insertionSort(int arr[], int size) {
	int i, key, j;
	for (i = 1; i < size; i++) {					// Loop to end of array, start at second elem
		key = arr[i];								// Set key to ith array elem - this picks the elem up
		j = i - 1;									// Set j to i - 1  -- j is elem to the left of i

		while (j >= 0 && arr[j] > key) {			// While j is not at beginning of array, and jth elem is > the key
			arr[j + 1] = arr[j];					// Shift elem to the right
			j--;									// Iterate j to the left until we hit index 0
		}											// After while loop, j will be -1
		arr[j + 1] = key;							// So we drop the key into the first position (-1 + 1)
	}
}

void selectionSort(int arr[], int size) {
	int i, j, min_idx;

	for (i = 0; i < size; i++) {				// Loop through whole array
		min_idx = i;							// Set min index to i - edge of sorted area - starts at very left
		for (j = i + 1; j < size; j++) {		// Loop through elem after i till the end
			if (arr[j] < arr[min_idx]) {		// If looped element is smaller than the current min
				min_idx = j;					// then set the min to it
			}
		}
		swap(arr[min_idx], arr[i]);				// After sorting through to find min idx, swap ith array elem and the min idx elem


	}
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);					// Partition the array to set a pivot and sort the larger/smaller values appropriately

		quickSort(arr, low, pi - 1);						// Recursive call for the left side
		quickSort(arr, pi + 1, high);						// Recursive call for the right side
	}
}

int partition(int arr[], int low, int high) {
	int pivot = arr[high];									// Initial pivot set to end elem
	int smaller = low - 1;									// Smaller index ptr set to low - 1 (smaller is ++ first in the for loop so it will start at 0)

	for (int current = low; current <= high - 1; current++) {	// Loop through array from low to high
		if (arr[current] < pivot) {							// If the current elem is smaller than pivot
			smaller++;										// Increase smaller ptr
			swap(arr[smaller], arr[current]);				// Swap the current elem with smaller elem
		}
		// else - don't iterate i and continue for loop - it will stay at the next smallest element
		// when the loop detects a smaller than pivot value, it shifts i to spot after last smallest elem, and swaps them.
	}
	swap(arr[smaller + 1], arr[high]);			// Finally, swap the elem after the smallest element and the pivot. 
	return (smaller + 1);								// This leaves the pivot in between the smaller and larger values. Array is ready for quick sort

}

void merge(int arr[], int left, int mid, int right) {

}



void swap(int &num1, int &num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}
