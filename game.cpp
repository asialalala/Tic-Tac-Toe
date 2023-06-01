#include "Game.h"
#include <QDebug>

/*!
 * \brief Game::Game
 */
Game::Game()
{
    X = 0;
    Y = 0;
    Places = nullptr;
}

/*!
 * \brief Game::setX
 * \param x - size of vertical board
 */
void Game::setX(int x)
{
    X = x;
}

/*!
 * \brief Game::setY
 * \param y - size of horizontal board
 */
void Game::setY(int y)
{
    Y=y;
}
/*!
 * \brief Game::getX
 * \return X - size of vertical board
 */
 int Game::getX() const
{
    return X;
}

/*!
 * \brief Game::getY
 * \return Y - size of horizontal board
 */
int Game::getY() const
{
    return Y;
}

/*!
 * \brief Game::~Game
 */
Game::~Game()
{
    delete [] Places;
}

/*!
 * \brief getPlacePtr
 * \return Places
 */
Place * Game::getPlacesPtr() const
{
    return Places;
}


/*!
 * \brief Game::allocatePlaces, allocate the array Places with size XxY
 */
void Game::allocatePlaces()
{
    Places = new Place[(X)*(Y)];
    qDebug() << "allocate";
}


