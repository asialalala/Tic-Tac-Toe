#ifndef PLACE_H
#define PLACE_H

/*!
 * \file
 * \brief Definition of class Place
 *
 * The file inludes definition of class Place where cross or circle can be sitated.
 * It is class inherited from QPushButton.
 */

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include "defined.h"
/*!
 * \file
 * \brief The Place class
 *
 * The file icludes definition of class Place
 * that
 */
class Place : public QPushButton
{
     Q_OBJECT
public:
    explicit Place(QWidget *parent = 0);
    ~Place();
    static int ResID;   // A static variable counter buttons rooms
    int getID();        // Function to return a local number buttons
    Place& operator=(Place rhs);
    Place(Place const& copy);
    void setState(State s);
    State getState() const;

public slots:

private:
    int buttonID = 0;   // Local variable number of the button
    State PlaceState;
};

#endif // PLACE_H
