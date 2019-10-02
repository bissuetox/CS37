#include <iostream>
#include <string>
using namespace std;

class CandD {
public:
	CandD(int id, string msg);
	~CandD();
private:
	int oID;
	string oMsg;
};

//constructor definition
CandD::CandD(int id, string msg) {
	oID = id;
	oMsg = msg;
	cout << "Object " << oID << " constructor " << oMsg << endl;
}

CandD::~CandD() {
	cout << (oID == oID == 6 ? "\n" : "");
	cout << "Object " << oID << " destructor " << oMsg << endl;
}

//prototype
void create(void);

CandD o1(1, "(global before main)");

int main() {
	cout << "\nMAIN : BEGIN" << endl;
	CandD o2(2, "(local automatic - MAIN");
	static CandD o3(3, "(local static - MAIN)");
	create();
	cout << "\nMAIN: RESUME" << endl;
	CandD o4(4, "(local automatic - MAIN)");
	cout << ("\nMAIN: END") << endl;
}

// instantiate automatic and static objects in a called function.
void create(void) {
	cout << ("\nCREATE : BEGIN") << endl;
	CandD o5(5, "(local automatic - CREATE)");
	static CandD o6(6, "(local static - CREATE)");
	CandD o7(7, "(local automatic - CREATE)");
	cout << "\nCREATE : END" << endl;

	return;
}