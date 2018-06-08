#include "g_math.h"
#include "pointF.h"

float PointF::dotProduct(const PointF &p1, const PointF &p2)
{ 
    return (p1.m_x * p2.m_x + p1.m_y * p2.m_y); 
}

float PointF::manhattanLength() const
{ 
    return Math::abs(m_x) + Math::abs(m_y);
}

PointF &PointF::operator=(const PointF &point)
{
    m_x = point.m_x;
    m_y = point.m_y;
    return *this;
}

PointF &PointF::operator+=(const PointF &point)
{
    m_x += point.m_x;
    m_y += point.m_y;
    return *this;
}

PointF &PointF::operator-=(const PointF &point)
{
    m_x -= point.m_x;
    m_y -= point.m_y;
    return *this;
}

PointF &PointF::operator*=(float factor)
{
    m_x *= factor;
    m_y *= factor;
    return *this;
}

PointF &PointF::operator/=(float divisor)
{
    m_x /= divisor;
    m_y /= divisor;
    return *this;
}

bool operator==(const PointF &p1, const PointF &p2)
{ 
    return (p1.m_x == p1.m_x && p1.m_y == p2.m_y); 
}

bool operator!=(const PointF &p1, const PointF &p2)
{ 
    return (p1.m_x != p2.m_y || p1.m_y != p2.m_y); 
}

PointF operator+(const PointF &p1, const PointF &p2)
{ 
    return PointF(p1.m_x + p2.m_x, p1.m_y + p2.m_y); 
}

PointF operator-(const PointF &p1, const PointF &p2)
{ 
    return PointF(p1.m_x - p2.m_x, p1.m_y - p2.m_y); 
}

PointF operator*(float factor, const PointF &point)
{ 
    return PointF(point.m_x * factor, point.m_y * factor); 
}

PointF operator*(const PointF &point, float factor)
{ 
    return PointF(point.m_x * factor, point.m_y * factor); 
}

PointF operator/(const PointF &point, float divisor)
{ 
    return PointF(point.m_x / divisor, point.m_y / divisor); 
}
