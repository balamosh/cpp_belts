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

// Реализуйте для класса Rational операторы ==, + и -

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

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
