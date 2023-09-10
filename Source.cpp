#include <iostream>
using namespace std;


struct Speed
{
public:
	double distance5Hours, distance8Hours, distance12Hours;
};

double speed5(Speed &speed);
double speed8(Speed &speed);
double speed12(Speed &speed);
void showdata(Speed &speed);
int main()
{
	Speed car;
	showdata(car);
	system("pause");
}

double speed5(Speed &speed)
{
	return speed.distance5Hours = 5 * 60;
}

double speed8(Speed &speed)
{
	return speed.distance8Hours= 8 * 60;
}

double speed12(Speed &speed)
{
	return speed.distance12Hours= 12 * 60;
}

void showdata(Speed &speed)
{
	cout << "The car will travel the following distances" << endl;
	cout << speed5(speed) <<  " miles in 5 hours" << endl;
	cout << speed8(speed) <<  " miles in 8 hours" << endl;
	cout << speed12(speed) << " miles in 12 hours" << endl;

}
/*
Name: Antonio Ortega
Date: 09/07/19
Project name 2-5
The car will travel the following distances
300 miles in 5 hours
480 miles in 8 hours
720 miles in 12 hours
Press any key to continue . . .
*/