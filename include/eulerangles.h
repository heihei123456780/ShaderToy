#ifndef EULER_ANGLES_H
#define EULER_ANGLES_H

class Quaternion;

class EulerAngles
{
public:
    EulerAngles()
        : m_yaw(0.0f), m_roll(0.0f), m_pitch(0.0f) 
    {
    }
    
    EulerAngles(const EulerAngles &other)
        : m_yaw(other.m_yaw), m_roll(other.m_roll), m_pitch(other.m_pitch) 
    {
    }
    
    EulerAngles(float yaw, float roll, float pitch)
        : m_yaw(yaw), m_roll(roll), m_pitch(pitch) 
    {
    }
        
    ~EulerAngles()
    {
    }

    inline float yaw() const { return m_yaw; }
    inline float roll() const { return m_roll; }
    inline float pitch() const { return m_pitch; }

    inline void setYaw(float y) { m_yaw = y; }
    inline void setRoll(float r) { m_roll = r; }
    inline void setPitch(float p) { m_pitch = p; }

    void identity();
    void fromQuaternion(const Quaternion &quat);
    
    Quaternion toQuaternion() const;

private:
    float m_yaw, m_roll, m_pitch;
};


#endif // _EULER_ANGLES_H_
