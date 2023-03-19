#include "GamingWindow.h"
#include <raylib.h>
#include "FrameTime.h"
#include "AnimData.h"

class Runner
{
private:
    int current_direction;
    bool isOnGround(const GamingWindow &gameWindow)
    {
        return pos.y < gameWindow.height-animData->Rec.height;
    }
public:
    Vector2 pos;
    float velocity;
    int jump_velocity;
    float gravity;

    Texture2D scarfy;
    AnimData *animData;

    FrameTime *frameTime;

    Runner();
    Runner(const GamingWindow &gameWindow)
    {
        gravity = 1600;
        jump_velocity = -800;
        velocity = 0;
        scarfy = LoadTexture("textures/scarfy.png");
        animData = new AnimData(scarfy.width/6,scarfy.height,5,0.08);

        pos.x = gameWindow.width/2-animData->Rec.width/2;
        pos.y = gameWindow.height  - animData->Rec.height;
        
        frameTime = FrameTime::getInstance();
    }

    ~Runner()
    {
        UnloadTexture(scarfy);
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
    
    void MoveRunner(const GamingWindow &gameWindow)
    {
        if(isOnGround(gameWindow))
        {
            velocity += gravity*frameTime->deltaTime();   
        }
        else
        {
            velocity = 0;
        }

        if(velocity == 0 && IsKeyPressed(KEY_SPACE))
        {
            velocity = jump_velocity;
        }
        pos.y += velocity*frameTime->deltaTime();
    }

    void DrawRunner()
    {
        //change animation frame
       animData->updateAnimData();

        // Draw sprite
        DrawTextureRec(scarfy,animData->Rec,pos,WHITE);
    }
};