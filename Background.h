#include "GamingWindow.h"
#include <string>
class Background
{
private:
    Texture2D background;
    float bgx{};
    FrameTime *frameTime;
    int speed;
public:
    Background(std::string texturePath, int speed_)
    {
        frameTime = FrameTime::getInstance();
        background = LoadTexture(texturePath.c_str());
        speed = speed_;
    }

    ~Background()
    {
        UnloadTexture(background);
    }

    void DrawBackground(const GamingWindow &gameWindow)
    {
        bgx -= speed*frameTime->deltaTime();
        Vector2 bgPos{bgx,0.0};
        Vector2 bgPos2{bgx+gameWindow.width,0.0};
        
        DrawTextureEx(background,bgPos,0.0,2.0,WHITE);
        DrawTextureEx(background,bgPos2,0.0,2.0,WHITE); 

        //calculate if bg gets out of range for next frame before hand
        if(bgx - speed*frameTime->deltaTime() <= -gameWindow.width)
        {
            bgx += gameWindow.width;
        }  
    }

};