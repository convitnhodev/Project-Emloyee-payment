#include"Employee.h"

class DataManeger {
private:
	string name;
	vector<Employee*> arr;
	static DataManeger* mInstancePtr;
	static mutex mLocker;
	DataManeger(string x) {
		name = x;
	}
public:
	DataManeger(const DataManeger&) = delete;
	static DataManeger* getInstance(string x);
	void readFile(const char* Input);
	void countAllSalary();
	void printInfo();
};



