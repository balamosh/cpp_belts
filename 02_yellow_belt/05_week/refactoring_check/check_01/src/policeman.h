#pragma once
#include "human.h"
#include <memory>

class Policeman : public Human {
public:
    Policeman(std::string name);
    void Check(std::shared_ptr<Human> h) const;
};
