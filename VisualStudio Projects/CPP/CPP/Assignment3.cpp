//----------------------------------------------------------------------------//
// Name: Chris Kruki                                                          //
// Student ID: 1132759                                                        //
// Assignment: #3                                                             //
//----------------------------------------------------------------------------//

#define PARTINFO_CNT 1
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Car
{
public:

private:
	string brand;
	string model;
	int year;
};

class Manufacturer
{
public:

private:
	string name;
};

class Parts
{
};

class Brakes : public Parts
{
};

class Lights : public Parts
{
};

class Oil : public Parts
{
};

class Tires : public Parts
{
};

void parseLineToTokens(string lineText, string tokens[]);

int main()
{
	//open the file from which to read the data

	//call a global function to find out how many objects of each type to create
	// iterate through the file and count for each type?

	//create arrays to contain the necessary objects

	//global function to read information from the file into the arrays of objects

	//call functions to find the best selling item for each category, output best to a file

	//close the file explicitly
}

// Parse a line of text into tokens and store them in an array of strings
void parseLineToTokens(string lineText, string tokens[]) // get line of text from file, then pass it into this function
{
	int end, start;

	start = -2;
	for (int j = 0; j < PARTINFO_CNT; j++)
	{
		start = start + 3;
		end = lineText.find('"', start);
		tokens[j] = lineText.substr(start, end - start);
		start = end;
	}
	// token array will have all of the values sorted,
	// 15 different items ( columns of things )
}



// Notes:
//
// Example:
// To create an array of 'cnt' Books items, where 'cnt' can only be determined at the time the program is run:
//   Books *booksList = new Books[cnt];
//
// To clean up dynamically allocated memory when done with the dynamically allocated array:
//   delete [] booksList;
//
//
// To go back and read from the beginning of the file that was already opened and read till the EOF
//   bookFile.clear();			// reset the EOF state
//   bookFile.seekg(0, ios::beg);	// set pointer at the beginning of the file		