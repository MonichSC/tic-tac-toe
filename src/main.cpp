#include "ComputerPlayer.hpp"
#include "Game.hpp"
#include "HumanPlayer.hpp"

int main()
{
    Game g;
    g.Launch(new HumanPlayer(1), new ComputerPlayer(2));
    return 0;
}
