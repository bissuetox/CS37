#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Person {
private:

};

// function prototypes
int determineLines(ifstream& fileIn);
void readLines(ifstream& fileIn, string linesArray[], const int& lineCount);
void writeMerged(ofstream &fileOut, string lineArray1[], string lineArray2[], const int& lineCount1, const int& lineCount2);
string getString(string line);
int getNum(string line);


int main() {
	int lineCount1 = 0, lineCount2 = 0;
	string* lineArray1;
	string* lineArray2;

	ifstream fileIn1("Lab_HW9_2_Merge1.txt");
	ifstream fileIn2("Lab_HW9_2_Merge2.txt");

	if (fileIn1.is_open()) {
		if (fileIn2.is_open()) {
			lineCount1 = determineLines(fileIn1);
			lineCount2 = determineLines(fileIn2);
		}
	}
	else {
		cerr << "File not found.";
		exit(1);
	}

	lineArray1 = new string[lineCount1];
	lineArray2 = new string[lineCount2];

	readLines(fileIn1, lineArray1, lineCount1);
	readLines(fileIn2, lineArray2, lineCount2);

	fileIn1.close();
	fileIn2.close();

	ofstream fileOut("merged_output.txt");
	if (fileOut.is_open()) {
		writeMerged(fileOut, lineArray1, lineArray2, lineCount1, lineCount2);
	}
	else {
		cerr << "File not created.";
		exit(1);
	}

	delete[] lineArray1;
	delete[] lineArray2;
}

// function that takes an ifstream object and returns the number of lines
int determineLines(ifstream& fileIn) {
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

void readLines(ifstream& fileIn, string linesArray[], const int& lineCount) {
	for (int i = 0; i < lineCount; i++) {
		getline(fileIn, linesArray[i]);
		//cout << "Line " << i + 1 << ": " << linesArray[i] << endl; // debug purposes
	}
}

string getString(string line) {
	string name = line.substr(0, line.find(' '));
	return name;
}

int getNum(string line) {
	int num;
	line.erase(0, line.find(' ') + 1);
	istringstream iss(line);
	iss >> num;
	return num;
}


void writeMerged(ofstream &fileOut, string lineArray1[], string lineArray2[], const int& lineCount1, const int& lineCount2) {
	const int combinedLines = lineCount1 + lineCount2;
	string* combinedArray = new string[combinedLines];

	int newLines = 0;
	string* newArray;
	
	int i = 0, sameNum = 0, newNum = 0, tick = 0;
	for (int j = 0; j < lineCount1; j++) {
		combinedArray[i] = lineArray1[j];
		i++;
	}
	for (int k = 0; k < lineCount2; k++) {
		combinedArray[i] = lineArray1[k];
		i++;
	}
	for (int j = 0; j < combinedLines; j++) {
		for (int k = j; k < combinedLines; k++) {
			if (j != k) {
				if (getString(combinedArray[j]) == getString(combinedArray[k]) && getNum(combinedArray[j]) == getNum(combinedArray[k])) {
					cout << getString(combinedArray[j]) << " == " << getString(combinedArray[k] ) << endl;
					sameNum += 1;
					tick = 1;
				}
			}
		}
		if (tick != 1) {
			newNum += 1;
		}
		else
			tick = 0;
	}

	newArray = new string[newLines];

	for (int k = 0; k < newLines; k++) {
		fileOut << newArray[k] << endl;
	}

}