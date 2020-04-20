#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class Node {
public:
	string label;			// Use if(v1 || v2) to check if its a vertex or edge, edge will have v1 || v2 == not null
	int weight;
	Node* v1, * v2;			// The two vertices connected (if edge)

	// Default constructor
	Node() {
		label = "";
		weight = 0;
		v1 = v2 = NULL;
	}
	// Constructor for vertex
	Node(string fLabel) {
		label = fLabel;
		weight = 0;
		v1 = v2 = NULL;
	}
	// Constructor for edge
	Node(string fLabel, Node* fV1, Node* fV2, int fWeight) {
		label = fLabel;
		v1 = fV1;
		v2 = fV2;
		weight = fWeight;
	}
};

class graphList {
public:
	Node** list;
	int count, maxCount;
	graphList() {
		list = NULL;
		count = maxCount = 0;
	}
	~graphList() {
		delete list;
	}

	int getVertex(string fLabel) {
		int found = -1;
		for (int i = 0; i < count; i++) {
			if (list[i]->label == fLabel) {
				found = i;
				break;
			}
		}
		return found;
	}
	void getData() {
		string vertexName;
		int numPoints;

		// Get num of points
		cout << "How many points? ";
		cin >> numPoints;
		cin.ignore();
		maxCount = ((numPoints * (numPoints - 1)) / 2) + numPoints;		// Max edges (undirected) + n spots for vertices
		list = new Node * [maxCount];

		// Get vertices
		for (int i = 0; i < numPoints; i++) {
			cout << "Enter vertex name: ";
			getline(cin, vertexName);
			list[count] = new Node(vertexName);
			count++;
		}

		string tempData, tempV1, tempV2, tempWeight;

		// Get edges
		while (count < maxCount) {
			cout << "Enter an edge and weight in format\n(Vertex1 Vertex2 Weight) - (-1 to quit)" << endl;
			getline(cin, tempData);
			if (tempData == "-1") break; 
			istringstream ss(tempData);
			ss >> tempV1 >> tempV2 >> tempWeight;
			int intWeight = stoi(tempWeight);

			int indexV1 = getVertex(tempV1);
			int indexV2 = getVertex(tempV2);
			if (indexV1 == -1 || indexV2 == -1) {
				cout << "Vertices not found." << endl << endl;
				continue;
			}
			Node* V1 = list[indexV1];
			Node* V2 = list[indexV2];

			list[count] = new Node(V1->label + V2->label, V1, V2, intWeight);
			count++;
		}
	}

	void printEdges() {
		cout << "Edges: " << endl;
		for (int i = 0; i < count; i++) {
			if (list[i]->v1 && list[i]->v2) {
				cout << list[i]->label << " - " << list[i]->weight << endl;
			}
		}
	}
};

int main() {
	graphList GL;
	GL.getData();
	GL.printEdges();
}