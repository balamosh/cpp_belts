#include "human.h"
#include "student.h"
#include "teacher.h"
#include "policeman.h"
#include <memory>
#include <vector>


void VisitPlaces(std::shared_ptr<Human> h, const std::vector<std::string>& places){
    for (const auto& p : places)
        h->Walk(p);
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(std::make_shared<Teacher>(t), {"Moscow", "London"});
    p.Check(std::make_shared<Student>(s));
    VisitPlaces(std::make_shared<Student>(s), {"Moscow", "London"});
    return 0;
}
