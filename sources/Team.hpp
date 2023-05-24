#pragma once
#include <vector>
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
class Team
{
public:
    std::vector<Character *> _teamMembers = {};
    int _currentLeader;
    // constructor
    Team(Character *);
    // copy constructor
    Team(Team &) = default;
    // copy assignment operator
    Team &operator=(const Team &) = default;
    // move constructor
    Team(Team &&) = default;
    // move assignment operator
    Team &operator=(Team &&) = default;
    // destructor
    virtual ~Team() = default;
    
    void add(Character *);
    virtual void attack(Team *);
    // void attack(Team2 *);
    // void attack(SmartTeam *);
    int stillAlive();
    void print();
    void findCurrentLeader();
    int findVictim(Team *);
};

namespace ariel
{
};