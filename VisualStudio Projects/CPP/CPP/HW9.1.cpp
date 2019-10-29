#include <iostream>
#include <string>
#include <fstream>
using namespace std;
// program that counts the lines of a text file, dynamically creates an array of that size, and stores the data in the text into that array,
// then outputs that data into a new file in reverse order

int determineLines(ifstream &fileIn); // function that determiens the line count
void readLines(ifstream& fileIn, int linesArray[], const int& lineCount); // function that reads the lines and inputs them in array
void reverseOutput(ofstream &fileOut, int linesArray[], const int& lineCount); // writes the lineArray in reverse order to new file

// main func
int main() {
	int* linesArray;
	int lineCount = 0;
	ifstream fileIn("Lab_HW9_1_Input.txt"); // opens text file located in project folder
	if (fileIn.is_open()) { // check if file was found
		lineCount = determineLines(fileIn); // sets global lineCount to returned linecount from function
		linesArray = new int[lineCount]; // initializes linesArray array with linecount size
		readLines(fileIn, linesArray, lineCount);
	}
	else { // if file was not opened
		cerr << "File not found."; 
		exit(1);
	}

	fileIn.close(); // close fileIn

	ofstream fileOut("reverse_output.txt");
	if (fileOut.is_open()) { // check if file was found
		reverseOutput(fileOut, linesArray, lineCount);
	}

	else { // if file was not opened
		cerr << "File not found.";
		exit(1);
	}

	fileOut.close(); // closes fileOut
	
	delete[] linesArray; // deletes dynamically allocated array
}

// returns the line count and resets the pointer and EOF bit
int determineLines(ifstream &fileIn) {
	int lineCount = 0;
	string trash;
	while (fileIn.good()) { // or fileIn.good()
		getline(fileIn, trash);
		lineCount++; // adds 1 to line count
	}
	fileIn.clear(); // resets EOF bit
	fileIn.seekg(0, ios::beg); // sets line pointer to beginning of file
	return lineCount; // returns line count to caller
}

// readline function that loops through the file and stores it in the linesArray array
void readLines(ifstream &fileIn, int linesArray[], const int &lineCount) {
	for (int i = 0; i < lineCount; i++) {
		fileIn >> linesArray[i];
		cout << "Line " << i+1 << ": " << linesArray[i] << endl; // debug purposes
	}
}

// outputs lineArray function in reverse order using for loop
void reverseOutput(ofstream& fileOut, int linesArray[], const int &lineCount) {
	for (int j = lineCount; j > 0; j--) { // looping in opposite order - linecount to 0
		fileOut << linesArray[j-1] << endl; // using j-1 to take into account array is 0 to 9
		cout << "wrote: " << linesArray[j-1] << endl; // debug purposes
	}
}