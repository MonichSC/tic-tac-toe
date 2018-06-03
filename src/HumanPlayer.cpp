#include "Board.hpp"
#include "HumanPlayer.hpp"

#include <cstdio>
#include <iostream>

//! @version 1.0.0
HumanPlayer::HumanPlayer(uint8 id) : Player(id)
{}

//! @version 1.0.0
uint8 HumanPlayer::Update(const Board &b)
{
    printf("Current player: %c\n", GetChar());
    printf("Board status: \n");

    b.Print();

    int action;

    do
    {
        printf("Index of the field to check: ");
        std::cin>>action;
    }while(action >= 9 || action < 0 || b.GetField(action));

    return static_cast<uint8>(action);
}
