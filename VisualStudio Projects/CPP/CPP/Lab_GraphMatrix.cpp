#include <iostream>
#include <string>
#include <array>
#include <sstream>
using namespace std;

class MatrixGraph {
public:
	int** edges;
	string* labels;
	int count;

	MatrixGraph() {
		edges = NULL;
		labels = NULL;
		count = 0;
	}
	MatrixGraph(int fCount, string* vertices) {
		count = fCount;
		edges = new int*[count];
		for (int i = 0; i < count; i++) {
			edges[i] = new int[count];
		}

		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				edges[i][j] = 0;
			}
		}

		labels = new string[count];
		for (int i = 0; i < count; i++) {
			labels[i] = vertices[i];
		}
	}

	int getVertex(string fLabel) {
		int found = -1;
		for (int i = 0; i < count; i++) {
			if (labels[i] == fLabel) {
				found = i;
				break;
			}
		}
		return found;
	}

	void addEdge(string fromVertex, string toVertex) {
		int fromIdx = getVertex(fromVertex);
		int toIdx = getVertex(toVertex);
		edges[fromIdx][toIdx]++;
	}

	void printEdges() {
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				if (edges[i][j] != 0) {
					cout << "Edge: " << labels[i] << ":" << labels[j] << endl;
				}
			}
		}
	}
};

int main() {
	MatrixGraph* graph;

	int numVertices;

	// Get # of vertices
	cout << "Enter number of vertices: ";
	cin >> numVertices;
	cin.ignore();
	
	string* vertices = new string[numVertices], tempString;
	cout << "Enter vertices separated by spaces: " << endl;
	getline(cin, tempString);
	istringstream ss(tempString);
	for (int i = 0; i < numVertices; i++) {
		ss >> vertices[i];
	}
	graph = new MatrixGraph(numVertices, vertices);

	string v1, v2;

	while (1) {
		cout << "Enter source and destination vertices in format: \n(Vertex1 Vertex2) - (-1 to quit)" << endl;
		getline(cin, tempString);
		if (tempString == "-1") break;
		istringstream ss(tempString);
		ss >> v1 >> v2;
		graph->addEdge(v1, v2);
	}
	
	graph->printEdges();
}