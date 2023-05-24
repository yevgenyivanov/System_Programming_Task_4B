#pragma once
#include "Character.hpp"
#include "Team.hpp"

class Team2 : public Team
{
public:
  Team2(Character *);
  void attack(Team *_enemyTeam) override;
};

namespace ariel
{
};