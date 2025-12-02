/*FileName: Ch6_Programming_Project.cpp
Programmer: Sean G
Project: Paint Job Estimator
Requirements:

Use modular functions to calculate gallons of paint, labor hours, and costs.
Validate input for number of rooms, paint price, and square footage.
Apply constants for labor and material rates.
Generate a complete cost estimate for paint jobs using accumulated totals.


*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
// Constants
const double Gallons_per_sqft = 1.0 / 110.0;
const double Labor_per_sqft = 8.0 / 110.0;
const double Labor_charge_per_hour = 25.0;

int getrooms();
double getsqft();
double getpricepergallon();
int gallonsforroom(double sqft);
void displayestimate(double paintcharge, int gallonsneeded, double laborcharge, double laborhours);

int main() 
{
	double paintCharge = 0.0;
	double laborCharge = 0.0;
	int gallonsNeeded = 0;
	double laborHours = 0.0;
	int numRooms = getrooms();
	for (int i = 0; i < numRooms; ++i) {
		double squareFeet = getsqft();
		int gallons = gallonsforroom(squareFeet);
		gallonsNeeded += gallons;
		double paintPrice = getpricepergallon();
		paintCharge += gallons * paintPrice;
		double labor = squareFeet * Labor_per_sqft;
		laborHours += labor;
		laborCharge += labor * Labor_charge_per_hour;
	}
	displayestimate(paintCharge, gallonsNeeded, laborCharge, laborHours);
	return 0;
}
int getrooms() 
{
	int rooms;
	do {
		cout << "Enter the number of rooms to be painted (must be > 0): ";
		cin >> rooms;
	} while (rooms < 1);
	return rooms;
}
double getsqft() 
{
	double sqft;
	do {
		cout << "Enter the square footage of wall space in the room (must be >= 0): ";
		cin >> sqft;
	} while (sqft < 0);
	return sqft;
}
double getpricepergallon() 
{
	double price;
	do {
		cout << "Enter the price of paint per gallon (must be >= $10.00): ";
		cin >> price;
	} while (price < 10.0);
	return price;
}
int gallonsforroom(double sqft) 
{
	return static_cast<int>(ceil(sqft * Gallons_per_sqft));
}
void displayestimate(double paintcharge, int gallonsneeded, double laborcharge, double laborhours) 
{
	cout << fixed << setprecision(2);
	cout << "\nEstimate for Painting Job:\n";
	cout << "-----------------------------------\n";
	cout << "Gallons of paint required: " << gallonsneeded << " gallons\n";
	cout << "Hours of labor required: " << laborhours << " hours\n";
	cout << "Cost of the paint: $" << paintcharge << "\n";
	cout << "Labor charges: $" << laborcharge << "\n";
	cout << "Total cost of the paint job: $" << (paintcharge + laborcharge) << "\n";
}