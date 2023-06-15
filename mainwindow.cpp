#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>


/*!
 * \brief MainWindow::MainWindow
 * \param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButtonReset->setEnabled(false); // there is nothing to reset
}

/*!
 * \brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    // set elements of game
    int size = (ui->spinBoxSIZE->text()).toInt();
    int win = (ui->spinBoxWIN->text()).toInt();

    ui->checkBox->setEnabled(false); // turn of checkBox

    if(size < win || win <= 1 || size <= 0)
    {
        QMessageBox msgBox;
        msgBox.setText("The number of positions to win has to be less than the size, number win and size have to be more than 1.");
        msgBox.exec();
        return;
    }
    game.setSIZE(size);
    game.setWIN(win);
    game.allocatePlaces();

    ui->spinBoxSIZE->setEnabled(false); // turn off shoosing size X
    ui->spinBoxWIN->setEnabled(false); // turn off shoosing size Y

    // create buttons
    for(int i = 0; i < game.getSIZE(); i++)
    {
        for(int j = 0; j < game.getSIZE(); j++)
        {
            Place * button = &(game.getPlaces()[i][j]);

            ui->gridLayout->addWidget(button, i, j);
            button->setStyleSheet("height: 48px; width: 48px; font-size: 36px");
            // Connect the signal to the slot pressing buttons set 'o' and trigger AI
            connect(button, SIGNAL(clicked()), this, SLOT(slotPut0()));

        }
    }

    ui->addButton->setEnabled(false); // turn off the button of adding places

    // if AI is o, AI has to strt the game
    if(!game.getTurn())
        game.AIMove();

}


/*!
 * \brief MainWindow::slotPut0 set "o" or "x" on the button and enable
 * the button and than call AImove
 */
void MainWindow::slotPut0()
{
    // To determine the object that caused the signal
    QWidget * widget = (QWidget *) sender();


    int i, j, spanI, spanJ = 0;
    ui->gridLayout->getItemPosition(ui->gridLayout->indexOf(widget), &i, &j, &spanI, &spanJ);

    // vizualizate move
    game.getTurn()?game.getPlaces()[i][j].setText("o"):game.getPlaces()[i][j].setText("x"); // set "o" or "x"
    game.getTurn()?game.getPlaces()[i][j].setState(o):game.getPlaces()[i][j].setState(State::x); // save information about state
    game.getPlaces()[i][j].setEnabled(false); // turn off the button
    game.increaseMoveNumber();
    Winner result = game.whoWins();

    comunicate(result);

    if(!game.getGameEnd()) // if it is not end AI plaies
    {
        game.AIMove(); // AI turn
        result = game.whoWins(); // check if AI has won
        comunicate(result);
    }
}

void MainWindow::comunicate(Winner result)
{
    QMessageBox msgBox;
    switch(result)
    {
        case nobody:
            return;
        case xwins:
            msgBox.setText("Player X has won.");
            msgBox.exec();
            for(int i = 0; i < game.getSIZE(); i++) // turn of the rest of buttons
            {
                for(int j = 0; j < game.getSIZE(); j++)
                {
                    if(game.getPlaces()[i][j].getState() == Blank)
                        game.getPlaces()[i][j].setEnabled(false);
                }
            }
            ui->pushButtonReset->setEnabled(true);
            break;
        case owins:
            msgBox.setText("Player O has won.");
            msgBox.exec();
            for(int i = 0; i < game.getSIZE(); i++) // turn of the rest of buttons
            {
                for(int j = 0; j < game.getSIZE(); j++)
                {
                    if(game.getPlaces()[i][j].getState() == Blank)
                        game.getPlaces()[i][j].setEnabled(false);
                }
            }
            ui->pushButtonReset->setEnabled(true);
            break;
        case draw :
            msgBox.setText("Nobody has won. It is a draw.");
            msgBox.exec();
            for(int i = 0; i < game.getSIZE(); i++) // turn of the rest of buttons
            {
                for(int j = 0; j < game.getSIZE(); j++)
                {
                    if(game.getPlaces()[i][j].getState() == Blank)
                        game.getPlaces()[i][j].setEnabled(false);
                }
            }
            ui->pushButtonReset->setEnabled(true);
            break;
        default :
            qDebug() << "Something has gone wrong. There is no option like that in results of the game";
        break;

    }


 return;
}

/*!
 * \brief MainWindow::on_pushButtonReset_clicked after click reset board of tic-tac-toe
 */
void MainWindow::on_pushButtonReset_clicked()
{
    game.reset();
    ui->pushButtonReset->setEnabled(false);
}


/*!
 * \brief MainWindow::on_checkBox_stateChanged
 * \param check - 1 when cheked = user is playing x
 *              - o when is not checked = user is playing o
 */
void MainWindow::on_checkBox_stateChanged(int check)
{
    game.setTurn(!check);
}

