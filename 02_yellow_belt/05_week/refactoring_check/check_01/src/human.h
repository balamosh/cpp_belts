#pragma once
#include <string>
#include <iostream>

class Human{
public:
    Human(const std::string &type, const std::string &name);
    virtual void Walk(const std::string& destination);
    std::string GetType() const;
    std::string GetName() const;

protected:
    void Action(const std::string& do_smth) const;
    void Action(const std::string& do_smth, const std::string& on_what) const;
    const std::string Type, Name;
};
