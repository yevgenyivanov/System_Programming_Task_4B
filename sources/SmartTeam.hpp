#pragma once
#include <vector>
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "Team.hpp"
#include "Team2.hpp"

class SmartTeam
{
private:
    std::vector<Character *> _teamMembers = {};

// public:
//     // constructor
//     SmartTeam(Character *);
//     // copy constructor
//     SmartTeam(SmartTeam &);
//     // copy assignment operator
//     SmartTeam &operator=(const SmartTeam &) noexcept;
//     // move constructor
//     SmartTeam(SmartTeam &&) noexcept;
//     // move assignment operator
//     SmartTeam &operator=(SmartTeam &&) noexcept;
//     // destructor
//     ~SmartTeam();
//     //
//     void add(Character *);
//     // void attack(Team *);
//     // void attack(Team2 *);
//     void attack(SmartTeam *);
//     int stillAlive();
//     void print();
};

namespace ariel
{
};