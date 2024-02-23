#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "walker.h"



Walker::Walker(int targetDistance, double stepSize) : x(0.0),
y(0.0), stepCount(0), targetDistance(targetDistance), stepSize(stepSize){}

void Walker::takeStep()
{
    double angle = (std::rand() % 360) * (3.14/ 180.0);
    x += stepSize * std::cos(angle);
    y += stepSize * std::sin(angle);
    stepCount++;
}
