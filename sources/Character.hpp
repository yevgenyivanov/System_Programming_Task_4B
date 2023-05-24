#pragma once
#include <string>
#include "Character.hpp"
#include "Point.hpp"
class Character
{
private:
    std::string _name;
    int _hitPoints;
    Point _currLocation;
    bool _inTeam;

public:
    // constructor
    Character(const std::string &, int, Point);
    // copy constructor
    Character(Character &) = default;
    // copy assignment operator
    Character &operator=(const Character &) = default;
    // move constructor
    Character(Character &&) = default;
    // move assignment operator
    Character &operator=(Character &&) = default;
    // destructor
    virtual ~Character() = default;
    //
    //funcs
    // check if character has more than 0 hp
    bool isAlive();
    double distance(Character *);
    void hit(int);
    // getters
    std::string getName();
    Point getLocation();
    virtual std::string print();
    // helper func
    virtual void attack(Character *);
    int get_hp();
    void setTeam();
    bool isInTeam();
    void setLocation(Point);
};
namespace ariel
{
};