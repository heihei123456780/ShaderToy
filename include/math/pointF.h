#ifndef POINTF_H
#define POINTF_H 

class PointF
{
public:
    inline PointF() 
        : m_x(0.0f), m_y(0.0f) 
    {
    }
    
    inline PointF(float x, float y) 
        : m_x(x), m_y(y) 
    {
    }
    
    inline PointF(const PointF &point) 
        : m_x(point.m_x), m_y(point.m_y) 
    {
    }

    ~PointF();

    inline float x() const { return m_x; }
    inline float y() const { return m_y; }

    inline void setX(float x) { m_x = x; }
    inline void setY(float y) { m_y = y; }
    
    float dotProduct(const PointF &p1, const PointF &p2);
    float manhattanLength() const;
    
    PointF &operator=(const PointF &point);  
    PointF &operator+=(const PointF &point);
    PointF &operator-=(const PointF &point);
    PointF &operator*=(float factor);
    PointF &operator/=(float divisor);

    friend bool operator==(const PointF &p1, const PointF &p2);
    friend bool operator!=(const PointF &p1, const PointF &p2);
    
    friend PointF operator+(const PointF &p1, const PointF &p2);
    friend PointF operator-(const PointF &p1, const PointF &p2);
    friend PointF operator*(float factor, const PointF &point);
    friend PointF operator*(const PointF &point, float factor);
    friend PointF operator/(const PointF &point, float divisor);

private:
    float m_x, m_y;
};

#endif 
