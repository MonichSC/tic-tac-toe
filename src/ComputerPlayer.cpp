#include "Board.hpp"
#include "ComputerPlayer.hpp"

ComputerPlayer::ComputerPlayer(uint8 id) : Player(id)
{}

uint8 ComputerPlayer::Update(const Board &b)
{
#ifdef EXTENDED_CHECKS
    ASSERT(!b.IsFinished(), "ComputerPlayer::Update - game is finished");
#endif

    int8 bestScore = -100;
    ActionList actions, bestActions;
    b.GetOpenFields(actions);
    bestActions.reserve(actions.size());
    Board testBoard(b);
    uint8 reverseId = _ReverseId(id);

    for (uint8 i = 0; i < actions.size(); ++i)
    {
        uint8 action = actions[i];
        testBoard.CheckField(action, id);
        int8 score = -_Calculate(testBoard, reverseId);
        testBoard.UncheckField(action);

        if(score > bestScore)
        {
            bestActions.clear();
            bestActions.push_back(action);
            bestScore = score;
        }
        else if(score == bestScore)
            bestActions.push_back(action);
    }

    uint8 bestAction;

    if(bestActions.size() == 1)
        bestAction = bestActions[0];
    else bestAction = bestActions[GenerateRandom() % bestActions.size()];

    return bestAction;
}

int8 ComputerPlayer::_Calculate(Board &b, uint8 player)
{
    if(b.IsFinished())
    {
        // The move done last time ended the game. If game has any winner, it must be the enemy, because he did the last move.
        if(b.GetWinner())
            return -1;
        else return 0;
    }

    ActionList actions;
    b.GetOpenFields(actions);
    uint8 reverseId = _ReverseId(player);
    int8 bestScore = -100;

    for (uint8 i = 0; i < actions.size(); ++i)
    {
        uint8 action = actions[i];
        b.CheckField(action, player);
        int8 score = -_Calculate(b, reverseId);
        b.UncheckField(action);
        if(score > bestScore)
            bestScore = score;
    }

    return bestScore;
}

uint8 ComputerPlayer::_ReverseId(uint8 id)
{
    return (uint8)(id == 1 ? 2 : 1);
}
