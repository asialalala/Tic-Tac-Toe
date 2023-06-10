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
    GameEnd = false; // it is the beginning, not the end :)
    turn = true;
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

/*!
 * \brief Game::whoWin
 * \return
 */
Winner Game::whoWins()
{
    // verify vertical wil condition X
    for(int i = 0; i < Y; i++)
    {
        if(Places[i][0].getState() != x)
            break;
        if(i == X-1) // end of board X won
        {
            GameEnd = true;
            qDebug() << "X wygrało.\n";
            return xwins;
        }
    }

    // verify vertical wil condition O
    for(int i = 0; i < Y; i++)
    {
        if(Places[i][0].getState() != o)
            break;
        if(i == X-1) // end of board O won
        {
            GameEnd = true;
            qDebug() << "O wygrało.\n";
            return owins;
        }
    }

    // verify hirizontal wil condition X
    for(int i = 0; i < X; i++)
    {
        if(Places[i][0].getState() != x)
            break;
        if(i == X-1) // end of board X won
        {
            GameEnd = true;
            qDebug() << "X wygrało.\n";
            return xwins;
        }
    }

    // verify hirizontal wil condition O
    for(int i = 0; i < X; i++)
    {
        if(Places[i][0].getState() != o)
            break;
        if(i == X-1) // end of board O won
        {
            GameEnd = true;
            qDebug() << "O wygrało.\n";
            return owins;
        }
    }


    // verify diagonary wil condition "\" X
    for(int i = 0; i < X; i++)
    {
        if(Places[i][i].getState() != x)
            break;
        if(i == X-1) // end of board X won
        {
            GameEnd = true;
            qDebug() << "X wygrało.\n";
            return xwins;
        }
    }

    // verify diagonary wil condition "\" O
    for(int i = 0; i < X; i++)
    {
        if(Places[i][i].getState() != o)
            break;
        if(i == X-1) // end of board O won
        {
            GameEnd = true;
            qDebug() << "O wygrało.\n";
            return owins;
        }
    }

    // verify diagonary wil condition "/" X
    for(int i = 0; i < X; i++)
    {
        for(int j = (Y-1); j >= 0; j--)
        {
            if(Places[i][j].getState() != x)
                break;
            if(i == X-1) // end of board X won
            {
                GameEnd = true;
                qDebug() << "X wygrało.\n";
                return xwins;
            }
        }
    }

    // verify diagonary wil condition "/"
    for(int i = 0; i < X; i++)
    {
        for(int j = (Y-1); j >= 0; j--)
        {
            if(Places[i][j].getState() != o)
                break;
            if(i == X-1) // end of board O won
            {
                GameEnd = true;
                qDebug() << "O wygrało.\n";
                return owins;
            }
        }
    }


    // check if there is empty position
    for(int i = 0; i < X; i++)
    {
        for(int j = 0; j < Y; j++)
        {
           if(Places[j][i].getState() == Blank)
           {
               qDebug() << "Jeszcze rozgrywka się nie skończyła.";
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
        for(int i = 0;  i < X; i++)
        {
            for(int j = 0; j < Y; j++)
            {
                if(Places[j][i].getState() == Blank)
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
        for(int i = 0;  i < X; i++)
        {
            for(int j = 0; j < Y; j++)
            {
                if(Places[j][i].getState() == Blank)
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
    qDebug() << "AI wykonuje ruch \n";
    int bestMove[2] = {0,0} ;
    int minMaxEval = turn? INT_MIN : INT_MAX;

    for(int i = 0; i < Y; i++)
    {
        for(int j = 0; j < X; j++)
        {
            if(Places[i][j].getState() == Blank)
            {
                qDebug() << "petla \n";
                qDebug() << i;
                qDebug() << j;
                Places[i][j].setText(turn? "x" : "o");
                Places[i][j].setState(turn? x : o );
                int eval = miniMax(SEARCH_DEPH, INT_MIN, INT_MAX, false);
                // restor beginning setting
                Places[i][j].setText(" ");
                setGameEnd(false);
                Places[i][j].setState(Blank);

                // get the maximum evaluation if current turn is X
                if(turn)
                {
                   if(eval > minMaxEval)
                   {
                       bestMove[0] = i; // next to right side
                       bestMove[1] = j;
                       minMaxEval = eval;
                   }
                }//else // get the minimum evaluation if current turn is O
//                {
//                    if(eval < minMaxEval)
//                     //   bestMove[0] = j*X + 1; // next to right side
//                      //  bestMove[1] = i;
//                        minMaxEval = eval;
//                }
            }
        }
    }
    qDebug() << "koniec petli \n";
    Places[bestMove[0]][bestMove[1]].setState(x);
    Places[bestMove[0]][bestMove[1]].setText("x");
    Places[bestMove[0]][bestMove[1]].setEnabled(false);

    qDebug() << "Ruch wykonany. \n";
}
