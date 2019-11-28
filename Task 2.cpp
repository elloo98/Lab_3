#include <iostream>
using namespace std;
/*
double average_salary(const int* salaries, const int employees) {
	int index = 0;
	double result = 0;
	while (index < employees) {
		result = result + *salaries;
		index++;
		salaries++;
	}
	return result/employees;
}

int main() {
	double average = 0;
	int index = 0;
	int employees = 0;
	printf("How many employees?\n");
	while (employees <= 0) {
		cin >> employees;
		if (employees <= 0)
			printf("%i is not an allowed ammount of employees, please enter an allowed number\n",employees);
	}
	printf("Okay, now enter %i salaries\n", employees);
	int* arr = new int[employees];
	while (index < employees) {
		cin >> arr[index];
		index++;
	}
	average = average_salary(arr, employees);
	printf("The average salary is %f\n", average);
	delete[] arr;
	system("pause");
	return 0;
}
*/