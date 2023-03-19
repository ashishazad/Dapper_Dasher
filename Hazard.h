#include "GamingWindow.h"
#include <raylib.h>
#include "FrameTime.h"
#include "AnimData.h"

class Hazard
{
private:
    int current_direction;
public:
    Vector2 pos;
    
    static float velocity;

    static Texture2D nebula;
    static AnimData *animData;

    FrameTime *frameTime;

    Hazard() = default;
    Hazard(const GamingWindow &gameWindow)
    {
        
        pos.x = gameWindow.width;
        pos.y = gameWindow.height  - animData->Rec.height;

        frameTime = FrameTime::getInstance();
    }

    ~Hazard()
    {
        // UnloadTexture(nebula); todo: Why this is causing error of showing different texture itself
    }

    float bottom()
    {
        return pos.y+animData->Rec.height;
    }
    float up()
    {
        return pos.y;
    }
    float right()
    {
        return pos.x+animData->Rec.width;
    }
    float left()
    {
        return pos.x;
    }
    
    void MoveHazard(const GamingWindow &gameWindow)
    {
        pos.x = pos.x + velocity*frameTime->deltaTime();
    }

    void DrawHazard()
    {
        //change animation frame
        animData->updateAnimData();

        // Draw sprite
        DrawTextureRec(nebula,animData->Rec,pos,WHITE);
    }
};

float Hazard::velocity;
Texture2D Hazard::nebula;
AnimData *Hazard::animData = nullptr;