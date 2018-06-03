#ifndef TTT_COMPUTER_PLAYER_H
#define TTT_COMPUTER_PLAYER_H

#include "Player.hpp"

class Board;

//! @brief Minmax computer player.
//! @author Monich
//! @version 1.0.0
class ComputerPlayer : public Player
{
public:
    //! @brief Constructor for user interface.
    //! @param id - identifier of the player.
    explicit ComputerPlayer(uint8 id);

    //! @sa Player::Update(const Board &b)
    virtual uint8 Update(const Board &b);

private:
    //! @brief Calculates a subtree of a board.
    //! @details Recurrent function. Counts score for each subtree maximizing it for given player, which changes with every iteration.
    //! @returns maximum score by this tree.
    //! @param b - Board with editing rights.
    //! @param player - identifier of the player for which to maximise this time.
    static int8 _Calculate(Board& b, uint8 player);
    //! @brief Generates other player id.
    static uint8 _ReverseId(uint8 id);
};

#endif // !TTT_COMPUTER_PLAYER_H