#pragma once

#include <iostream>

using namespace std;

class Date {
public:

	Date(int y, int m, int d);
	int	GetYear() const;
	int	GetMonth() const;
	int	GetDay() const;
	string	convert_to_string() const;

private:
	int	year;
	int	month;
	int	day;
};

Date		ParseDate(istream& is);

ostream&	operator << (ostream& os, const Date& date);

bool		operator < (const Date& lhs, const Date& rhs);
bool		operator <= (const Date &lhs, const Date &rhs);
bool		operator > (const Date &lhs, const Date &rhs);
bool		operator >= (const Date &lhs, const Date &rhs);
bool		operator == (const Date &lhs, const Date &rhs);
bool		operator != (const Date &lhs, const Date &rhs);