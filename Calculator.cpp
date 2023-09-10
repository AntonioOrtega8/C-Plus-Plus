#include <iostream>
using namespace std;
double sum(double &num1, double &num2);
double diff(double &num1, double &num2);
double mult(double &num1, double &num2);
double div(double &num1, double &num2);
int rem(int &num1, int &num2);
void menu(char &selection, double &num1, double &num2);

int main()
{
	double num1, num2;
	char selection;
	menu(selection, num1, num2);
	system("pause");
}

double sum(double &num1, double &num2)
{
	double result;
	result = (num1 + num2);
	return result;
}

double diff(double &num1, double &num2)
{
	double result;
	result = (num1 - num2);
	return result;
}

double mult(double &num1, double &num2)
{
	double result;
	result = (num1 * num2);
	return result;
}

double div(double &num1, double &num2)
{
	double result;
	result = (num1 / num2);
	return result;
}


int rem(int &num1, int &num2)
{
	int result;
	result = (num1 % num2);
	return result;
}

void menu(char &selection, double &num1, double &num2)
{
	double solution;
	cout << "please select your 1st number" << endl;
	cin >> num1;
	cout << "please select your 2nd number" << endl;
	cin >> num2;
	cout << "please select your opperation" << endl;
	cout<< "Sum      =  s" << endl
		<< "Diffrence = d" << endl
		<< "Product   = p" << endl
		<< "Quotient  = q" << endl
		<< "Remainder = r" << endl;
	cin >> selection;

	switch (selection)
	{
	case 's':
	{
		solution = sum(num1, num2);
		break;
	}

	case 'd':
	{
		solution = diff(num1, num2);
		break;
	}
	case 'p':
	{
		solution = mult(num1, num2);
		break;
	}
	case 'q':
	{
		solution = div(num1, num2);
		break;
	}
	case 'r':
	{
		int A = num1;
		int B = num2;
		solution = rem(A, B);
		break;
	}
	default:
		cout << "Invalid choice unable to solve" << endl;
		solution = 0;


	}

	cout << "The answer is: " << solution << endl;

}
