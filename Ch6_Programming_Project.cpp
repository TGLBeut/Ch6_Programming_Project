/*FileName: Ch6_Programming_Project.cpp
Programmer: Sean G
Project: Celsius Temperature Table
Requirements:

Write a modular program that generates a temperature conversion table.
Use named constants for flexibility and reuse.
Implement a getCelsius function for conversion.
Display tabular data with correct formatting (titles, labels, precision).
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int Min_Fahrenheit = 0;
const int Max_Fahrenheit = 20;
const double Conversion_Factor = 5.0 / 9.0;
const int Fahrenheit_Offset = 32;
const int Column_Width = 12;
const int Decimal_Precision = 1;
double getcelsius(int fahrenheit);

int main() 
{
	cout << "Celsius Temperature Table\n";
	cout << "-------------------------\n";
	
	cout << right << setw(Column_Width) << "Fahrenheit"
		 << right << setw(Column_Width) << "Celsius\n";
	
	for (int fahrenheit = Min_Fahrenheit; fahrenheit <= Max_Fahrenheit; ++fahrenheit) {
		double celsius = getcelsius(fahrenheit);
		cout << right << setw(Column_Width) << fixed << setprecision(Decimal_Precision) << fahrenheit
			 << right << setw(Column_Width) << fixed << setprecision(Decimal_Precision) << celsius << endl;
	}
	return 0;
}
double getcelsius(int fahrenheit) {
	return Conversion_Factor * (fahrenheit - Fahrenheit_Offset);
}