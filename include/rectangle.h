#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "size.h"
#include "point.h"

class Rectangle
{
public:
    Rectangle() 
        : m_t(0), m_b(0), m_l(0), m_r(0) 
    {
    }

    Rectangle(int top, int bottom, int left, int right) 
        : m_t(top), m_b(bottom), m_l(left), m_r(right) 
    {
    }
    
    Rectangle(const Point &topleft, const Point &bottomright)
        : m_t(topleft.y()),
          m_b(bottomright.y()),
          m_l(topleft.x()),
          m_r(bottomright.y()) 
    {
    }

    Rectangle(const Point &point, const Size &size)
        : m_t(point.y()),
          m_b(point.y() + size.height()),
          m_l(point.x()),
          m_r(point.x() + size.width())
    {
    }

	Rectangle(const Size &size, const Point &point)
		: m_t(point.y()),
		  m_b(point.y() + size.height()),
		  m_l(point.x()),
		  m_r(point.x() + size.width())
	{
    }

    ~Rectangle()
    {
    }

    inline bool isEmpty() const { return (m_l > m_r) || (m_t > m_b);  }
    inline bool isNull() const { return (m_r == m_l - 1) && (m_b == m_t - 1); }
    inline bool isValid() const { return (m_l <= m_r) && (m_t <= m_b); }

    inline int x() const { return m_l; }
    inline int y() const { return m_t; }

    inline void setX(int x) { m_l = x; }
    inline void setY(int y) { m_t = y; }

    inline int width() const { return m_r - m_l; }
    inline int height() const { return m_b - m_t; }

    inline void setWidth(int w) { m_r = m_l + w; }
    inline void setHeight(int h) { m_b = m_t + h; }

    inline int top() const { return m_t; }
    inline int bottom() const { return m_b; }
    inline int left() const { return m_l; }
    inline int right() const { return m_r; }

    inline int area() const { return width() * height(); }
    inline int perimeter() const { return (width() + height()) * 2; }

    inline void setTop(int t) { m_t = t; }
    inline void setBottom(int b) { m_b = b; }
    inline void setLeft(int l) { m_l = l; }
    inline void setRight(int r) { m_r = r; }

    inline Point topLeft() const { return Point(m_l, m_t); }
    inline Point bottomLeft() const { return Point(m_l, m_b); }
    inline Point topRight() const { return Point(m_r, m_t); }
    inline Point bottomRight() const { return Point(m_r, m_b); }
    inline Point center() const { return Point((m_l + m_r) / 2, (m_t + m_b) / 2); }
    
    inline void setTopLeft(const Point &point) 
    { 
        m_t = point.y(); 
        m_l = point.x(); 
    }
    
    inline void setBottomLeft(const Point &point) 
    { 
        m_b = point.y(); 
        m_l = point.x(); 
    }

    inline void setTopRight(const Point &point) 
    { 
        m_t = point.y(); 
        m_r = point.x(); 
    }

    inline void setBottomRight(const Point &point) 
    { 
        m_b = point.y(); 
        m_r = point.x(); 
    }

    void setCenter(const Point &point);
    void setRectangle(const Rectangle &Rectangle);
    void setRectangle(int top, int bottom, int left, int right);

	inline Size size() const { return Size(m_r - m_l, m_b - m_t); }
    inline void setSize(const Size &s) { m_r = m_l + s.width(); m_b = m_t + s.height(); }

    inline void moveTo(int dx, int dy);
    inline void moveTo(const Point &point);

    inline void moveTop(int top) 
    { 
        m_b += (top - m_t);
        m_t = top; 
    }

    inline void moveBottom(int bottom) 
    { 
        m_t += (bottom - m_b); 
        m_b = bottom; 
    }

    inline void moveLeft(int left) 
    { 
        m_r += (left - m_l); 
        m_l = left; 
    }

    inline void moveRight(int right) 
    { 
        m_l += (right - m_r); 
        m_r = right; 
    }

    inline void moveCenter(const Point &point);

    inline void moveTopLeft(const Point &point) 
    { 
        moveTop(point.y()); 
        moveLeft(point.x()); 
    }

    inline void moveBottomLeft(const Point &point) 
    { 
        moveBottom(point.y()); 
        moveLeft(point.x()); 
    }

    inline void moveTopRight(const Point &point) 
    { 
        moveTop(point.y()); 
        moveRight(point.x()); 
    }

    inline void moveBottomRight(const Point &point) 
    { 
        moveBottom(point.y()); 
        moveRight(point.x()); 
    }
    
    inline bool contains(int x, int y) const 
    { 
        return x >= m_l && x <= m_r && y >= m_t && y <= m_b; 
    }
    
    inline bool contains(const Point &point) const { return contains(point.x(), point.y()); }
    inline void inflate(Size &size) { inflate(size.width(), size.height()); }
    //inline void inflate(Rectangle &rect) { inflate(rect.size()); }
    
    bool contains(const Rectangle &rect) const;
    void inflate(int width, int height);
   
    static Rectangle intersects(const Rectangle &rect1, const Rectangle &rect2);
    static Rectangle unions(const Rectangle &rect1, const Rectangle &rect2);

    Rectangle &operator=(const Rectangle &rect);
    //Rectangle operator&(Rectangle &rect1, Rectangle &rect2) { return Rectangle::intersects(rect1, rect2); }
    //Rectangle operator|(const Rectangle &rect1, const Rectangle &rect2) { return Rectangle::unions(rect1, rect2); }

    friend bool operator==(const Rectangle &rect1, const Rectangle &rect2);
    friend bool operator!=(const Rectangle &rect1, const Rectangle &rect2);

private:
    // top, bottom, left, down
    int m_t, m_b, m_l, m_r;
};

#endif // RECTANGLE_H
