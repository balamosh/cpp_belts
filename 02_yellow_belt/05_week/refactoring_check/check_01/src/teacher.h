#pragma once
#include "human.h"

class Teacher : public Human {
public:
    Teacher(const std::string& name, const std::string& subject);
    void Teach() const;

private:
    const std::string Subject;
};

