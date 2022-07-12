#include "DataManeger.h"

DataManeger* DataManeger::mInstancePtr = nullptr;
mutex DataManeger::mLocker;


DataManeger* DataManeger::getInstance(string x) {
	mLocker.lock();
	if (nullptr == mInstancePtr) {
		mInstancePtr = new DataManeger(x);
	}
	mLocker.unlock();
	return mInstancePtr;
}

void DataManeger::readFile(const char* Input) {
	freopen(Input, "rt", stdin);
	int count = 0;
	string readType;
	string readName;
	string tmp;
	short flag;
	float a;
	float b;
	float c;
	while (!feof(stdin)) {
		flag = -1;
		getline(cin, readType, ':');
		if (readType == "DailyEmployee")
			flag = 1;
		else if (readType == "HourlyEmployee")
			flag = 2;
		else if (readType == "ProductEmployee")
			flag = 3;
		else if (readType == "Manager")
			flag = 0;
		getline(cin, readName, '\n');
		getline(cin, tmp, '=');
		cin >> a;
		getline(cin, tmp, '=');
		cin >> b;
		if (flag == 0) {
			getline(cin, tmp, '=');
			cin >> c;
		}
		switch (flag)
		{
		case 1:
			this->arr.push_back(Employee::make_Employee(flag));
			this->arr[count]->set_fullname(readName);
			this->arr[count]->set_Payment(a);
			this->arr[count]->set_Total(b);
			count++;
			break;
		case 2:
			this->arr.push_back(Employee::make_Employee(flag));
			this->arr[count]->set_fullname(readName);
			this->arr[count]->set_Payment(a);
			this->arr[count]->set_Total(b);
			count++;
			break;
		case 3:
			this->arr.push_back(Employee::make_Employee(flag));
			this->arr[count]->set_fullname(readName);
			this->arr[count]->set_Payment(a);
			this->arr[count]->set_Total(b);
			count++;
			break;
		default:
			this->arr.push_back(Employee::make_Employee(flag));
			this->arr[count]->set_fullname(readName);
			this->arr[count]->set_Payment(c);
			this->arr[count]->set_Total(b);
			this->arr[count]->set_fixed(a);
			count++;
			break;
		}
		getline(cin, tmp, '\n');
	}
}

void DataManeger::printInfo() {
	int tmp;
	int SIZE = arr.size();
	for (int i = 0; i < SIZE; i++) {
		tmp = arr[i]->Tick();
		switch (tmp)
		{
		case 1:
			cout << "DailyEmployee: " << arr[i]->get_fullname() << endl;
			cout << "    ";
			cout << "DailyPayment=" << arr[i]->get_Payment() << "$;" << endl;
			cout << "    ";
			cout << "TotalDays=" << arr[i]->get_Total() << ";" << endl;
			cout << "    ";
			cout << "Total Salary: " << arr[i]->countSalary() << endl;
			break;

		case 2:
			cout << "HourlyEmployee: " << arr[i]->get_fullname() << endl;
			cout << "    ";
			cout << "HouryPayment=" << arr[i]->get_Payment() << "$;" << endl;
			cout << "    ";
			cout << "TotalHours=" << arr[i]->get_Total() << ";" << endl;
			cout << "    ";
			cout << "Total Salary: " << arr[i]->countSalary() << endl;
			break;

		case 3:
			cout << "ProductEmployee: " << arr[i]->get_fullname() << endl;
			cout << "    ";
			cout << "PaymentProduct=" << arr[i]->get_Payment() << "$;" << endl;
			cout << "    ";
			cout << "TotalProducts=" << arr[i]->get_Total() << ";" << endl;
			cout << "    ";
			cout << "Total Salary: " << arr[i]->countSalary() << endl << endl;
			break;

		default:
			cout << "Manager: " << arr[i]->get_fullname() << endl;
			cout << "    ";
			cout << "FixedPayment=" << arr[i]->get_fixed() << "$;" << endl;
			cout << "    ";
			cout << "TotalEmployees=" << arr[i]->get_Payment() << "$;" << endl;
			cout << "    ";
			cout << "TotalEmployees=" << arr[i]->get_Total() << ";" << endl;
			cout << "    ";
			cout << "Total Salary: " << arr[i]->countSalary() << endl;
			break;
		}
	}
}


