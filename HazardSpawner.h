#include "GamingWindow.h"
#include "Hazard.h"

//should also be singleton component
class HazardSpawner
{
private:
    int totalHazards = 5;
    Hazard *hazards;
    float pad;
public:
    HazardSpawner(const GamingWindow &gameWindow)
    { 
        Hazard::velocity = -250;
        Hazard::nebula = LoadTexture("textures/12_nebula_spritesheet.png");
        Hazard::animData = new AnimData(Hazard::nebula.width/8,Hazard::nebula.height/8,8,0.02);
        pad = 30;

        hazards = new Hazard[totalHazards];
        for(int i=0;i<totalHazards;i++)
        {
            hazards[i] = Hazard(gameWindow);
            hazards[i].pos.x += i*gameWindow.width;
        }
    }

    ~HazardSpawner()
    {
        UnloadTexture(Hazard::nebula);
    }

    void MoveHazards(const GamingWindow &gameWindow)
    {
        for(int i=0;i<totalHazards;i++)
        {
            hazards[i].MoveHazard(gameWindow);
        }
    }

    void DrawHazards()
    {
        for(int i=0;i<totalHazards;i++)
        {
            hazards[i].DrawHazard();
        }
    }

    int FinishLine()
    {
        return hazards[totalHazards-1].right();
    }

    bool DetectCollision(Runner &runner)
    {
        Rectangle scarfyRec{
            runner.left(),
            runner.up(),
            runner.right()-runner.left(),
            runner.bottom()-runner.up()
        };
        for(int i=0;i<totalHazards;i++)
        {
            Rectangle nebulaRec{
                hazards[i].left()+pad,
                hazards[i].up()+pad,
                hazards[i].right()-hazards[i].left()-2*pad,
                hazards[i].bottom()-hazards[i].up()-2*pad
            };
            if(CheckCollisionRecs(nebulaRec,scarfyRec))
            {
                return true;
            }
        }
        return false;
    }
};