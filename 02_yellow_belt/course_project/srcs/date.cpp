#include "date.h"

#include <iomanip>
#include <tuple>
#include <sstream>

using namespace std;

// Date methods

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

int	Date::GetYear() const { return (year); }

int	Date::GetMonth() const { return (month); }

int	Date::GetDay() const { return (day); }

string	Date::convert_to_string() const {
	ostringstream	out;
	out << Date(year, month, day);
	return (out.str());
}

// Functions

Date		ParseDate(istream& is) {
	int	year, month, day;
	is >> year;
	is.ignore(1);
	is >> month;
	is.ignore(1);
	is >> day;
	return (Date(year, month, day));
}

ostream&	operator << (ostream& os, const Date& date) {
	os << setfill('0');
	os << setw(4) << date.GetYear() 
		<< '-' 
		<< setw(2) << date.GetMonth() 
		<< '-' 
		<< setw(2) << date.GetDay();
	return (os);
}

bool		operator < (const Date& lhs, const Date& rhs) {
	return (make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) <
			make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()));
}