#pragma once
class Rectangle
{
public:
    Rectangle();
    ~Rectangle();
    int GetHeight();
    int GetWeight();

private:
    int xLow, yLow, height, width;
};