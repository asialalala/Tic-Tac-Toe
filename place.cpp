#include "Place.h"

/*!
 * \brief Place::Place Constructor of class Place which counts number of Places
 * \param parent - type of widget
 */
Place::Place(QWidget *parent) :
    QPushButton(parent)
{
    ResID++;            // Increment of counter by one
    buttonID = ResID;   // Assigning a button number which will be further work with buttons
}

/*!
 * \brief Place::~Place
 */
Place::~Place()
{

}

/*!
 * \brief Place::getID
 * \return buttonID
 */
int Place::getID()
{
    return buttonID;
}

/*!
 * \brief QPlace::ResID  global initialization of static variable
 */
int Place::ResID = 0;
