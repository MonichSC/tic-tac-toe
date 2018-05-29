#include "Board.hpp"

#define BOARD_SIZE 9

//! @version 1.0.0
Board::Board()
{
    Clear();
}

//! @version 1.0.0
Board::Board(const Board &b)
{
    for (uint8 i = 0; i < BOARD_SIZE; ++i)
        fields[i] = b.fields[i];
    winner = b.winner;
}

//! @version 1.0.0
uint8 Board::GetField(uint8 index) const
{
#ifdef EXTENDED_CHECKS
    ASSERT(index < BOARD_SIZE, "Board::GetField - invalid index");
#endif

    return fields[index];
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
    ASSERT(fields[index], "Board::CheckField - field already checked");
#endif

    fields[index] = player;
    fieldsChecked++;
    _CheckWinner(index);
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
