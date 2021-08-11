#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Person {
public:

	Person(const string& name, const string& type)
	: Name(name)
	, Type(type) {}

	void	PrintInfo() const {
		cout << Type << ": " << Name;
	}
	
	virtual void	Walk(const string& destination) const {
		PrintInfo();
		cout << " walks to: " << destination << endl;
    }

public:
	const string	Name;
	const string	Type;
};


class Student : public Person {
public:

    Student(const string& name, const string& favouriteSong) 
	: Person(name, "Student")
	, FavouriteSong(favouriteSong) {}

    void	Learn() const {
		PrintInfo();
        cout << " learns" << endl;
    }

	void	SingSong() const {      
		PrintInfo();
		cout << " sings a song: " << FavouriteSong << endl;
    }

    void	Walk(const string& destination) const override {
		PrintInfo();      
		cout << " walks to: " << destination << endl;
        SingSong();
    }

public:
    const string	FavouriteSong;
};


class Teacher : public Person {
public:

    Teacher(const string& name, const string& subject)
	: Person(name, "Teacher")
	, Subject(subject) {}

    void	Teach() const {
		PrintInfo();
        cout << " teaches: " << Subject << endl;
    }

public:
    const string	Subject;
};


class Policeman : public Person {
public:
    
	Policeman(const string& name)
	: Person(name, "Policeman") {}

    void	Check(const Person& p) const {
		PrintInfo();
        cout << " checks " << p.Type << ". " 
			<< p.Type << "'s name is: " << p.Name << endl;
    }    
};


void	VisitPlaces(Person person, const vector<string>& places) {
    for (const auto& p : places) {
        person.Walk(p);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
