#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;


void add() {
	double num1;
	double num2;

	int result;

	cout << "Enter first number: ";
	cin >> num1, "\n";
	cout << "Enter second number: ";
	cin >> num2, "\n";

	cout << "Answer : ";
	cout <<  num1 + num2;
}

void sub() {
	double num1;
	double num2;

	int result;

	cout << "Enter first number: ";
	cin >> num1, "\n";
	cout << "Enter second number: ";
	cin >> num2, "\n";

	cout << "Answer : ";
	cout << num1 - num2;
}

void mul() {
	double num1;
	double num2;

	int result;

	cout << "Enter first number: ";
	cin >> num1, "\n";
	cout << "Enter second number: ";
	cin >> num2, "\n";

	cout << "Answer : ";
	cout << num1 * num2;
}

void div() {
	double num1;
	double num2;

	int result;

	cout << "Enter first number: ";
	cin >> num1, "\n";
	cout << "Enter second number: ";
	cin >> num2, "\n";

	cout << "Answer : ";
	cout << num1 / num2;
}

int main() {
	string option;
	cout << "1 Add \n";
	cout << "2 Subtract \n";
	cout << "3 Multiply \n";
	cout << "4 Divide \n";
	cout << "Enter Input Here : ";

	getline (cin, option);

	if (option == "1")
	{
		add();
		return 0;
	}

	else if (option == "2")
	{
		sub();
		return 0;
	}

	else if (option == "3")
	{
		mul();
		return 0;
	}

	else if (option == "4")
	{
		div();
		return 0;
	}
}


