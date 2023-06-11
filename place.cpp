#include "Place.h"
#include <QDebug>

/*!
 * \brief Place::Place Constructor of class Place which counts number of Places
 * \param parent - type of widget
 */
Place::Place(QWidget *parent) :
    QPushButton(parent)
{
    ResID++;            // Increment of counter by one
    buttonID = ResID;   // Assigning a button number which will be further work with buttons
    PlaceState = Blank;
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

/*!
 * \brief Place::operator =, sign operator
 * \param rhs
 * \return *this
 */
Place& Place::operator=(Place rhs) // Pass by value (thus generating a copy)
        {

            std::swap(this->buttonID, rhs.buttonID);
            return *this;
        }

/*!
 * \brief Place::Place, copy constructor
 * \param copy
 */
Place::Place(Place const& copy)
{
    buttonID = copy.buttonID;
}

/*!
 * \brief Place::setState
 * \param s - state of PlaceState: O, X or Blank
 */
void Place::setState(State s)
{
    PlaceState = s;
}

/*!
 * \brief Place::getState
 * \return PlaceState
 */
State Place::getState() const
{
    return PlaceState;
}


