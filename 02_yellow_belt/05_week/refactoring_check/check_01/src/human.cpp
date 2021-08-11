#include "human.h"

Human::Human(const std::string &type, const std::string &name) : Type(type), Name(name) {}

void Human::Walk(const std::string& destination) {
    Action("walks to", destination);
}

std::string Human::GetType() const {
    return Type;
}

std::string Human::GetName() const {
    return Name;
}

void Human::Action(const std::string& do_smth) const {
    std::cout << Type << ": " << Name << " " << do_smth << std::endl;
}

void Human::Action(const std::string& do_smth, const std::string& on_what) const {
    std::cout << Type << ": " << Name << " " << do_smth << ": " << on_what << std::endl;
}

