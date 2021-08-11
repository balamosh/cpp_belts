#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <memory>
#include <cmath>

using namespace std;

class Figure {
public:
	Figure(const string& new_name, double new_perimeter, double new_area)
	: name(new_name)
	, perimeter(new_perimeter)
	, area(new_area) {}

	virtual string	Name() const = 0;

	virtual double	Perimeter() const = 0;

	virtual double	Area() const = 0;

	const string	name;
	const double	perimeter;
	const double	area;
};

class Rect : public Figure {
public:
	Rect(int width, int height)
	: Figure("RECT", 2 * width + 2 * height, width * height) {}

	string	Name() const override {
		return (name);
	}

	double	Perimeter() const override {
		return (perimeter);
	}

	double	Area() const override {
		return (area);
	}
};

class Triangle : public Figure {
public:
	Triangle(int a, int b, int c)
	: Figure("TRIANGLE",
			a + b + c,
			sqrt((a + b + c) / 2.)
			* sqrt(abs((a + b + c) / 2. - a))
			* sqrt(abs((a + b + c) / 2. - b))
			* sqrt(abs((a + b + c) / 2. - c))) {}
	
	string	Name() const override {
		return (name);
	}

	double	Perimeter() const override {
		return (perimeter);
	}

	double	Area() const override {
		return (area);
	}
};

class Circle : public Figure {
public:
	Circle(int r) : Figure("CIRCLE", 2 * 3.14 * r, 3.14 * r * r) {}

	string	Name() const override {
		return (name);
	}

	double	Perimeter() const override {
		return (perimeter);
	}

	double	Area() const override {
		return (area);
	}
};

shared_ptr<Figure>	CreateFigure(istringstream& is) {
	string	type;
	is >> type;
	if (type == "RECT")
	{
		int	width, height;
		is >> width >> height;
		return (make_shared<Rect>(width, height));
	} else if (type == "TRIANGLE") {
		int	a, b, c;
		is >> a >> b >> c;
		return (make_shared<Triangle>(a, b, c));
	} else if (type == "CIRCLE") {
		int	r;
		is >> r;
		return (make_shared<Circle>(r));
	} else {
		return (make_shared<Rect>(0, 0));
	}
}

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
