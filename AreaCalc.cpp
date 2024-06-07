
//Day-1: Learning c++: Project: Area Calculator

#include <iostream>
#include <cmath>

using namespace std;


void Sqre() 
{
	double side;
	double result;
	
	cout << "\nEnter side here : ";
	cin >> side;

	result = pow(side, 2);
	cout << "\nArea will be : ";
	cout << result;
}

void Rect()
{
	double lenght;
	double breadth;
	double result;

	cout << "\nEnter length here : ";
	cin >> lenght;
	cout << "\nEnter breath here : ";
	cin >> breadth;
	result = lenght * breadth;
	cout << "\n Result : ";
	cout << result;
}

void Triangle()
{
	double base;
	double height;
	double result;

	cout << "Enter base Here : ";
	cin >> base;
	cout << "\nEnter height Here : ";
	cin >> height;

	result = 0.5 * base * height;

	cout << "\nResult : ";
	cout << result;
}

int main()
{
	int option;

	cout << "Select your desired Shape! \n";
	cout << "1. Square \n";
	cout << "2. Rectangle \n";
	cout << "3. Triangle(90 degree) \n";

	cout << "Enter your option here : ";
	cin >> option;

	if (option == 1)
	{
		Sqre();
	}
	else if (option == 2)
	{
		Rect();
	}
	else if (option == 3)
	{
		Triangle();
	}
	else
	{
		cout << "Please Select Valid Option!";
		return 0;
	}
}

