#include <iostream>
using namespace std;

class AdjacencyMatrix {
private:
	int matrix[10][10];
	int index[10];
	char* label[10];
public:
	bool AddBidirectionalEdge(char* V1, char* V2) {
		bool foundV1 = false, foundV2 = false;
		int indexV1, indexV2;
		for (int i = 0; i < 10; i++) {
			if (V1 == label[i]) {
				foundV1 = true;
				indexV1 = i;
			}
			if (V2 == label[i]) {
				foundV2 = true;
				indexV2 = i;
			}
		}
		if (foundV1 == false || foundV2 == false) {
			return false;
		}

		matrix[indexV1][indexV2] = 1;
		matrix[indexV2][indexV1] = 1;
		return true;
	}
};

int main() {
	AdjacencyMatrix am;
}