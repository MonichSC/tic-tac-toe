#include "Board.hpp"

#include <cstdio>

#define BOARD_SIZE 9

//! @version 1.0.0
Board::Board()
{
    Clear();
}

//! @version 1.0.1
Board::Board(const Board &b)
{
    for (uint8 i = 0; i < BOARD_SIZE; ++i)
        fields[i] = b.fields[i];
    winner = b.winner;
    fieldsChecked = b.fieldsChecked;
}

//! @version 1.0.0
uint8 Board::GetField(uint8 index) const
{
#ifdef EXTENDED_CHECKS
    ASSERT(index < BOARD_SIZE, "Board::GetField - invalid index");
#endif

    return fields[index];
}

// @version 1.0.0
char Board::GetFieldChar(uint8 index) const
{
#ifdef EXTENDED_CHECKS
    ASSERT(index < BOARD_SIZE, "Board::GetField - invalid index");
#endif

    switch (fields[index])
    {
        case 0:
            return ' ';
        case 1:
            return 'X';
        case 2:
            return 'O';
    }
}

//! @version 1.0.0
void Board::GetOpenFields(ActionList &openFields) const
{
#ifdef EXTENDED_CHECKS
    ASSERT(openFields.empty(), "Board::GetOpenFields - not empty");
    ASSERT(BOARD_SIZE >= fieldsChecked, "Board::GetOpenFields - fieldChecked too big");
#endif

    openFields.reserve(static_cast<uint64>(BOARD_SIZE - fieldsChecked));
    for (uint8 i = 0; i < BOARD_SIZE; ++i)
        if(!fields[i])
            openFields.push_back(i);
}

//! @version 1.0.0
uint8 Board::GetWinner() const
{
    return winner;
}

//! @version 1.0.0
bool Board::IsFinished() const
{
    return winner || fieldsChecked == 9;
}

//! @version 1.0.0
void Board::CheckField(uint8 index, uint8 player)
{
#ifdef EXTENDED_CHECKS
    ASSERT(index < BOARD_SIZE, "Board::CheckField - invalid index");
    ASSERT(!fields[index], "Board::CheckField - field already checked");
#endif

    fields[index] = player;
    fieldsChecked++;
    _CheckWinner(index);
}

//! @version 1.0.0
void Board::UncheckField(uint8 index)
{
#ifdef EXTENDED_CHECKS
    ASSERT(index < BOARD_SIZE, "Board::UncheckField - invalid index");
    ASSERT(fields[index], "Board::UncheckField - field not checked");
#endif

    fields[index] = 0;
    fieldsChecked--;
    winner = 0;
}

//! @version 1.0.0
void Board::Clear()
{
    for (uint8 i = 0; i < BOARD_SIZE; ++i)
        fields[i] = 0;
    winner = 0;
    fieldsChecked = 0;
}

//! @version 1.0.0
void Board::Print() const
{
    printf("-------------------\n");
    for (uint8 i = 0; i < 3; ++i)
    {
        printf("|  ");
        for (uint8 j = 0; j < 3; ++j)
            printf("%c  |  ", GetFieldChar(i*3+j));
        printf("\n-------------------\n");
    }
}

//! @version 1.0.0
void Board::_CheckWinner(uint8 index)
{
#ifdef EXTENDED_CHECKS
    ASSERT(index < BOARD_SIZE, "Board::_CheckWinner - invalid index");
    ASSERT(fields[index], "Board::_CheckWinner - field wasn't checked");
#endif

    if(fieldsChecked >= 5) // Winner can be announced only after 5th round.
    {
        _CheckHorizontal(index);
        _CheckVertical(index);
        _CheckDiagonal(index);
    }
}

//! @version 1.0.0
void Board::_CheckHorizontal(uint8 index)
{
#ifdef EXTENDED_CHECKS
    ASSERT(index < BOARD_SIZE, "Board::_CheckWinner - invalid index");
    ASSERT(fields[index], "Board::_CheckWinner - field wasn't checked");
#endif
    uint8 row = index / ((uint8)3);
    uint8 check = 1;

    for (int i = 0; i < 3; ++i)
        check *= fields[row * 3 + i];

    _GetWinnerByCheckResult(check);
}

//! @version 1.0.0
void Board::_CheckVertical(uint8 index)
{
#ifdef EXTENDED_CHECKS
    ASSERT(index < BOARD_SIZE, "Board::_CheckWinner - invalid index");
    ASSERT(fields[index], "Board::_CheckWinner - field wasn't checked");
#endif
    uint8 col = index % ((uint8)3);
    uint8 check = 1;

    for (int i = 0; i < 3; ++i)
        check *= fields[col + 3 * i];

    _GetWinnerByCheckResult(check);
}

//! @version 1.0.0
void Board::_CheckDiagonal(uint8 index)
{
#ifdef EXTENDED_CHECKS
    ASSERT(index < BOARD_SIZE, "Board::_CheckWinner - invalid index");
    ASSERT(fields[index], "Board::_CheckWinner - field wasn't checked");
#endif

    if(index % 2 == 0) // Only field with even index can be on diagonal.
    {
        if(index % 4 == 0)
        {
            uint8 check = 1;
            for (int i = 0; i < 3; ++i)
                check *= fields[i * 4];
            _GetWinnerByCheckResult(check);
        }
        if(index != 0 && index != 8)
        {
            uint8 check = 1;
            for (int i = 0; i < 3; ++i)
                check *= fields[i * 2 + 2];
            _GetWinnerByCheckResult(check);
        }
    }
}

//! @version 1.0.0
void Board::_GetWinnerByCheckResult(uint8 check)
{
    if(check == 1)
        winner = 1;
    else if (check == 8)
        winner = 2;
}
