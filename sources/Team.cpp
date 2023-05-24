#include <stdexcept>
#include <limits>
#include <iostream>
#include <typeinfo>
#include "Team.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

constexpr int initialLeaderPos = 0;
constexpr int _one = 1;
constexpr int maxTeamSize = 10;
using namespace ariel;
Team::Team(Character *_teamLeader)
{
    if (!_teamMembers.empty() || _teamLeader->isInTeam())
        throw std::runtime_error("Team leader is already assigned");
    if (_teamLeader == nullptr)
    {
        throw std::runtime_error("Leader poitner is null");
    }
    this->_teamMembers.emplace_back(_teamLeader);
    _teamLeader->setTeam();
    _currentLeader = initialLeaderPos;
}

// Team::~Team()
// {
//     int _teamSize = this->_teamMembers.size();
//         for (int i = initialLeaderPos; i < _teamSize; i++)
//         {
//             std::cout<< "deleting: " << _teamMembers[(unsigned long)i]->print()<< std::endl;
//             delete _teamMembers[(unsigned long)i];
//         }
//         // _teamMembers.clear();
//     // std::vector<Character *>().swap(_teamMembers);
//     // _teamMembers.empty();
//     // delete this;
// }
// Team::~Team()
// {
//     for (Character *member : _teamMembers)
//     {
//         delete member;
//     }
// }



void Team::add(Character *_char)
{
    if (_char->isInTeam())
    {
        throw std::runtime_error("Character is already part of a team.");
    }
    if (this->_teamMembers.size() < maxTeamSize)
    {
        this->_teamMembers.emplace_back(_char);
        _char->setTeam();
        return;
    }
    throw std::runtime_error("Team limit exceeded");
}

void Team::attack(Team *_enemyTeam)
{
    if (_enemyTeam == nullptr || this == _enemyTeam)
    {
        throw std::invalid_argument("Cannot attack null/self");
    }
    if (this->stillAlive() == initialLeaderPos)
    {
        throw std::runtime_error("Dead team cannot attack");
    }
    if (_enemyTeam->stillAlive() == initialLeaderPos)
    {
        throw std::runtime_error("Cannot attack dead team.");
    }
    // find if leader is alive
    // findCurrentLeader();
    _enemyTeam->findCurrentLeader();
    // find target closes to this->leader
    int _victim = this->findVictim(_enemyTeam);
    //
    // Cowboys attack first
    for (int i = 0; i < this->_teamMembers.size(); i++)
    {
        if (!_enemyTeam->_teamMembers[(unsigned long)_victim]->isAlive())
        {
            _victim = this->findVictim(_enemyTeam);
        }
        if (this->_teamMembers[(unsigned long)i]->isAlive())
            if (dynamic_cast<Cowboy *>(this->_teamMembers[(unsigned long)i]))
                this->_teamMembers[(unsigned long)i]->attack(_enemyTeam->_teamMembers[(unsigned long)_victim]);
    }
    // Ninjas attack after all cowboys
    for (int i = 0; i < this->_teamMembers.size(); i++)
    {
        if (!_enemyTeam->_teamMembers[(unsigned long)_victim]->isAlive())
        {
            _victim = this->findVictim(_enemyTeam);
        }
        if (this->_teamMembers[(unsigned long)i]->isAlive() && _enemyTeam->_teamMembers[(unsigned long)_victim]->isAlive())
            if (dynamic_cast<Ninja *>(this->_teamMembers[(unsigned long)i]))
                this->_teamMembers[(unsigned long)i]->attack(_enemyTeam->_teamMembers[(unsigned long)_victim]);
    }
}
int Team::stillAlive()
{
    int still_alive = 0;
    for (int i = 0; i < _teamMembers.size(); i++)
    {
        if (_teamMembers[(unsigned long)i]->isAlive())
            still_alive++;
    }
    return still_alive;
}
void Team::print()
{
    for (int i = 0; i < _teamMembers.size(); i++)
    {
        std::cout << _teamMembers[(unsigned long)i]->print() << std::endl;
    }
}

void Team::findCurrentLeader()
{
    // if leader is alive no need to find a new one
    if (_teamMembers[(unsigned long)_currentLeader]->isAlive())
    {
        return;
    }
    int _tmpLeader;
    double _minDist = std::numeric_limits<double>::max();
    for (int i = 0; i < _teamMembers.size(); i++)
    {
        if (_teamMembers[(unsigned long)i]->isAlive())
        {
            if (_teamMembers[(unsigned long)i]->distance(_teamMembers[(unsigned long)_currentLeader]) < _minDist)
            {
                // reduce distance
                _minDist = _teamMembers[(unsigned long)i]->distance(_teamMembers[(unsigned long)_currentLeader]);
                // save for vector location for future use
                _tmpLeader = i;
            }
        }
    }
    this->_currentLeader = _tmpLeader;
}

int Team::findVictim(Team *_enemyTeam)
{
    double _minDist = std::numeric_limits<double>::max();
    int _victim = 0;
    for (int i = 0; i < _enemyTeam->_teamMembers.size(); i++)
    {
        if (_enemyTeam->_teamMembers[(unsigned long)i]->isAlive() && this->_teamMembers[(unsigned long)this->_currentLeader]->distance(_enemyTeam->_teamMembers[(unsigned long)i]) < _minDist)
        {
            // reduce distance and save tmp location
            _minDist = this->_teamMembers[(unsigned long)this->_currentLeader]->distance(_enemyTeam->_teamMembers[(unsigned long)i]);
            _victim = i;
        }
    }
    return _victim;
}