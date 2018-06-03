#include "Board.hpp"
#include "Game.hpp"
#include "Player.hpp"

#include <cstdio>
#include <iostream>

void Game::Launch(Player *p1, Player *p2)
{
    char input;
    do
    {
        _LaunchMatch(p1, p2);
        printf("Do you want to keep playing?\n");
        std::cin>>input;
    }while(input == 'y' || input == 'Y');

    delete p1;
    delete p2;
}

void Game::_LaunchMatch(Player *p1, Player *p2)
{
    Board b;
    Player* active = p1;
    Player* next = p2;
    Player* temp;

    while(!b.IsFinished())
    {
        uint8 move = active->Update(b);
        b.CheckField(move, active->id);

        temp = active;
        active = next;
        next = temp;
    }

    char winner;

    switch(b.GetWinner())
    {
        case 0:
            printf("Draw!\n");
            return;
        case 1:
            winner = p1->GetChar();
            break;
        case 2:
            winner = p2->GetChar();
    }

    printf("Winner: %c\n", winner);
}
