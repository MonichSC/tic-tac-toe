#ifndef TTT_PLAYER_HPP
#define TTT_PLAYER_HPP

#include "helpers.hpp"

class Board;

//! @brief Abstract class for game's player, human or AI alike.
//! @author Monich
//! @version 1.0.0
class Player
{
public:
    //! @brief Virtual destructor for Player.
    virtual ~Player() = default;

    //! @brief Gets the next move from the Player.
    //! @returns id of the next move.
    //! @param b - actual state of the board.
    virtual uint8 Update(const Board& b) = 0;
};

#endif // !TTT_BOARD_HPP
