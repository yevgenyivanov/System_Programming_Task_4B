#include "Character.hpp"
#include <string>
#include <iostream>
#include <cmath>
using namespace ariel;
// constructor
Character::Character(const std::string &name, int hitpoints, Point location) : _name(name), _hitPoints(hitpoints), _currLocation(location) {}
//
//
// funcs
bool Character::isAlive() { return (this->_hitPoints > 0); }

double Character::distance(Character *_other)
{
    double delta_x = this->_currLocation.get_x() - _other->_currLocation.get_x();
    double delta_y = this->_currLocation.get_y() - _other->_currLocation.get_y();
    double dist = (delta_x * delta_x) + (delta_y * delta_y);
    return std::sqrt(dist);
}

void Character::hit(int _damage)
{
    if(_damage<0){
        throw std::invalid_argument("damage cannot be negative");
    }
    if (this->_hitPoints > 0)
    {
        this->_hitPoints = this->_hitPoints - _damage;
    }
    
}
// getters
std::string Character::getName() { return this->_name; }
Point Character::getLocation() { return this->_currLocation; }

std::string Character::print()
{
    if (this->_hitPoints <= 0)
    {
        std::string _params = "";
        _params += "Name: (" + this->getName() + ")";
        _params += " | Location: " + this->_currLocation.print();
        return _params;
    }
    std::string _params = "";
    _params += "Name: " + this->getName();
    _params += " | Location: " + this->_currLocation.print();
    _params += " | Hit Points: " + std::to_string(this->get_hp());
    return _params;
}
//
void Character::attack(Character *_target)
{
    // pass
}
int Character::get_hp()
{
    return this->_hitPoints;
}
void Character::setTeam()
{
    this->_inTeam = true;
}
bool Character::isInTeam()
{
    return this->_inTeam;
}
void Character::setLocation(Point _newLocation)
{
    this->_currLocation = _newLocation;
}