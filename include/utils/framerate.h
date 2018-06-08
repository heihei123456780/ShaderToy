#ifndef FRAMERATE_H
#define FRAMERATE_H

class FrameRate
{
public:
    FrameRate();
    ~FrameRate();

    void initFrameRate();
    int setFrameRate(unsigned int rate);

    unsigned int frameRate() const { return mRate; }
    unsigned int frameCount() const { return mFrameCount; }
    unsigned int globalTime() const { return mGlobalTime; }

    unsigned int frameRateDelay();

private:
    unsigned int mFrameCount;
    float mRateTicks;
    unsigned int mBaseTicks;
    unsigned int mLastTicks;
    unsigned int mRate;
    unsigned int mGlobalTime;
};

#endif // GLFRAMERATE_H
