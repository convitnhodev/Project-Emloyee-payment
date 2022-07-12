#include"DataManeger.h"


int main() {
	const char* Input = "input.txt";
	DataManeger* data;
	data = DataManeger::getInstance("thang 10");
	data->readFile(Input);
	data->printInfo();
	system("pause");
	system("pause");
}