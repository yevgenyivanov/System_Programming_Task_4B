#pragma once
#include <vector>
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "Team.hpp"

class SmartTeam : public Team
{
private:
    // std::vector<Character *> _teamMembers = {};
public:
    SmartTeam(Character *);
    void attack(Team *_enemyTeam) override;
};

namespace ariel
{
};