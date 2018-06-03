#ifndef TTT_PLAYER_HPP
#define TTT_PLAYER_HPP

#include "helpers.hpp"

class Board;

//! @brief Abstract class for game's player, human or AI alike.
//! @author Monich
//! @version 1.1.0
class Player
{
public:
    //! @brief Constructor of the player
    //! @param id - identifier of the player
    //! @version 1.0.0
    explicit Player(uint8 id) : id(id){
#ifdef EXTENDED_CHECKS
        ASSERT(id == 1 || id == 2, "Player() - bad id");
#endif // EXTENDED_CHECKS
    };

    //! @brief Virtual destructor for Player.
    virtual ~Player() = default;

    //! @brief Gets the next move from the Player.
    //! @returns id of the next move.
    //! @param b - actual state of the board.
    virtual uint8 Update(const Board& b) = 0;

    //! @brief Identifier of the player.
    const uint8 id;

    //! @brief Gets the character representing this Player.
    char GetChar() const
    {
        return id == 1 ? 'X' : 'O';
    }
};

#endif // !TTT_BOARD_HPP
