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
    GameStatus = keepUp; // the game has started and it is keeping up, noone wins
    GameEnd = false; // it is the beginning, not the end :)
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
    for (int i = 0; i < Y; i++) // To delete the Place arrays
            delete[] Places[i];
        delete[] Places;
}

/*!
 * \brief getPlacePtr
 * \return Places
 */
Place ** Game::getPlaces() const
{
    return Places;
}


/*!
 * \brief Game::allocatePlaces, allocate the array Places with size XxY
 */
void Game::allocatePlaces()
{
    qDebug() << "allocate";

    Places = new  Place*[Y];
    for (int i = 0; i < Y; i++) {

           // Declare a memory block
           // of size n
           Places[i] = new Place[X];
       }
}

/*!
 * \brief Game::AIMove
 */
/*void Game::AIMove()
{
    int bestMove[3] ;
    int minMaxEval = turn? INT_MIN : INT_MAX;

    for(int i = 0; i < Y; i++)
    {
        for(int j = 0; j < X; j++)
        {
            if(!Places[i*X+j].getOff())
            {
                Places[i*X+j].setText(turn? "x" : "o");
                Places[i*X+j].setOff(true);
                int eval = miniMax();

                // restor beginning setting
                Places[i*X+j].setText(" ");
                setGameEnd(false);
                Places[i*X+j].setOff(false);

                if(turn)
                {
                   if(eval > minMaxEval)
                   {
                      // bestMove[0] = j*X + 1; // next to right side
                     //  bestMove[1] = i;
                   }
                }else
                {
                    //if(eval < minMaxEval)
                     //   bestMove[0] = j*X + 1; // next to right side
                      //  bestMove[1] = i;
                }
            }

        }
    }
}*/

/*!
 * \brief Game::getTurn
 * \return turn
 */
bool Game::getTurn() const
{
    return turn;
}

/*!
 * \brief Game::setGameEnd
 */
void Game::setGameEnd(bool value)
{
    GameEnd = value;
}

/*int Game::evaluateBoard()
{
    // evaluate  horizontal wil condition
    for(int i = 0; i < X; i++)
    {
        if(Places[0+i*X] + Places[0+i*X]+ Places[0+i*X])
    }
}*/

/*!
 * \brief Game::miniMax
 */
/*void Game::miniMax()
{

}*/
