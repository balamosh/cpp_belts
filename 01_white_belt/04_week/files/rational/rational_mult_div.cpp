#include <iostream>
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

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
