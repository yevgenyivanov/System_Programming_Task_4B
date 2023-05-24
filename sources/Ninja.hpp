#pragma once
#include <string>
#include <stdio.h>
#include "Point.hpp"
#include "Character.hpp"
class Ninja : public Character
{
private:
    int _velocity;

public:
    Ninja(const std::string &_name,int _hitPoints, Point &_startingLocation, int _velocity): Character(_name, _hitPoints, _startingLocation), _velocity(_velocity){};
    void move(Character *);
    void slash(Character *);  
    void attack(Character *_target) override;
    std::string print() override;
    //
    // copy constructor
    Ninja(Ninja &) = default;
    // copy assignment operator
    Ninja &operator=(const Ninja &) = default;
    // move constructor
    Ninja(Ninja &&) = default;
    // move assignment operator
    Ninja &operator=(Ninja &&) = default;
    // destructor
    ~Ninja() override = default;
};
