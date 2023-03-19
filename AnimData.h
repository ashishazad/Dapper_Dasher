#pragma once

class AnimData
{
public:
    AnimData()
    {

    }

    AnimData(int width, int height, int totalFrame_, float animationDelay_) :
        runningAnimationTime(0),
        animationDelay(animationDelay_),
        currentFrame(0),
        totalFrame(totalFrame_)
    {
        frameTime = FrameTime::getInstance();
        Rec.width = width;
        Rec.height  = height;
        Rec.x = 0;
        Rec.y = 0;
    }

    void updateAnimData()
    {
        Rec.x = currentFrame*Rec.width;
        if(runningAnimationTime >= animationDelay){
            currentFrame = (currentFrame+1)%totalFrame;
            runningAnimationTime = 0;
        }
        runningAnimationTime += frameTime->deltaTime();
    }

    FrameTime *frameTime;
    float runningAnimationTime;
    float animationDelay;
    int currentFrame; 
    int totalFrame;
    Rectangle Rec;
};