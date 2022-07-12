#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<mutex>
using namespace std;

class Employee {
protected:
	string fullname;
	float Salary;
public:
	virtual int get_Total() {
		return 0;
	}
	virtual void set_Total(int) {
		return;
	}
	virtual float get_Payment() {
		return 0;
	}
	virtual void set_Payment(float k) {
		return;
	}
	virtual float get_fixed() {
		return 0;
	}
	virtual void set_fixed(float) {
		return;
	}
	virtual float countSalary() {
		return 0;
	}
	virtual int Tick() {
		return 0;
	}

	static Employee* make_Employee(int choice);
	string get_fullname();
	void set_fullname(string);
};


class DailyEmployee : public Employee {
private:
	int days;
	float DailyPayment;
public:
	int get_Total();
	void set_Total(int);
	float get_Payment();
	void set_Payment(float k);
	float countSalary();
	int Tick() {
		return 1;
	}
};


class HourlyEmployee :public Employee {
private:
	int hours;
	float HourlyPayment;
public:
	int get_Total();
	void set_Total(int);
	float get_Payment();
	void set_Payment(float);
	float countSalary();
	int Tick() {
		return 2;
	}
};


class ProductEmployee : public Employee {
private:
	int products;
	float PaymentPerProduct;

public:
	int get_Total();
	void set_Total(int);
	float get_Payment();
	void set_Payment(float);
	float countSalary();
	int Tick() {
		return 3;
	}
};

class Manager : public Employee {
private:
	float fixedPayment;
	int TotalEmployees;
	float PaymentPerEmployee;
public:
	float get_fixed();
	int get_Total();
	float get_Payment();
	void set_fixed(float);
	void set_Total(int);
	void set_Payment(float);
	float countSalary();
	int Tick() {
		return 0;
	}
};