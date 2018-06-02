#ifndef TTT_GAME_HPP
#define TTT_GAME_HPP

#include "helpers.hpp"

class Player;

class Game
{
public:
    void Launch(Player* TODELETE p1, Player* TODELETE p2);

private:
    void _LaunchMatch(Player* p1, Player* p2);
};

#endif // !TTT_GAME_HPP
