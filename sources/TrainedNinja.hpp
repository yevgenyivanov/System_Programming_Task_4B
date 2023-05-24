#pragma once
#include "Ninja.hpp"
constexpr int tr_NinjaHp = 120;
constexpr int tr_NinjaVel = 12;
class TrainedNinja : public Ninja
{
public:
    TrainedNinja(const std::string &_name, Point _startingLocation) : Ninja(_name, tr_NinjaHp, _startingLocation, tr_NinjaVel){};
};
