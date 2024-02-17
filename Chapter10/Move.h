#pragma once

class Move
{
private:
    double x;
    double y;

public:
    Move(double a = 0, double b = 0);
    void showMove() const;
    void moveAdd(const Move &m);
    void reset(double a = 0, double b = 0);
};