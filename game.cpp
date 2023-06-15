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
    moveNumber = 0;
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
 * \return information about winner following the demanded positions to win
 */
Winner Game::whoWins()
{
    int score = 0;
    // verify vertical wil condition X
    for(int j = 0; j < SIZE; j++)
    {
        score = 0; // end of column
        for(int i = 0; i < SIZE; i++)
        {
            if(Places[i][j].getState() == x)
            {
                score++;

                if(score == WIN) // end of board X won
                {
                    GameEnd = true;
                    qDebug() << "X wygrało wertykalnie.\n";
                    return xwins;
                }
            }else{
                score = 0;
            }
        }
    }

    // verify vertical wil condition O
    for(int j = 0; j < SIZE; j++)
    {
        score = 0; // end of column
        for(int i = 0; i < SIZE; i++)
        {
            if(Places[i][j].getState() == o)
            {
                score++;
                if(score == WIN) // end of board O won
                {
                    GameEnd = true;
                    return owins;
                }
            }else{
                score=0;
            }
        }
    }

    // verify hirizontal wil condition X
    for(int j = 0; j < SIZE; j++)
    {
        score = 0; // end of row
        for(int i = 0; i < SIZE; i++)
        {
            if(Places[j][i].getState() == x)
            {
                score++;
                if(score == WIN) // end of board X won
                {
                    GameEnd = true;
                     qDebug() << "X wygrało horyzontalnie.\n";
                    return xwins;
                }
            }else{
                score=0;
            }
        }
    }

    // verify hirizontal wil condition O
    for(int j = 0; j < SIZE; j++)
    {
        score = 0; // end of row
        for(int i = 0; i < SIZE; i++)
        {
            if(Places[j][i].getState() == o)
            {
                score++;
                if(score == WIN) // end of board O won
                {
                    GameEnd = true;
                     qDebug() << "O wygrało horyzontalnie.\n";
                    return owins;
                }
            }else{
                score = 0; // gap
            }
        }
    }


    // verify diagonary wil condition "\" X
    for(int p = 0; p < SIZE; p++) // upper left triangle
    {
        int j = 0;
        score = 0; // new diagon
        for(int i = p; i < SIZE; i++)
        {
            if(Places[j][i].getState() == x)
            {
                score++;
                if(score == WIN) // end of board X won
                {
                    GameEnd = true;
                     qDebug() << "X wygrało diagonalnie \\.\n";
                    return xwins;
                }
            }else
            {
                score = 0; // gap
            }
            j++;
        }
    }
    for(int p = 1; p < SIZE; p++) // lower right triangle
    {
        int j = 0;
        score = 0; // new diagon
        for(int i = p; i < SIZE; i++)
        {
            if(Places[i][j].getState() == x)
            {
                score++;
                if(score == WIN) // end of board X won
                {
                    GameEnd = true;
                     qDebug() << "X wygrało diagonalnie \\.\n";
                    return xwins;
                }
            }else
            {
                score = 0; // gap
            }
            j++;
        }
    }

    // verify diagonary wil condition "\" O
    for(int p = 0; p < SIZE; p++) // upper left triangle
    {
        int j = 0;
        score = 0; // new diagon
        for(int i = p; i < SIZE; i++)
        {
            if(Places[j][i].getState() == o)
            {
                score++;
                if(score == WIN) // end of board O won
                {
                    GameEnd = true;
                    return owins;
                }
            }else{
                score = 0;// gap
            }
            j++;
        }
    }
    for(int p = 1; p < SIZE; p++) // lower  right triangle
    {
        int j = 0;
        score = 0; // new diagon
        for(int i = p; i < SIZE; i++)
        {
            if(Places[i][j].getState() == o)
            {
                score++;
                if(score == WIN) // end of board X won
                {
                    GameEnd = true;
                    return owins;
                }
            }else
            {
                score = 0; // gap
            }
            j++;
        }
    }

    // verify diagonary wil condition "/" X
    for(int p = 0; p < SIZE; p++) // upper left triangle
    {
        score = 0; // new diagon
        int j = 0;
        for(int i = p; i >= 0; i--)
        {
            if(Places[i][j].getState() == x)
            {
                score++;
                if(score == WIN) // end of board X won
                {
                    GameEnd = true;
//                    qDebug() << "X wygrało diagonalnie /.\n";
                    return xwins;
                }
            }else{
                score = 0;
            }
            j++;
        }
    }
    for(int p = 0; p < SIZE; p++) // lower right triange
    {
        int j = SIZE - 1;
        score = 0; // new diagon
        for(int i = p; i < SIZE; i++)
        {
            if(Places[j][i].getState() == x)
            {
                score++;
                if(score == WIN) // end of board X won
                {
                    GameEnd = true;
//                    qDebug() << "X wygrało diagonalnie /.\n";
                    return xwins;
                }
            }else{
                score = 0;
            }
            j--;
        }
    }

    // verify diagonary wil condition "/"
    for(int p = 0; p < SIZE; p++) // upper left triangle
    {
        score = 0; // new diagon
        int j = 0;
        for(int i = p; i >= 0; i--)
        {
            if(Places[i][j].getState() == o)
            {
                score++;
                if(score == WIN) // end of board X won
                {
                    GameEnd = true;
//                    qDebug() << "O wygrało diagonalnie /.\n";
                    return owins;
                }
            }else{
                score = 0;
            }
            j++;
        }
    }
    for(int p = 0; p < SIZE; p++) // lower right triange
    {
        int j = SIZE - 1;
        score = 0; // new diagon
        for(int i = p; i < SIZE; i++)
        {
            if(Places[j][i].getState() == o)
            {
                score++;
                if(score == WIN) // end of board X won
                {
                    GameEnd = true;
//                    qDebug() << "O wygrało diagonalnie /.\n";
                    return owins;
                }
            }else{
                score = 0;
            }
            j--;
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

    // chosen of first move
    if( (!turn && Places[SIZE/2][SIZE/2].getState() == Blank ) || (turn && moveNumber == 1  && Places[SIZE/2][SIZE/2].getState() == Blank) )
    {
        bestMove[0] = bestMove[1] = SIZE/2;
    }
    else if(turn && moveNumber == 1  && Places[SIZE/2 -1][SIZE/2 - 1].getState() == Blank )
    {
        bestMove[0] = bestMove[1]  = SIZE/2 - 1;

    }// chosen of the best move using minMax
    else{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(Places[i][j].getState() == Blank)
            {
                Places[i][j].setState(turn? x : o );
                int eval = miniMax(SEARCH_DEPH, INT_MIN, INT_MAX, !turn);
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
                }else{
                    if(eval < minMaxEval)
                    {
                        bestMove[0] = i;
                        bestMove[1] = j;
                        minMaxEval = eval;
                    }
                }
            }
        }
    }
}
    // visualizate move
    turn?Places[bestMove[0]][bestMove[1]].setState(x):Places[bestMove[0]][bestMove[1]].setState(o); // save information about state
    turn?Places[bestMove[0]][bestMove[1]].setText("x"):Places[bestMove[0]][bestMove[1]].setText("o"); // set "o" or "x"
    Places[bestMove[0]][bestMove[1]].setEnabled(false); // turn off the button
    increaseMoveNumber(); // count the omve
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

/*!
 * \brief Game::setTurn
 * \param t - true - user is o, false - user is x
 */
void Game::setTurn(bool t)
{
    turn = t;
}


/*!
 * \brief Game::increaseMoveNumber
 */
void Game::increaseMoveNumber()
{
    moveNumber++;
}
