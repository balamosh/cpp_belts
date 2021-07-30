#include <iostream>
#include <numeric>
#include <cmath>
using namespace std;

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
