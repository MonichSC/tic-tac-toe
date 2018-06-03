#ifndef TTT_BOARD_HPP
#define TTT_BOARD_HPP

#include "helpers.hpp"

#include <vector>

typedef std::vector<uint8> ActionList;

//! @brief Represents board of the game.
//! @author Monich
//! @version 1.2.0
class Board
{
public:
    //! @brief Default constructor of the Board.
    Board();
    //! @brief Copy constructor of the Board.
    //! @param b - Board to copy.
    Board(const Board& b);

    //! @brief Returns the status of the given field.
    //! @details Field empty is represented by 0. Number 1 or 2 specifies the player that checked this file
    //!     Fields are sorted in this manner:\n
    //!     0   1   2 \n
    //!     3   4   5 \n
    //!     6   7   8 \n
    //! @returns Owner of the field.
    //! @param index - index of the field to check.
    uint8 GetField(uint8 index) const;
    //! @brief Returns the character representing given field on the console.
    //! @details Field empty is represented by 0. Number 1 or 2 specifies the player that checked this file
    //!     Fields are sorted in this manner:\n
    //!     0   1   2 \n
    //!     3   4   5 \n
    //!     6   7   8 \n
    //! @returns Character representing the field.
    //! @param index - index of the field to check.
    char GetFieldChar(uint8 index) const;

    //! @brief Returns fields that are open to check.
    //! @pre Parameter openFields must be empty.
    //! @param openFields - vector where the open fields will be stored. Stored values are guaranteed to be sorted.
    void GetOpenFields(ActionList& OUTARG openFields) const;

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
    //! @param index - index of the field to check.
    //! @param player - player that makes a tick.
    void CheckField(uint8 index, uint8 player);
    //! @brief Unclaims the field specified.
    //! @pre index is valid and owned.
    //! @post Field is no longer owned. Use only for AI.
    //! @param index - index of the field to uncheck.
    void UncheckField(uint8 index);

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
    //! @brief Number of the fields already checked.
    uint8 fieldsChecked;

    //! @brief Calculates the winner of the game.
    //! @details Should be called after every check of the field.
    //! @pre Field specified was just checked by the player.
    //! @post Winner is saved if there is any.
    //! @param index - index of the field that was checked.
    void _CheckWinner(uint8 index);

    //! @brief Checks for the winner in horizontal line.
    //! @details Checks horizontal line for the field specified.
    //! @pre Field specified was just checked by the player.
    //! @post Winner is saved if there is any.
    //! @param index - index of the field that was checked.
    void _CheckHorizontal(uint8 index);
    //! @brief Checks for the winner in vertical line.
    //! @details Checks vertical line for the field specified.
    //! @pre Field specified was just checked by the player.
    //! @post Winner is saved if there is any.
    //! @param index - index of the field that was checked.
    void _CheckVertical(uint8 index);
    //! @brief Checks for the winner in diagonal line.
    //! @details Checks diagonal line for the field specified.
    //! @pre Field specified was just checked by the player.
    //! @post Winner is saved if there is any.
    //! @param index - index of the field that was checked.
    void _CheckDiagonal(uint8 index);

    //! @brief Calculates if _Check* result contains a winner.
    //! @details _Check* functions calculate the multiplier of given line. This function resolves if this multiplier has a winner contained.
    //! @post Winner is saved if there is any.
    //! @param check - the multiplier.
    void _GetWinnerByCheckResult(uint8 check);
};

#endif // !TTT_BOARD_HPP
