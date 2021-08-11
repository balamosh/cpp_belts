#include "policeman.h"

Policeman::Policeman(std::string name) 
    : Human("Policeman", name) {}

void Policeman::Check(std::shared_ptr<Human> h) const {
    std::string arg1 = "checks " + h->GetType() + ". " 
        + h->GetType() + "'s name is";
    Action(arg1, h->GetName());
}
