// #include <stdexcept>
// #include "SmartTeam.hpp"
// #include "Cowboy.hpp"
// #include "Ninja.hpp"
// #include "YoungNinja.hpp"
// #include "TrainedNinja.hpp"
// #include "OldNinja.hpp"
// #include "Team.hpp"
// #include "Team2.hpp"
// using namespace ariel;
// SmartTeam::SmartTeam(Character *_teamLeader)
// {
//     if (!_teamMembers.empty())
//         throw std::runtime_error("Team leader already assigned");

//     this->_teamMembers.emplace_back(_teamLeader);
// }

// // copy constructor
// SmartTeam::SmartTeam(SmartTeam &) {}
// // copy assignment operator
// SmartTeam &SmartTeam::operator=(const SmartTeam &_otherSmartTeam) noexcept 
// {
//     this->_teamMembers= _otherSmartTeam._teamMembers;
//     return *this;
// }
// // move constructor
// SmartTeam::SmartTeam(SmartTeam &&_otherSmartTeam) noexcept {}
// // move assignment operator
// SmartTeam &SmartTeam::operator=(SmartTeam &&_otherSmartTeam) noexcept 
// {
//     return _otherSmartTeam=*this;
// }
// // destructor
// SmartTeam::~SmartTeam() {}

// void SmartTeam::add(Character *_char)
// {
// }
// // void SmartTeam::add(Cowboy *){}

// // void SmartTeam::attack(Team *_enemyTeam2) {}
// // void SmartTeam::attack(Team2 *_enemyTeam2) {}
// void SmartTeam::attack(SmartTeam *_enemyTeam2) {}
// int SmartTeam::stillAlive() { return 0; }
// void SmartTeam::print() {}