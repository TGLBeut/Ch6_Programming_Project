/*FileName: Ch6_Programming_Project.cpp
Programmer: Sean G
Project: Star Search
Requirements:

Use modular functions to gather and validate judge scores.
Apply functions to determine minimum and maximum scores.
Calculate average score by dropping the highest and lowest.
Design modular solutions where each function has a single, clear purpose.
*/

#include <iostream>
#include <iomanip>
using namespace std;

double getscore();
bool islower(double, double);
bool ishigher(double, double);
double calcaverage(double, double, double);

int main() {
	double score, total = 0.0, minscore, maxscore, average;
	
	score = getscore();
	minscore = score;
	maxscore = score;
	total += score;
	
	for (int i = 1; i < 5; i++) {
		score = getscore();
		total += score;
		if (islower(score, minscore)) {
			minscore = score;
		}
		if (ishigher(score, maxscore)) {
			maxscore = score;
		}
	}
	average = calcaverage(total, minscore, maxscore);
	
	cout << fixed << setprecision(2);
	cout << "The performer's average score is: " << average << endl;
	return 0;
}
double getscore() {
	double score;
	cout << "Enter the judge's score (0-10): ";
	cin >> score;
	while (score < 0.0 || score > 10.0) {
		cout << "Invalid score. Please enter a score between 0 and 10: ";
		cin >> score;
	}
	return score;
}
bool islower(double a, double b) {
	return a <= b;
}
bool ishigher(double a, double b) {
	return a >= b;
}
double calcaverage(double total, double minscore, double maxscore) {
	return (total - minscore - maxscore) / 3.0;
}