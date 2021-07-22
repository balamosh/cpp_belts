#include <iostream>
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
	Rational	reversed_rhs(rhs.Denominator(), rhs.Numerator());
	return (lhs * reversed_rhs);
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

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    cout << "OK" << endl;
    return 0;
}
