#include "Game.h"
#include <QDebug>

/*!
 * \brief Game::Game
 */
Game::Game()
{
    SIZE = 0;
    WIN = 0;
    Places = nullptr;
    GameEnd = false; // it is the beginning, not the end :)
    turn = true;
}

/*!
 * \brief Game::setSIZE
 * \param x - size of vertical board
 */
void Game::setSIZE(int size)
{
    SIZE = size;
}

/*!
 * \brief Game::setWIN
 * \param y - size of horizontal board
 */
void Game::setWIN(int win)
{
    WIN = win;
}
/*!
 * \brief Game::getSIZE
 * \return SIZE - size of board
 */
 int Game::getSIZE() const
{
    return SIZE;
}

/*!
 * \brief Game::getWIN
 * \return WIN- snumber of places to win
 */
int Game::getWIN() const
{
    return WIN;
}

/*!
 * \brief Game::~Game
 */
Game::~Game()
{
    for (int i = 0; i < SIZE; i++) // To delete the Place arrays
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

    Places = new  Place*[SIZE];
    for (int i = 0; i < SIZE; i++) {

           // Declare a memory block
           // of size n
           Places[i] = new Place[SIZE];
       }
}


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

bool Game::getGameEnd()
{
    return GameEnd;
}

/*!
 * \brief Game::whoWin
 * \return
 */
Winner Game::whoWins()
{
    // verify vertical wil condition X
    for(int j = 0; j < SIZE; j++)
    {
        for(int i = 0; i < SIZE; i++)
        {
            if(Places[i][j].getState() != x)
                break;
            if(i == SIZE-1) // end of board X won
            {
                GameEnd = true;
            //    qDebug() << "X wygrało wertykalnie.\n";
                return xwins;
            }
        }
    }

    // verify vertical wil condition O
    for(int j = 0; j < SIZE; j++)
    {
        for(int i = 0; i < SIZE; i++)
        {
            if(Places[i][j].getState() != o)
                break;
            if(i == SIZE-1) // end of board O won
            {
                GameEnd = true;
              //  qDebug() << "O wygrało wertykalnie.\n";
                return owins;
            }
        }
    }

    // verify hirizontal wil condition X
    for(int j = 0; j < SIZE; j++)
    {
        for(int i = 0; i < SIZE; i++)
        {
            if(Places[j][i].getState() != x)
                break;
            if(i == SIZE-1) // end of board X won
            {
                GameEnd = true;
                // qDebug() << "X wygrało horyzontalnie.\n";
                return xwins;
            }
        }
    }

    // verify hirizontal wil condition O
    for(int j = 0; j < SIZE; j++)
    {
        for(int i = 0; i < SIZE; i++)
        {
            if(Places[j][i].getState() != o)
                break;
            if(i == SIZE-1) // end of board O won
            {
                GameEnd = true;
                // qDebug() << "O wygrało horyzontalnie.\n";
                return owins;
            }
        }
    }


    // verify diagonary wil condition "\" X
    for(int i = 0; i < SIZE; i++)
    {
        if(Places[i][i].getState() != x)
            break;
        if(i == SIZE-1) // end of board X won
        {
            GameEnd = true;
             // qDebug() << "X wygrało diagonalnie \\.\n";
            return xwins;
        }
    }

    // verify diagonary wil condition "\" O
    for(int i = 0; i < SIZE; i++)
    {
        if(Places[i][i].getState() != o)
            break;
        if(i == SIZE-1) // end of board O won
        {
            GameEnd = true;
//            qDebug() << "O wygrało diagonalnie \\.\n";
            return owins;
        }
    }

    // verify diagonary wil condition "/" X
    for(int i = 0; i < SIZE; i++)
    {
            if(Places[i][SIZE-i-1].getState() != x)
                break;
            if(i == SIZE-1) // end of board X won
            {
                GameEnd = true;
//                qDebug() << "X wygrało diagonalnie /.\n";
                return xwins;
            }

    }

    // verify diagonary wil condition "/"
    for(int i = 0; i < SIZE; i++)
    {
            if(Places[i][SIZE-i-1].getState() != o)
                break;
            if(i == SIZE-1) // end of board O won
            {
                GameEnd = true;
//                qDebug() << "O wygrało diagonalnie /.\n";
                return owins;
            }
    }

    // check if there is empty position
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
           if(Places[j][i].getState() == Blank)
           {
//               qDebug() << "Jeszcze rozgrywka się nie skończyła.";
               return nobody;
           }
        }
    }

    GameEnd = true;
    return draw;  // noone won, it is draw
}

/*!
 * \brief Game::miniMax
 */
int Game::miniMax(int depth, int alpha, int beta, bool turn)
{
    Winner current = whoWins();
    setGameEnd(false);

    if(current == xwins)
    {
      return GREAT_NUMBER * (depth + 1); // it prioritizes faster win
    }

    else if(current == owins)
    {
      return SMALL_NUMBER * (depth + 1); // it prioritizes faster win
    }

    else if(current == draw)
    {
      return ZERO;
    }

    else if(current == nobody && depth == 0)
    {
        return ZERO;
    }

    if(turn) // if maximizer
    {
        int maxValue = INT_MIN;
        for(int i = 0;  i < SIZE; i++)
        {
            for(int j = 0; j < SIZE; j++)
            {
                if(Places[i][j].getState() == Blank)
                {
                    Places[i][j].setState(x);
                    int value = miniMax(depth - 1, alpha, beta, !turn);
                    maxValue = std::max(maxValue, value);
                    alpha = std::max(alpha, value);
                    Places[i][j].setState(Blank);
                    if(beta <= alpha)
                        break;
                }
                if(beta <= alpha)
                    break;
            }
        }
     return maxValue;
    }else // when minimizer
    {
        int minValue = INT_MAX;
        for(int i = 0;  i < SIZE; i++)
        {
            for(int j = 0; j < SIZE; j++)
            {
                if(Places[i][j].getState() == Blank)
                {
                    Places[i][j].setState(o);
                    int value = miniMax(depth - 1, alpha, beta, !turn);
                    minValue = std::min(minValue, value);
                    beta = std::min(beta, value);
                    Places[i][j].setState(Blank);
                    if(beta <= alpha)
                        break;
                }
                if(beta <= alpha)
                    break;
            }
        }
        return minValue;
    }

}

/*!
 * \brief Game::AIMove
 */
void Game::AIMove()
{
    int bestMove[2] = {0,0} ;
    int minMaxEval = turn? INT_MIN : INT_MAX;

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(Places[i][j].getState() == Blank)
            {
                Places[i][j].setState(turn? x : o );
                int eval = miniMax(SEARCH_DEPH, INT_MIN, INT_MAX, false);
                // restor beginning setting
                setGameEnd(false);
                Places[i][j].setState(Blank);

                // get the maximum evaluation if current turn is X
                if(turn)
                {
                   if(eval > minMaxEval)
                   {
                       bestMove[0] = i;
                       bestMove[1] = j;
                       minMaxEval = eval;
                   }
                }
            }
        }
    }
    Places[bestMove[0]][bestMove[1]].setState(x);
    Places[bestMove[0]][bestMove[1]].setText("x");
    Places[bestMove[0]][bestMove[1]].setEnabled(false);

}

/*!
 * \brief Game::reset reset the pools of board
 */
void Game::reset()
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            Places[i][j].setState(Blank);
            Places[i][j].setEnabled(true);
            Places[i][j].setText(" ");
        }
    }
    GameEnd = false;
}
