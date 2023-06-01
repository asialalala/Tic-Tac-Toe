#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{

    game.setX((ui->spinBoxX->text()).toInt());
    game.setY((ui->spinBoxY->text()).toInt());

    for(int i = 0; i < game.getY(); i++)
    {
        for(int j = 0; j < game.getX(); j++)
        {
            Place *button = new Place(this);  // Create a dynamic button object
            // Set the text with number of button
            button->setText("Numer " + QString::number(button->getID()));
            // Adding a button to the bed with a vertical layout
            ui->gridLayout->addWidget(button, i, j);
            // Connect the signal to the slot pressing buttons produce numbers

            connect(button, SIGNAL(clicked()), this, SLOT(slotGetNumber()));
            connect(button, SIGNAL(clicked()), this, SLOT(slotPut0()));
        }
    }

    ui->addButton->setEnabled(false); // turn off the butto to add places
}


/*!
 * \brief MainWindow::slotGetNumber writes number ID in place in right
 */
void MainWindow::slotGetNumber()
{
    // To determine the object that caused the signal
    Place *button = (Place*) sender();
    /* Then set the number of buttons in lineEdit,
     * which is contained in the dynamic button */
    ui->lineEdit->setText(QString::number(button->getID()));
    /* That is the key number is set to lineEdit field only
     * when we press one of the dynamic keys,
     * and this number corresponds to the button you pressed
     * */
}

/*!
 * \brief MainWindow::slotPut0 set "o" on the button and enable
 * the button
 */
void MainWindow::slotPut0()
{
    // To determine the object that caused the signal
    Place *button = (Place*) sender();
    button->setText("o"); // set "o"
    button->setEnabled(false); // turn off the button
}




