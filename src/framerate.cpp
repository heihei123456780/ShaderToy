#include "common.h"
#include "framerate.h"

#define FPS_UPPER_LIMIT 200
#define FPS_LOWER_LIMIT 1
#define FPS_DEFAULT     30

FrameRate::FrameRate()
    : mFrameCount(0),
      mRateTicks(0.0f),
      mBaseTicks(0),
      mLastTicks(0),
      mRate(FPS_DEFAULT),
      mGlobalTime(0)
{
}

FrameRate::~FrameRate()
{
}

inline static Uint32 getTicks()
{
    Uint32 ticks = SDL_GetTicks();
    return ticks == 0 ? 1 : ticks;
}

void FrameRate::initFrameRate()
{
    mFrameCount = 0;
    mRate = FPS_DEFAULT;
    mRateTicks = (1000.0f / (float)FPS_DEFAULT);
    mGlobalTime = getTicks();
    mBaseTicks = mGlobalTime;
    mLastTicks = mGlobalTime;
}

int FrameRate::setFrameRate(unsigned int rate)
{
    if (rate >= FPS_LOWER_LIMIT && rate <= FPS_UPPER_LIMIT)
    {
        mFrameCount = 0;
        mRate = rate;
        mRateTicks = (1000.0f / (float)rate);
        return 0;
    }
    else
        return -1;
}

unsigned int FrameRate::frameRateDelay()
{
    Uint32 currentTicks;
    Uint32 targetTicks;
    Uint32 theDelay;
    Uint32 timePassed = 0;

    if (mBaseTicks == 0)
        initFrameRate();

    mFrameCount++;

    currentTicks = getTicks();
    mGlobalTime = currentTicks;

    timePassed = currentTicks - mLastTicks;
    mLastTicks = currentTicks;
    targetTicks = mBaseTicks + (Uint32)((float)mFrameCount * mRateTicks);

    if (currentTicks <= targetTicks)
    {
        theDelay = targetTicks - currentTicks;
        SDL_Delay(theDelay);
    }
    else
    {
        mFrameCount = 0;
        mBaseTicks = getTicks();
    }

    return timePassed;
}


