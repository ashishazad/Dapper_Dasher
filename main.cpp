#include <cstdio>
#include <raylib.h>
#include <chrono>
#include <iostream>
#include <thread>
#include "GamingWindow.h"
#include "Runner.h"
#include "FrameTime.h"
#include "HazardSpawner.h"
#include "Background.h"

bool isCollisionDetected = false;

int main()
{
    GamingWindow gameWindow(380,512,"DapperDasher!!");
    InitWindow(gameWindow.width,gameWindow.height,gameWindow.title.c_str());

    FrameTime *frameTime = FrameTime::getInstance();
    // SetTargetFPS(60);

    Runner runner(gameWindow);
    HazardSpawner hazardSpawner(gameWindow);
    Background background("textures/far-buildings.png",20);
    Background midground("textures/back-buildings.png",40);
    Background foreground("textures/foreground.png",80);

    while(!WindowShouldClose()){
        if(frameTime->GetFrameTime()>16667)
        {
            frameTime->UpdateFrameTime();

            BeginDrawing();
            ClearBackground(WHITE);
            background.DrawBackground(gameWindow);
            midground.DrawBackground(gameWindow);
            foreground.DrawBackground(gameWindow);
            if(hazardSpawner.DetectCollision(runner))
            {
                DrawText("Game Over!!",gameWindow.width/4,gameWindow.height/3,40,RED);
            }
            else if(runner.left() > hazardSpawner.FinishLine())
            {
                DrawText("Game Won!!",gameWindow.width/4,gameWindow.height/3,40,GREEN);
            }
            else
            {
                runner.MoveRunner(gameWindow);
                hazardSpawner.MoveHazards(gameWindow);

                runner.DrawRunner();
                hazardSpawner.DrawHazards();
            }
            EndDrawing();     
        }  
    }
    CloseWindow();
}