#include <iostream>
using namespace std;

/*
struct Word {
	int len = 0;
	char word[50];
};
*/


int main() {
	char sentence[50]; // Initial load char array
	//Word words[10]; // Array of Word tructs
	cout << "Enter a sentence: " << endl;
	cin.get(sentence, 50);

	int wordNum = 0, wordChar = 0;
	for (int i = 0; sentence[i] != '\0'; i++) {
		if (sentence[i] == ' ') {
			//wordNum++;
			//wordChar = 0;
			cout << endl;
			continue;
		}

		else if (sentence[i] >= '0' && sentence[i] <= '9' || sentence[i] == '.'; // don't assume they will type 2...3 or 2,422
		else {
			//words[wordNum].word[wordChar] = sentence[i];
			cout << sentence[i];

			//wordChar++;
		}
	}


	/*
	while (sentence[sPos] != '\0') { // While not at end of sentence
		
		if (sentence[sPos] != ' ') {
			words[wPos].word[len] = 
		}

	}
	*/
}