#include <iostream>
using namespace std;

class HashTable {
private:
	int HashFunction(int ValueToHash) {
		return (ValueToHash % 10);
	}
	int* hashTable = new int[10];

public:
	HashTable() {
		for (int I = 0; I < 10; I++) {
			hashTable[I] = 0;
		}
	}

	int Insert(int ValueToInsert) {
		int idxHash = HashFunction(ValueToInsert);
		if (hashTable[idxHash] == 0) {
			hashTable[idxHash] = ValueToInsert;
			return idxHash;
		}
		else {
			int probIdx = HashFunction(idxHash + 1);
			while (probIdx != idxHash) {
				if (hashTable[probIdx] == 0) {
					hashTable[probIdx] = ValueToInsert;
					return probIdx;
				}
				probIdx = HashFunction(probIdx + 1);
			}
		}
		return -1;
	}
};

class HashTableProf {
private:
	int HashFunction(int ValueToHash) {
		return (ValueToHash % 10);
	}
	int* hashTable = new int[10];

public:
	HashTableProf() {
		for (int I = 0; I < 10; I++) {
			hashTable[I] = 0;
		}
	}

	int Insert(int ValueToInsert) {
		int HI = HashFunction(ValueToInsert);
		int index = -1;
		for (int i = HI; i != HI - 1; i = ++i % 10)
		{
			if (hashTable[i] == 0)
			{
				hashTable[i] = ValueToInsert;
				index = i;
				break;
			}
		}
		return (index);
	}
};

int HashFunction(int ValueToHash) {
	return (ValueToHash % 10);
}

int main() {
	HashTable ht;
	HashTableProf ht1;
	cout << "Idx " << ht.Insert(8) << endl;
	cout << "Idx " << ht.Insert(18) << endl;
	cout << "Idx " << ht.Insert(28) << endl;
	cout << "Idx " << ht.Insert(38) << endl;

	cout << "-----" << endl;
	cout << "Idx " << ht1.Insert(8) << endl;
	cout << "Idx " << ht1.Insert(18) << endl;
	cout << "Idx " << ht1.Insert(28) << endl;
	cout << "Idx " << ht1.Insert(38) << endl;
}