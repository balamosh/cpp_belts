#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Так как с заданием знакомы все, то прокомментирую решение только здесь, а не в коде ниже
// В силу малого количества кода проект находится в одном файле
// Все методы всех классов тривиальны и тело большинства из них состоит из одной строки
// в силу этого, а также того, что методы, определенные в классе, являются inline
// каждый метод определяется в соответствующем классе  
// Для методов, не меняющих данные, установлен классификатор const
// Строки передаются по константным ссылкам
// Класс Person является абстрактным классом т.к. консруктор определен с модификатором protected
// Класс Person выступает в качестве базового для производных классов Student, Teacher, Policeman 
// Функция Walk является виртуальной и перекрывается только в классе Student, поскольку для этого класса она отличается
// Метод Prefix возвращает строку, содержащую тип и имя соответствующей персоны, этот метод защищенный, 
// поскольку считаю, что он имеет смысл только для потомков класса Person


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PERSON~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class Person {
public:
    virtual void Walk(const string& destination) const {
        cout << Type << ": " << Name << " walks to: " << destination << endl;
    }
    const string Type;
    const string Name;
  
protected:
    Person(const string& type, const string& name) :Type{ type }, Name{ name } {}   
    string Prefix() const { return Type + ": " + Name; }


};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~STUDENT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class Student : public Person {
public:
    Student(const string& name, const string& favourite_song) : Person{ "Student",name }, FavouriteSong{ favourite_song } {}
    void Learn() {
        cout << Prefix() << " learns" << endl;
    }
    void Walk(const string& destination) const override {
        Person::Walk(destination);
        cout << Prefix() << " sings a song: " << FavouriteSong << endl;
    }
    void SingSong() {
        cout << Prefix() << " sings a song: " << FavouriteSong << endl;
    }
    const string FavouriteSong;
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~TEACHER~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class Teacher : public Person {
public:
    Teacher(const string& name, const string& subject) :Person{ "Teacher",name }, Subject{ subject } {}
    void Teach() {
        cout << Prefix() << " teaches: " << Subject << endl;
    }
    const string Subject;
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~POLICEMAN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class Policeman : public Person {
public:
    Policeman(const string& name) :Person{ "Policeman", name} {}
    void Check(Person& p) const {
        cout << Prefix() << " checks " << p.Type << ". "
            << p.Type << "'s name is: " << p.Name << endl;
    }   
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~VISIT_PLACE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void VisitPlaces(Person& person, const vector<string>& places) {
    for (const auto& p : places) {
        person.Walk(p);
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MAIN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, { "Moscow", "London" });
    p.Check(s);
    VisitPlaces(s, { "Moscow", "London" });

    system("pause");
    return 0;
}
