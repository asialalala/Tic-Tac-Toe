#ifndef DEFINED_H
#define DEFINED_H

#define SEARCH_DEPH 3
#define SCORES_TO_WIN 3

#define GREAT_NUMBER 10000
#define SMALL_NUMBER -10000
#define ZERO 0


/*!
 * \brief The State enum which informs about element inludec in a place
 */
enum State
{
    Blank,
    x,
    o,
};

enum Winner
{
    draw,
    xwins,
    owins,
    nobody,
};
#endif // DEFINED_H
