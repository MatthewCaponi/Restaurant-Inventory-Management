#include "Date.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
Date::Date()
{
	time_t now_t;
	tm now;
	time(&now_t);
	localtime_s(&now, &now_t);
	month = now.tm_mon + 1;
	day = now.tm_mday;
	year = now.tm_year + 1900;
}

Date::Date(const string &stringDate)
{
	istringstream in;
	string strMonth = stringDate.substr(0, 2),
		strDay = stringDate.substr(3, 2),
		strYear = stringDate.substr(6);
	in.str(strMonth);
	in >> month;
	in.clear();
	in.str(strDay);
	in >> day;
	in.clear();
	in.str(strYear);
	in >> year;
}

Date::Date(const Date &d, int daysFromDate)
{
	*this = d;
	if (daysFromDate > 0)
	{
		for (int i = 0; i < daysFromDate; i++)
			++*this;
	} 
	else if (daysFromDate < 0)
	{
		for (int i = 0; i < -daysFromDate; i++)
		{
			--*this;
		}
	}
}

Date::Date(int newMonth, int newDay, int newYear)
{
	month = newMonth;
	day = newDay;
	year = newYear;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setters
int Date::getMonth() const
{
	return month;
}

int Date::getDay() const
{
	return day;
}

int Date::getYear() const
{
	return year;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helpers
string Date::toFormat() const
{
	ostringstream out;
	out << setfill('0') << setw(2) << right << month;
	out << "/";
	out << setfill('0') << setw(2) << right << day;
	out << "/";
	out << setfill('0') << setw(4) << right << year;
	return out.str();
}

string Date::toDigit() const
{
	ostringstream out;
	out << setfill('0') << setw(2) << right << month;
	out << setfill('0') << setw(2) << right << day;
	out << setfill('0') << setw(4) << right << year;
	return out.str();
}

Date Date::beginWeek() const
{
	int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	Date d(*this);
	d.year -= d.month < 3;
	int daysFromSunday = (d.year + d.year / 4 + d.year / 400 + t[d.month - 1] + d.day) % 7;
	d = Date(*this) - daysFromSunday;
	return d;
}

ostream& operator<<(ostream& out, const Date &d)
{
	string months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" }; 
	out << months[d.month - 1] << " " << setfill('0') << setw(2) << right << d.day << ", " << d.year;
	return out;
}

Date Date::operator+(int days) const
{
	Date d(*this, days);
	return d;
}

Date Date::operator-(int days) const
{
	Date d(*this, -days);
	return d;
}

Date& Date::operator++()
{
	++day;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day > 31)
		{
			day = 1;
			++month;
		}
	}
	else if (month == 2)
	{
		if (year % 4 == 0)
		{
			if (day > 29)
			{
				day = 1;
				++month;
			}
		}
		else
		{
			if (day > 28)
			{
				day = 1;
				++month;
			}
		}
	} 
	else
	{
		if (day > 30)
		{
			day = 1;
			++month;
		}
	}
	if (month > 12)
	{
		month = 1;
		++year;
	}
	return *this;
}

Date& Date::operator--()
{
	--day;
	if (month == 3)
	{
		if (day < 1)
		{
			if (year % 4 == 0)
				day = 29;
			else
				day = 28;
			--month;
		}
	}
	else if (month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11 || month == 1)
	{
		if (day < 1)
		{
			day = 31;
			--month;
		}
	} 
	else
	{
		if (day < 1)
		{
			day = 30;
			--month;
		}
	}
	if (month < 1)
	{
		month = 12;
		--year;
	}
	return *this;

}

bool Date::operator==(const Date &d) const
{
	return month == d.month && day == d.day && year == d.year;
}

bool Date::operator<(const Date &d) const
{
	if (year == d.year)
	{
		if (month == d.month)
		{
			return (day < d.day);
		}
		else
			return (month < d.month);
	}
	else
		return (year < d.year);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Destructor
Date::~Date() {};

