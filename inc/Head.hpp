#ifndef HEAD_HPP
#define HEAD_HPP

class Head
{
private:
    /* data */
    int _sqSize = 10;
    int _x;
    int _y;

public:
    Head();
    Head(int x, int y);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);

    void draw() const;
    bool checkCollision(int x, int y) const;
    void setPosition();

    ~Head();
};

#endif