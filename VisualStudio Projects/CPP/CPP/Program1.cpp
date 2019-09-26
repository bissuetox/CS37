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
	sCrop crops[4]; // array of crops
	sCrop &bestCrop = crops[0]; // set a reference to the first crop for later iteration

	for (int i = 0; i < 4; i++) 
	{
		inputData(crops[i]);
		calculate(crops[i]);
		printResults(crops[i]);
		if (crops[i].avgNP > bestCrop.avgNP) // if the iterated crop has a greater average than the current bestCrop, then set that crop to the best Crop
			bestCrop = crops[i];
	}
	cout << "Old MacDonald, you should plant " << bestCrop.cropName << endl << endl; // print the best crop
}

// function that calculates the min, max, and average net profit, and saves it in the passed crop struct
void calculate(sCrop &crop)
{
	float minGross = crop.yield * crop.costBushel * 1000; 
	float maxGross = minGross + (minGross * (crop.increase / 100));
	crop.minNP = minGross - (crop.costAcre * 1000);
	crop.maxNP = maxGross - (crop.costAcre * 1000);
	crop.avgNP = (crop.minNP + crop.maxNP) / 2;
}

// function that prompts the user to input the crop name and data and stores it in the passed crop struct
void inputData(sCrop &crop)
{
	cout << "Enter the crop name: ";
	getline(cin, crop.cropName);
	cout << "Enter cost, yield, price per bushel, and increase data: ";
	cin >> crop.costAcre >> crop.yield >> crop.costBushel >> crop.increase;
	cin.ignore();
}

// function that prints all of the data inside the passed crop struct and formats it nicely
void printResults(sCrop crop)
{
	cout << left << setw(15) << "";
	cout << setw(20) << "Minimum Profit";
	cout << setw(20) << "Maximum Profit";
	cout << setw(20) << "Average Profit" << endl;

	cout << left << setw(15) << crop.cropName;
	cout << setprecision(2) << fixed << " $" << setw(19) << crop.minNP;
	cout << "$" << setw(19) << crop.maxNP;
	cout << "$" << setw(19) << crop.avgNP << endl << endl;
}

/*
Enter the crop name: Sweet corn
Enter cost, yield, price per bushel, and increase data: 45.25 173 0.54 4.7
			   Minimum Profit      Maximum Profit      Average Profit
Sweet corn      $48170.01           $52560.75           $50365.38

Enter the crop name: Wheat
Enter cost, yield, price per bushel, and increase data: 43.00 200 0.43 3.1
			   Minimum Profit      Maximum Profit      Average Profit
Wheat           $43000.00           $45666.00           $44333.00

Enter the crop name: Kale
Enter cost, yield, price per bushel, and increase data: 43.50 157 0.61 4.3
			   Minimum Profit      Maximum Profit      Average Profit
Kale            $52270.01           $56388.12           $54329.06

Enter the crop name: Green Beans
Enter cost, yield, price per bushel, and increase data: 40.80 118 0.72 2.7
			   Minimum Profit      Maximum Profit      Average Profit
Green Beans     $44160.01           $46453.93           $45306.97

Old MacDonald, you should plant Kale
*/