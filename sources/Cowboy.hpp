#pragma once
#include "Character.hpp"
#include <string>
class Cowboy : public Character
{
private:
    int _ammo;

public:
    // constructor
    Cowboy(std::string, Point);
    // copy constructor
    Cowboy(Cowboy &) = default;
    // copy assignment operator
    Cowboy &operator=(const Cowboy &) = default;
    // move constructor
    Cowboy(Cowboy &&) = default;
    // move assignment operator
    Cowboy &operator=(Cowboy &&) = default;
    // destructor
    ~Cowboy() override = default;
    void shoot(Character *);
    bool hasboolets();
    void reload();
    void attack(Character *_target) override;
    std::string print() override;
};
