#include "mainwindow.h"
#include "./ui_mainwindow.h"


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
    Place *button = new Place(this);  // Create a dynamic button object
    /* Set the text with number of button
     * */
    button->setText("Numer " + QString::number(button->getID()));
    // Adding a button to the bed with a vertical layout
    ui->gridLayout->addWidget(button);
    // Connect the signal to the slot pressing buttons produce numbers

    connect(button, SIGNAL(clicked()), this, SLOT(slotGetNumber()));
}



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



