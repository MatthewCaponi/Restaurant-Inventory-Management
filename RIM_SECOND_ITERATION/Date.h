#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
using namespace std;

class Date
{
public:
	// Constructors
	Date();
	Date(const string &stringDate);
	Date(const Date &d, int daysFromD);
	Date(int newMonth, int newDay, int newYear);
	// Getters
	int getMonth() const;
	int getDay() const;
	int getYear() const;
	// Helpers
	string toDigit() const;
	string toFormat() const;
	Date beginWeek() const;
	friend ostream& operator<<(ostream& out, const Date &d);
	Date operator+(int days) const;
	Date operator-(int days) const;
	Date& operator++();
	Date& operator--();
	bool operator==(const Date &d) const;
	bool operator <(const Date &d) const;
	// Destructors
	~Date();
private:
	int month, day, year;
};

#endif
