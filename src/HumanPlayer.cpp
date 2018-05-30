#include "Board.hpp
#include "HumanPlayer.hpp""

#include <cstdio>

//! @version 1.0.0
HumanPlayer::HumanPlayer(uint8 id) : Player(id)
{}

//! @version 1.0.0
uint8 HumanPlayer::Update(const Board &b)
{
    printf("Current player: %c\n", GetChar());
    printf("Board status: \n");

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
            printf("%c\n", b.GetFieldChar(i*3+j));
        printf("\n");
    }

    return 0;
}
