#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {

public:

	Person(const string& type, const string& name)
		: _type(type), _name(name) {}

	virtual void Walk(const string& destination) const {
		cout << getTypeAndName() << " walks to: " << destination << endl;
	}

	string getName() const {
		return _name;
	}

	string getType() const {
		return _type;
	}

	string getTypeAndName() const {
		return string(_type + ": " + _name);
	}

private:
	const string _type;
	const string _name;
};


class Student : public Person {

public:

	Student(const string& name, const string& favouriteSong)
		: Person("Student", name), _favouriteSong(favouriteSong) {}

	void Learn() const {
		cout << getTypeAndName() << " learns" << endl;
	}

	void Walk(const string& destination) const override {
		Person::Walk(destination);
		SingSong();
	}

	void SingSong() const {
		cout << getTypeAndName() << " sings a song: " << _favouriteSong << endl;
	}

private:
	const string _favouriteSong;
};



class Teacher : public Person {

public:

	Teacher(const string& name, const string& subject) : Person("Teacher", name), _subject(subject) {}

	void Teach() const {
		cout << getTypeAndName() << " teaches: " << _subject << endl;
	}

private:
	const string _subject;
};


class Policeman : public Person {

public:

	Policeman(const string& name) : Person("Policeman", name) {}

	void Check(const Person& p) {
		cout << getTypeAndName() << " checks " << p.getType() << ". " << p.getType() << "'s name is: " << p.getName() << endl;
	}
};

void VisitPlaces(const Person& person, const vector<string>& places) {

	for (const auto& p : places) {
		person.Walk(p);
	}
}


int main() {
	Teacher t("Jim", "Math");
	Student s("Ann", "We will rock you");
	Policeman p("Bob");

	VisitPlaces(t, { "Moscow", "London" });
	p.Check(s);
	VisitPlaces(s, { "Moscow", "London" });
	return 0;
}
