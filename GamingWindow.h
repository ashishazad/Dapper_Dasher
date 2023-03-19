#pragma once
#include <string>

class GamingWindow
{
public:
    GamingWindow(): height(50),width(50){};
    GamingWindow(int y,int x,std::string t): height(y),width(x),title(t)
    {

    }
    int height;
    int width;
    std::string title;
};