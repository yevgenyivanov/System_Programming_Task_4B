#include "Ninja.hpp"
#include "Character.hpp"
#include "Point.hpp"
#include <stdio.h>
#include <string>
#include <stdexcept>
constexpr int damage = 40;
constexpr int slash_dist = 1;
void Ninja::slash(Character *_target)
{
    if (this->isAlive() && _target->isAlive() && this!=_target && _target!=nullptr)
    {
        if (this->getLocation().distance(_target->getLocation()) < slash_dist)
        {
            _target->hit(damage);
        }
    }
    else{
        throw std::runtime_error("Character / Target is already dead.");
    }
}
void Ninja::move(Character *_target)
{
    Point _currPoint = this->getLocation(), _targetPoint = _target->getLocation();
    if(_currPoint.distance(_targetPoint) < this->_velocity){
        this->Character::setLocation(Point::moveTowards(_currPoint, _targetPoint, _currPoint.distance(_targetPoint)));
        return;    
    }
    this->Character::setLocation(Point::moveTowards(_currPoint, _targetPoint, this->_velocity));
}
void Ninja::attack(Character *_target)
{
    if (!this->isAlive() || !_target->isAlive() || this==_target || _target==nullptr){
        throw std::runtime_error("");
    }
    if (this->getLocation().distance(_target->getLocation()) < slash_dist){
        this->slash(_target);
        return;
    }
    this->move(_target);
}
std::string Ninja::print()
{
    return "(N) " + this->Character::print();
}
//
// void *Ninja::operator new(size_t size){
//     void *ptr = malloc(size);
//     return ptr;
// }
// void Ninja::operator delete(void *ptr){
//     free(ptr);
// }