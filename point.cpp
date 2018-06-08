#include "g_math.h"
#include "point.h"

int Point::dotProduct(const Point &p1, const Point &p2)
{ 
    return (p1.m_x * p2.m_x + p1.m_y * p2.m_y); 
}

int Point::manhattanLength() const
{ 
    return Math::abs(m_x) + Math::abs(m_y);
}

Point &Point::operator=(const Point &point)
{
    m_x = point.m_x;
    m_y = point.m_y;
    return *this;
}
Point &Point::operator+=(const Point &point)
{
    m_x += point.m_x;
    m_y += point.m_y;
    return *this;
}

Point &Point::operator-=(const Point &point)
{
    m_x -= point.m_x;
    m_y -= point.m_y;
    return *this;
}

Point &Point::operator*=(int factor)
{
    m_x *= factor;
    m_y *= factor;
    return *this;
}

bool operator==(const Point &p1, const Point &p2)
{ 
    return (p1.m_x == p2.m_x && p1.m_y == p2.m_y); 
}

bool operator!=(const Point &p1, const Point &p2)
{ 
    return (p1.m_x != p2.m_y || p1.m_y != p2.m_y); 
}

Point operator+(const Point &p1, const Point &p2)
{ 
    return Point(p1.m_x + p2.m_x, p1.m_y + p2.m_y); 
}

Point operator-(const Point &p1, const Point &p2)
{ 
    return Point(p1.m_x - p2.m_x, p1.m_y - p2.m_y); 
}

Point operator*(int factor, const Point &point)
{ 
    return Point(point.m_x * factor, point.m_y * factor); 
}

Point operator*(const Point &point, int factor)
{ 
    return Point(point.m_x * factor, point.m_y * factor); 
}

