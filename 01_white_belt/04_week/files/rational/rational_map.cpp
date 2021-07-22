#include <map>
#include <set>
#include <vector>
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

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
