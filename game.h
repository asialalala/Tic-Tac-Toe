#ifndef GAME_H
#define GAME_H


class Game
{
private:
    int X;
    int Y;
public:
    Game();
    void setX(int x);
    void setY(int y);
    int getX() const;
    int getY() const;
};

#endif // GAME_H
