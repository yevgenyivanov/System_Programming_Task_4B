#pragma once
#include "Ninja.hpp"
constexpr int ol_NinjaHp = 150;
constexpr int ol_NinjaVel = 8;
class OldNinja : public Ninja
{
public:
    OldNinja(const std::string &_name, Point _startingLocation) : Ninja(_name, ol_NinjaHp, _startingLocation, ol_NinjaVel){};
};