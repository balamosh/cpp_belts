#include "student.h"

Student::Student(const std::string& name, const std::string& favouriteSong) 
    : Human("Student", name), FavouriteSong(favouriteSong) {}


void Student::Learn() { 
    Action("learns"); 
}

void Student::Walk(const std::string& destination) {
    Human::Walk(destination);
    SingSong();
}

void Student::SingSong() {
    Action("sings a song", FavouriteSong);
}
