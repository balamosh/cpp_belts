#include "date.h"

#include <iomanip>

using namespace std;

// Date methods

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

int	Date::GetYear() const { return (year); }

int	Date::GetMonth() const { return (month); }

int	Date::GetDay() const { return (day); }

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
	os << date.GetYear() << '-' << date.GetMonth() << '-' << date.GetDay();
	return (os);
}
