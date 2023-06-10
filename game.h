#ifndef GAME_H
#define GAME_H
#include "Place.h"
#include "defined.h"
/*!
 * \file
 * \brief The Game class
 *
 * The file includes definition of class Game
 */
class Game
{
private:
    int X;
    int Y;
    Place ** Places; // the places on the board                  a moze tu tworzyć tablicę wskaźników? a nie wskaźnik na tablicę
    bool GameEnd;
    bool turn = true; // true - x, false - o

public:
    Game();
    void setX(int x);
    void setY(int y);
    int getX() const;
    int getY() const;
    ~Game();
    Place ** getPlaces() const;
    void allocatePlaces();
    void AIMove() ;
    bool getTurn() const;
    void setGameEnd(bool value);
    int miniMax(int depth, int alpha, int beta, bool turn);
    Winner whoWins();
};

#endif // GAME_H
