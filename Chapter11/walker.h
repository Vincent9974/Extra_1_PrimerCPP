#pragma once

class Walker {
public:
    Walker(int targetDistance, double stepSize);
    void takeStep();
    double getX() const { return x; }
    double getY() const { return y; }
    int getStepCount() const { return stepCount; }

private:
    double x;
    double y;
    int stepCount;
    int targetDistance;
    double stepSize;
};