#ifndef DEFINED_H
#define DEFINED_H

#define SEARCH_DEPH 3
#define SCORES_TO_WIN 3

/*!
 * \brief The Status enum which informs of game's status
 */
enum Status
{
    keepUp = 0,
    Xwins = 1, // X wines (Maximizer)
    Owins = 2, // O wines (Minimizer)
};

/*!
 * \brief The State enum which informs about element inludec in a place
 */
enum State
{
    Blank,
    x,
    o,
};
#endif // DEFINED_H
