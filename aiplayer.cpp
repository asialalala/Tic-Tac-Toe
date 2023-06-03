#include "aiplayer.h"

// IT IS NOT USED


/*!
 * \brief AIPlayer::AIPlayer
 */
AIPlayer::AIPlayer()
{

}

int AIPlayer::bestMove(Game * game)
{
    int  best_move[3] ;
    int minMaxEval = game->getTurn()? INT_MIN : INT_MAX;

    for(int i = 0; i < game->getY(); i++)
    {
        for(int j = 0; j < game->getX(); j++)
        {
            if(!game->getPlaces()[i*game->getX()+j].getOff())
            {
                game->getPlaces()[i*game->getX()+j].setText(game->getTurn()? "x" : "o");
                game->getPlaces()[i*game->getX()+j].setOff(true);
                int eval = miniMax(game);

                // restor beginning setting
                game->getPlaces()[i*game->getX()+j].setText(" ");
                game->setGameEnd(false);
                game->getPlaces()[i*game->getX()+j].setOff(false);

                if(game->getTurn())
                {
                   if(eval > minMaxEval)
                   {
                       best_move[0] = j*game->getX() + 1; // next to right side
                       best_move[1] = i;
                   }
                }else
                {
                    if(eval < minMaxEval)
                        best_move[0] = j*game->getX() + 1; // next to right side
                        best_move[1] = i;
                }
            }

        }
    }
}




int evaluateBoard()
{

}
int AIPlayer::miniMax(Game * game)
{

}
