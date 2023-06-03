#ifndef AIPLAYER_H
#define AIPLAYER_H
#include "Place.h"
#include "Game.h"

// IT IS NOT USED

/*!
 * \file
 * \brief The AIPlayer class
 *
 * The file includes definition of class AIPlayer which uses minmiax algorythm
 */
class AIPlayer // czy potrzebana jest ta klasa?
{
public:
    AIPlayer();
    int bestMove(Game * game);
    int miniMax(Game * game);
    int evaluateBoard();
};

#endif // AIPLAYER_H
