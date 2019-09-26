#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// struct sCrop that contains all of the crop data to be both inputted and calculated
struct sCrop {
	string cropName;
	float costAcre, costBushel, increase, minNP, maxNP, avgNP = 0;
	int yield;
};

// function prototypes
void calculate(sCrop &crop);
void inputData(sCrop &crop);
void printResults(sCrop crop);

// main func 
int main()
{
	sCrop crops[4];
	sCrop &bestCrop = crops[0];

	for (int i = 0; i < 4; i++) 
	{
		inputData(crops[i]);
		calculate(crops[i]);
		printResults(crops[i]);
		if (crops[i].avgNP > bestCrop.avgNP)
			bestCrop = crops[i];
	}
	cout << "Old MacDonald, you should plant " << bestCrop.cropName << endl << endl;
}

// function that calculates the min, max, and average net profit
void calculate(sCrop &crop)
{
	float minGross = crop.yield * crop.costBushel * 1000;
	float maxGross = minGross + (minGross * (crop.increase / 100));
	crop.minNP = minGross - (crop.costAcre * 1000);
	crop.maxNP = maxGross - (crop.costAcre * 1000);
	crop.avgNP = (crop.minNP + crop.maxNP) / 2;
}

// function that prompts the user to input the crop name and data
void inputData(sCrop &crop)
{
	cout << "Enter the crop name: ";
	getline(cin, crop.cropName);
	cout << "Enter cost, yield, price per bushel, and increase data: ";
	cin >> crop.costAcre >> crop.yield >> crop.costBushel >> crop.increase;
	cin.ignore();
}

// function that prints all of the data inside formatted nicely
void printResults(sCrop crop)
{
	cout << left << setw(15) << "";
	cout << setw(20) << "Minimum Profit";
	cout << setw(20) << "Maximum Profit";
	cout << setw(20) << "Average Profit" << endl;

	cout << right << setw(15) << crop.cropName + ":  ";
	cout << left << setprecision(2) << fixed << " $" << setw(19) << crop.minNP;
	cout << "$" << setw(19) << crop.maxNP;
	cout << "$" << setw(19) << crop.avgNP << endl << endl;
}

/*
Enter the crop name: Corn
Enter cost, yield, price per bushel, and increase data: 41 150 .55 5.5
			   Minimum Profit      Maximum Profit      Average Profit
		Corn:   $41500.00           $46037.50           $43768.75

Enter the crop name: Watermelon
Enter cost, yield, price per bushel, and increase data: 42.5 160 .40 4.8
			   Minimum Profit      Maximum Profit      Average Profit
  Watermelon:   $21500.00           $24572.00           $23036.00

Enter the crop name: Carrots
Enter cost, yield, price per bushel, and increase data: 38 175 .60 7.7
			   Minimum Profit      Maximum Profit      Average Profit
	 Carrots:   $67000.01           $75085.01           $71042.51

Enter the crop name: Apples
Enter cost, yield, price per bushel, and increase data: 40.5 130 .8 2.2
			   Minimum Profit      Maximum Profit      Average Profit
	  Apples:   $63500.00           $65788.00           $64644.00

Old MacDonald, you should plant Carrots
*/