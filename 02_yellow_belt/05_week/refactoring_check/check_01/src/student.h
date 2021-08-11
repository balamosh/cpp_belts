#pragma once
#include "human.h"


class Student : public Human{
public:
    Student(const std::string& name, const std::string& favouriteSong);
    void Learn();
    void Walk(const std::string& destination) override;
    void SingSong();

public:
    const std::string FavouriteSong;
};


