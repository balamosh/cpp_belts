#include <iostream>
#include "names2.cpp"

int main(){
    Person person;

    int year = 1;
    person.ChangeFirstName(year, std::to_string(year)+"_first");
    person.ChangeLastName(year, std::to_string(year)+"_last");
    std::cout << "year: " << year << '\n';
    std::cout << person.GetFullNameWithHistory(year) << '\n';

    year = 2;
    person.ChangeFirstName(year, std::to_string(year)+"_first");
    person.ChangeLastName(year, std::to_string(year)+"_last");
    std::cout << "year: " << year << '\n';
    std::cout << person.GetFullNameWithHistory(year) << '\n';

    year = 3;
    person.ChangeFirstName(year, std::to_string(2)+"_first");
    person.ChangeLastName(year, std::to_string(2)+"_last");
    std::cout << "year: " << year << '\n';
    std::cout << person.GetFullNameWithHistory(year) << '\n';

    return 0;
}

