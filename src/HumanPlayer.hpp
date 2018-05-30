#ifndef TTT_HUMAN_PLAYER_HPP
#define TTT_HUMAN_PLAYER_HPP

#include "Player.hpp"

//! @brief Player class acting as an user interface.
//! @author Monich
//! @version 1.0.0
class HumanPlayer : public Player
{
public:
    //! @brief Constructor for user interface.
    //! @param id - identifier of the player.
    explicit HumanPlayer(uint8 id);

    //! @sa Player::Update(const Board &b)
    uint8 Update(const Board &b) override;
};

#endif // !TTT_HUMAN_PLAYER_HPP
