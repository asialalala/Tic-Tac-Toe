#ifndef GAME_H
#define GAME_H
#include "Place.h"
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
    Place * Places;
public:
    Game();
    void setX(int x);
    void setY(int y);
    int getX() const;
    int getY() const;
    ~Game();
    Place * getPlacesPtr() const;
    void setPlacesPtr(int n,  Place * ptr);
    void allocatePlaces();
};

#endif // GAME_H
