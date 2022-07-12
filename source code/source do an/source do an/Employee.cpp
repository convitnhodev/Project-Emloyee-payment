#include "Employee.h"

string Employee::get_fullname() {
	return fullname;
}

void Employee::set_fullname(string k) {
	fullname = k;
}


float DailyEmployee::countSalary() {
	return days * DailyPayment;
}

int DailyEmployee::get_Total() {
	return days;
}

void DailyEmployee::set_Total(int k) {
	days = k;
}

float DailyEmployee::get_Payment() {
	return DailyPayment;
}

void DailyEmployee::set_Payment(float k) {
	DailyPayment = k;
}




float HourlyEmployee::countSalary() {
	return hours * HourlyPayment;
}


int HourlyEmployee::get_Total() {
	return hours;
}

void HourlyEmployee::set_Total(int k) {
	hours = k;
}

float HourlyEmployee::get_Payment() {
	return HourlyPayment;
}

void HourlyEmployee::set_Payment(float k) {
	HourlyPayment = k;
}


float ProductEmployee::countSalary() {
	return products * PaymentPerProduct;
}

int ProductEmployee::get_Total() {
	return products;
}

void ProductEmployee::set_Total(int k) {
	products = k;
}

float ProductEmployee::get_Payment() {
	return PaymentPerProduct;
}

void ProductEmployee::set_Payment(float k) {
	PaymentPerProduct = k;

}

float Manager::countSalary() {
	return fixedPayment + (TotalEmployees * PaymentPerEmployee);
}

float Manager::get_fixed() {
	return fixedPayment;
}

int Manager::get_Total() {
	return TotalEmployees;
}

void Manager::set_fixed(float k) {
	fixedPayment = k;
}

void Manager::set_Payment(float k) {
	PaymentPerEmployee = k;
}

float Manager::get_Payment() {
	return PaymentPerEmployee;
}

void Manager::set_Total(int k) {
	TotalEmployees = k;
}

Employee* Employee::make_Employee(int choice) {
	if (choice == 0)
		return new Manager;
	if (choice == 1)
		return new DailyEmployee;
	if (choice == 2)
		return new HourlyEmployee;
	if (choice == 3)
		return new ProductEmployee;
}