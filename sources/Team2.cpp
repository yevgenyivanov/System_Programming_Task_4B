#include <stdexcept>
#include <iostream>
#include "Team2.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "Team.hpp"
// #include "SmartTeam.hpp"
using namespace ariel;
constexpr int _zero = 0;
Team2::Team2(Character *_teamLeader) : Team::Team(_teamLeader){};

void Team2::attack(Team *_enemyTeam)
{
    if (_enemyTeam == nullptr || this == _enemyTeam)
        throw std::invalid_argument("Cannot attack null/self");
    if (this->stillAlive() == _zero)
        throw std::runtime_error("Cannot attack/be attacked by a dead team");
    if (_enemyTeam->stillAlive() == _zero)
        throw std::runtime_error("Cannot attack/be attacked by a dead team");
    this->findCurrentLeader();
    _enemyTeam->findCurrentLeader();
    int _victim = this->findVictim(_enemyTeam);
    for (int i = 0; i < this->_teamMembers.size(); i++)
    {
        if (this->_teamMembers[(unsigned long)i]->isAlive())
        {
            if (_enemyTeam->_teamMembers[(unsigned long)_victim]->isAlive())
            {
                this->_teamMembers[(unsigned long)i]->attack(_enemyTeam->_teamMembers[(unsigned long)_victim]);
                // std::cout<< _teamMembers[(unsigned long)i]->print() << " attacked." << std::endl;
            }
            else
            {
                _victim = this->findVictim(_enemyTeam);
            }
        }
    }
}

// Team2::~Team2()
// {
//     int _teamSize=this->_teamMembers.size();
//     std::cout<< "Team2 size: " << _teamSize << std::endl;
//     for(int i=_teamSize-1; i>= _zero; i--){
//         delete _teamMembers[(unsigned long)i];

//     }
//     delete this;
// }