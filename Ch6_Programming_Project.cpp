/*FileName: Ch6_Programming_Project.cpp
Programmer: Sean G
Project: Rectangle Properties
Requirements:

Use modular functions for input, validation, calculation, and output.
Pass values by reference when functions return multiple results.
Calculate and display perimeter and area for rectangles.
Implement repetition controlled by user choice.
*/

#include <iostream>
#include <iomanip>
using namespace std;

void getdimensions(double & length, double & width);
void calculateperimeterarea(double length, double width, double & perimeter, double & area);
void displayresults(double length, double width, double perimeter, double area);
bool asktocontinue();

int main() 
{
	double length, width, perimeter, area;
	bool continueProgram = true;

	while (continueProgram) {
		getdimensions(length, width);
		calculateperimeterarea(length, width, perimeter, area);
		displayresults(length, width, perimeter, area);
		continueProgram = asktocontinue();
	}
	return 0;
}
void getdimensions(double & length, double & width) 
{
	do {
		cout << "All numbers must be greater than 0.\n";
		cout << "Enter the length of the rectangle: ";
		cin >> length;
		if (length <= 0) {
			cout << "Invalid input. Length must be greater than 0.\n";
		}
	} while (length <= 0);

	do {
		cout << "Enter the width of the rectangle: ";
		cin >> width;
		if (width <= 0) {
			cout << "Invalid input. Width must be greater than 0.\n";
		}
	} 
	while (width <= 0);
}
void calculateperimeterarea(double length, double width, double& perimeter, double& area) {
	perimeter = 2 * (length + width);
	area = length * width;
}
void displayresults(double length, double width, double perimeter, double area) {
	cout << fixed << setprecision(2);
	cout << "For a rectangle with the length of " << length << " and the width of " << width << ":\n";
	cout << "Perimeter: " << perimeter << endl;
	cout << "Area: " << area << endl;
}
bool asktocontinue() {
	char choice;
	cout << "Do you want to calculate another rectangle? (y/n): ";
	cin >> choice;
	cout << endl;

	return (choice == 'y' || choice == 'Y');
}