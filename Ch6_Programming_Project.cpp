/*FileName: Ch6_Programming_Project.cpp
Programmer: Sean G
Project: Safest Driving Area
Requirements:

Write modular functions to gather and validate accident data.
Use comparison functions (isLower) to determine minimum values.
Implement a program that identifies the safest region by number of accidents.
Display results clearly using modular output functions.
*/

#include <iostream>
#include <string>
using namespace std;

void getreginfo(string & regionname, int& numaccidents);
bool islower(int accidents1, int accidents2);
void showlowest(const string & regionname, int numaccidents);
int main() 
{
	const int Num_Regions = 3;
	string lowestregionname;
	int lowestaccidents;
	
	getreginfo(lowestregionname, lowestaccidents);
	
	for (int i = 1; i < Num_Regions; ++i) {
		string currentregionname;

		int currentaccidents;
		getreginfo(currentregionname, currentaccidents);
		
		if (islower(currentaccidents, lowestaccidents)) {
			lowestregionname = currentregionname;
			lowestaccidents = currentaccidents;
		}
	}
	showlowest(lowestregionname, lowestaccidents);
	return 0;
}
void getreginfo(string & regionname, int & numaccidents) {
	cout << "Enter the name of the region: ";
	getline(cin, regionname);

	do {
		cout << "Enter the number of accidents reported last year (>= 0): ";
		cin >> numaccidents;

		if (numaccidents < 0) {
			cout << "Failed input. Please enter a number greater than 0.\n";
		}
	} while (numaccidents < 0);
	cin.ignore();
}
bool islower(int accidents1, int accidents2) {
	return accidents1 <= accidents2;
}
void showlowest(const string & regionname, int numaccidents) {
	cout << "The safest region for driving is: " << regionname << endl;
	cout << "Number of accidents reported last year: " << numaccidents << endl;
}