#include <iostream>
#include <exception>
#include <sstream>
#include <numeric>
#include <cmath>
using namespace std;

// Вставьте сюда реализацию класса Rational из первой части

class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
	numerator = 0;
	denominator = 1;
    }

    Rational(int new_numerator, int new_denominator) {
        // Реализуйте конструктор
	numerator = abs(new_numerator);
	denominator = abs(new_denominator);
	if (denominator == 0)
		throw invalid_argument("Invalid argument");
	int	GCD = gcd(numerator, denominator);
	int	sgn = sign(new_numerator) * sign(new_denominator);
	if (GCD != 0)
	{
		numerator /= GCD;
		denominator /= GCD;
	}
	numerator *= sgn;
    }

    int Numerator() const {
        // Реализуйте этот метод
	return (numerator);
    }

    int Denominator() const {
        // Реализуйте этот метод
	return (denominator);
    }

private:
    int	sign(int val)
    {
	    return (val > 0) - (val < 0);
    }

    // Добавьте поля
    int	numerator;
    int	denominator;
};

// Вставьте сюда реализацию operator == для класса Rational из второй части

bool	operator==(const Rational& lhs, const Rational& rhs)
{
	return (lhs.Numerator() == rhs.Numerator() &&
		lhs.Denominator() == rhs.Denominator());
}

Rational	operator+(const Rational& lhs, const Rational& rhs)
{
	int	LCM = lcm(lhs.Denominator(), rhs.Denominator());
	int new_numerator = lhs.Numerator() * (LCM / lhs.Denominator())
			+ rhs.Numerator() * (LCM / rhs.Denominator());
	return (Rational(new_numerator, LCM));
}

Rational	operator-(const Rational& lhs, const Rational& rhs)
{
	int	LCM = lcm(lhs.Denominator(), rhs.Denominator());
	int new_numerator = lhs.Numerator() * (LCM / lhs.Denominator())
			- rhs.Numerator() * (LCM / rhs.Denominator());
	return (Rational(new_numerator, LCM));
}

// Реализуйте для класса Rational операторы * и /

Rational	operator*(const Rational& lhs, const Rational& rhs)
{
	return (Rational(lhs.Numerator() * rhs.Numerator(),
			lhs.Denominator() * rhs.Denominator()));
}

Rational	operator/(const Rational& lhs, const Rational& rhs)
{
	try
	{
		Rational	reversed_rhs(rhs.Denominator(), rhs.Numerator());
		return (lhs * reversed_rhs);
	}
	catch (invalid_argument& ex)
	{
		throw domain_error("Division by zero");
	}
}

// Реализуйте для класса Rational операторы << и >>

istream&	operator>>(istream& in_stream, Rational& r)
{
	int	new_numerator, new_denominator;
	char	sep = ' ';
	if (in_stream >> new_numerator &&
		in_stream >> sep &&
		in_stream >> new_denominator &&
		sep == '/')
	{
		r = Rational(new_numerator, new_denominator);
	}
	return (in_stream);
}

ostream&	operator<<(ostream& out_stream, const Rational& r)
{
	if (!out_stream.eof())
		out_stream << r.Numerator() << '/' << r.Denominator();
	return (out_stream);
}


// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а

bool		operator<(const Rational& lhs, const Rational& rhs)
{
	int	LCM = lcm(lhs.Denominator(), rhs.Denominator());
	int	l_num = lhs.Numerator() * (LCM / lhs.Denominator());
	int	r_num = rhs.Numerator() * (LCM / rhs.Denominator());
	return (l_num < r_num);
}

bool		operator>(const Rational& lhs, const Rational& rhs)
{
	return (rhs < lhs);
}

int	main(void)
{

	Rational	r1, r2;
	char		op;
	try
	{
		cin >> r1 >> op >> r2;
		if (op == '+')
			cout << r1 + r2 << endl;
		else if (op == '-')
			cout << r1 - r2 << endl;
		else if (op == '*')
			cout << r1 * r2 << endl;
		else if (op == '/')
		{
			try
			{
				cout << r1 / r2 << endl;
			}
			catch (domain_error& ex)
			{
				cout << ex.what() << endl;
			}
		}
	}
	catch (invalid_argument& ex)
	{
		cout << ex.what() << endl;
	}
	return (0);
}
