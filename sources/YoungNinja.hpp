#pragma once
#include "Ninja.hpp"
constexpr int yng_NinjaHp = 100;
constexpr int yng_NinjaVel = 14;
class YoungNinja : public Ninja
{
public:
    YoungNinja(const std::string &_name, Point _startingLocation) : Ninja(_name, yng_NinjaHp, _startingLocation, yng_NinjaVel){};
};
