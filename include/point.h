#ifndef POINT_H
#define POINT_H

class Point
{
public:
    inline Point()
        : m_x(0), m_y(0)
    {
    }

    inline Point(int x, int y) 
        : m_x(x), m_y(y)
    {
    }
    
    inline Point(const Point &point) 
        : m_x(point.m_x), m_y(point.m_y) 
    {
    }

    ~Point()
    {
    }

    inline int x() const { return m_x; }
    inline int y() const { return m_y; }
    
    inline void setX(int x) { m_x = x; }
    inline void setY(int y) { m_y = y; }
    inline void translate(int dx, int dy) { m_x += dx; m_y += dy; }
    
    int dotProduct(const Point &p1, const Point &p2);
    int manhattanLength() const;
    

    Point &operator=(const Point &point);
    Point &operator+=(const Point &point);
    Point &operator-=(const Point &point);
    Point &operator*=(int factor);
    Point &operator*=(double factor);

    friend bool operator==(const Point &p1, const Point &p2);
    friend bool operator!=(const Point &p1, const Point &p2);

    friend Point operator+(const Point &p1, const Point &p2);
    friend Point operator-(const Point &p1, const Point &p2);
    friend Point operator*(int factor, const Point &point);
    friend Point operator*(const Point &point, int factor);

private:
    int m_x, m_y;
};

#endif // POINT_H
