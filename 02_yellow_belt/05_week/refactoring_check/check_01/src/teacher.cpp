#include "teacher.h"

Teacher::Teacher(const std::string& name, const std::string& subject) 
    : Human("Teacher", name), Subject(subject) {}

void Teacher::Teach() const {
    Action("teacher", Subject);
}
