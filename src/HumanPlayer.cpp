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
    int base;

    do
    {
        printf("Index of the field to check: ");
        std::cin>>action;
        switch (action%3)
        {
            case 0:
                base = 11;
                break;
            case 1:
                base = 7;
                break;
            case 2:
                base = 9;
        }
        action = base - action;
    }while(action >= 9 || action < 0 || b.GetField(action));

    return static_cast<uint8>(action);
}
