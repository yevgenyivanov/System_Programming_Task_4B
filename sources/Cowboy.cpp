#include "Cowboy.hpp"
#include "Character.hpp"
#include <string>
#include <stdexcept>
constexpr int cowboy_Hp = 110;
constexpr int ammunition = 6;
constexpr int damage = 10;
Cowboy::Cowboy(std::string _name, Point _startingLocation) : Character::Character(_name, cowboy_Hp, _startingLocation), _ammo(ammunition) {}

void Cowboy::shoot(Character *_target)
{
    // cowboy is alive
    if (this->isAlive() && _target->isAlive() && this != _target)
    {
        // has at least one bullet loaded
        if (this->hasboolets())
        {
            this->_ammo--;
            _target->hit(damage);
        }
    }
    else
    {
        throw std::runtime_error("Character / Target is already dead.");
    }
}
bool Cowboy::hasboolets()
{
    return (this->_ammo > 0);
}
void Cowboy::reload()
{
    if (!this->isAlive())
    {
        throw std::runtime_error("Dead cowboy cannot reload");
    }
    this->_ammo = ammunition;
}
void Cowboy::attack(Character *_target)
{
    if (!this->isAlive() || !_target->isAlive() || this == _target || _target == nullptr)
    {
        throw std::runtime_error("cannot attack: attacker|target OR target is self|null");
    }
    if (this->hasboolets())
    {
        shoot(_target);
        return;
    }
    this->reload();
}
std::string Cowboy::print()
{
    return "(C) " + this->Character::print();
}