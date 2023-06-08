#include <stdexcept>
#include <limits>
#include <iostream>
#include <typeinfo>
#include "Team2.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "Team.hpp"
#include "SmartTeam.hpp"
using namespace ariel;
constexpr int _zero = 0;
constexpr int _ninjaSlashRange = 1;
constexpr int _cowboyDamage = 10;
constexpr int _invalidCowboyTarget = -1;
// use base class constructor
SmartTeam::SmartTeam(Character *_teamLeader) : Team::Team(_teamLeader){};
void SmartTeam::attack(Team *_enemyTeam)
{
    // check for errors in code usage
    if (_enemyTeam == nullptr || this == _enemyTeam)
        throw std::invalid_argument("Cannot attack null/self");
    if (this->stillAlive() == _zero)
        throw std::runtime_error("Cannot attack/be attacked by a dead team");
    if (_enemyTeam->stillAlive() == _zero)
        throw std::runtime_error("Cannot attack/be attacked by a dead team");
    // else find the current leader
    this->findCurrentLeader();
    // find victim closest to this->_teamLeader
    int _victim = this->findVictim(_enemyTeam);
    // boolean for saving current ninja attack status
    bool _ninjaAttacked = false;
    // ninjas attack first
    for (unsigned long i = _zero; i < this->_teamMembers.size(); i++)
    {
        if (!_enemyTeam->_teamMembers[(unsigned long)_victim]->isAlive())
        {
            _victim = this->findVictim(_enemyTeam);
        }
        if (dynamic_cast<Ninja *>(this->_teamMembers[i]))
        {

            if (this->_teamMembers[i]->isAlive())
            {
                // iterate over enemy team and find if anyone is within slash range
                for (unsigned long j = 0; j < _enemyTeam->_teamMembers.size(); j++)
                {
                    // target is alive and can be slashed.
                    if (_enemyTeam->_teamMembers[j]->isAlive())
                        if (this->_teamMembers[i]->distance(_enemyTeam->_teamMembers[j]) <= _ninjaSlashRange)
                        {
                            this->_teamMembers[i]->attack(_enemyTeam->_teamMembers[j]);
                            _ninjaAttacked = true; // prevent same ninja attacking twice
                            break;                 // same team member cannot attack twice in a row.
                        }
                }
                // iterated over entire enemy team and no enemy within slash distance found
                if (!_ninjaAttacked)
                {
                    this->_teamMembers[i]->attack(_enemyTeam->_teamMembers[(unsigned long)_victim]);
                }
            }
        }
    }

    // cowboys attack second
    // iterate over all cowboys and find total amount
    int _totalCowboys = _zero;
    for (unsigned long i = _zero; i < this->_teamMembers.size(); i++)
    {
        if (dynamic_cast<Cowboy *>(this->_teamMembers[i]))
        {
            if (this->_teamMembers[i]->isAlive())
            {
                _totalCowboys += 1;
            }
        }
    }
    // iterate over enemy team find enemy with hp <=_totalCowboys * _cowboysDamage
    // if true - attack
    int _cowboyTarget = _invalidCowboyTarget;
    // re-purpose _cowboyAmount to total possible cowboy damage
    _totalCowboys = _totalCowboys * _cowboyDamage;
    for (unsigned long i = _zero; i < _enemyTeam->_teamMembers.size(); i++)
    {
        if (_enemyTeam->_teamMembers[i]->isAlive() && _enemyTeam->_teamMembers[i]->get_hp() <= _totalCowboys)
        {
            _cowboyTarget = (int)i;
        }
    }
    // final iteration - if _cowboyTarget != -1 attack it with all cowobys. Else - attack victim closest to team leader
    for (unsigned long i = _zero; i < this->_teamMembers.size(); i++)
    {
        if (!_enemyTeam->_teamMembers[(unsigned long)_victim]->isAlive())
        {
            _victim = this->findVictim(_enemyTeam);
        }
        if (dynamic_cast<Cowboy *>(this->_teamMembers[i]))
        {
            if (this->_teamMembers[i]->isAlive())
            {
                // target with less hp
                if (_cowboyTarget != _invalidCowboyTarget)
                {
                    this->_teamMembers[i]->attack(_enemyTeam->_teamMembers[(unsigned long)_cowboyTarget]);
                    continue;
                }
                else
                {
                    this->_teamMembers[i]->attack(_enemyTeam->_teamMembers[(unsigned long)_victim]);
                }
            }
        }
    }
}