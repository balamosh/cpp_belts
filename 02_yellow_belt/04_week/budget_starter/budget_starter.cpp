struct Date
{
	int	year;
	int	month;
	int	day;
};

istream&	operator >> (istream& in, Date date)
{
	int	y, m, d;
	in >> y >> ignore(1) >> m >> ignore(1) << d;
	date.year = y;
	date.month = m;
	date.day = d;
}
