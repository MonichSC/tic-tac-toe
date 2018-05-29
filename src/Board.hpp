#ifndef TTT_BOARD_HPP
#define TTT_BOARD_HPP

#include "helpers.hpp"

//! @brief Represents board of the game.
//! @author Monich
//! @version 1.0.0
class Board
{
public:
    //! @brief Default constructor of the Board.
    Board();
    //! @brief Copy constructor of the Board.
    explicit Board(const Board& b);

    //! @brief Returns the status of the given field.
    //! @details Field empty is represented by 0. Number 1 or 2 specifies the player that checked this file
    //!     Fields are sorted in this manner:\n
    //!     0   1   2 \n
    //!     3   4   5 \n
    //!     6   7   8 \n
    //! @returns Owner of the field.
    uint8 GetField(uint8 index) const;

    //! @brief Returns a winner of a match.
    //! @returns id of the player that won the game. 0 if there is no winner.
    uint8 GetWinner() const;
    //! @brief Checks if the game is finished.
    //! @details Game is finished if there is a winner or all fields are fulled.
    //! @returns true if game is finished, false otherwise.
    bool IsFinished() const;

    //! @brief Claims the field specified.
    //! @details Fields are sorted in this manner:\n
    //!     0   1   2 \n
    //!     3   4   5 \n
    //!     6   7   8 \n
    //! @pre index is valid and not owned by any player.
    //! @post Field is owned by player.
    void CheckField(uint8 index, uint8 player);

    //! @brief Finishes the match and cleans the board.
    //! @post Board is cleaned.
    void Clear();
private:
    //! @brief Returns the status of the given field.
    //! @details Field empty is represented by 0. Number 1 or 2 specifies the player that checked this file
    //!     Fields are sorted in this manner:\n
    //!     0   1   2 \n
    //!     3   4   5 \n
    //!     6   7   8 \n
    uint8 fields[9];

    //! @brief Holds information about the winner of the match
    //! @details Don't calculate the winner every time GetWinner() is invoked - store it for optimisation.
    uint8 winner;
};

#endif // !TTT_BOARD_HPP
