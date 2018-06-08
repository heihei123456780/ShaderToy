#ifndef RECTANGLEF_H
#define RECTANGLEF_H

#include "sizeF.h"
#include "pointF.h"

class RectangleF
{
public:
    inline RectangleF() 
        : m_x(0.0f), m_y(0.0f), m_w(0.0f), m_h(0.0f) 
    {
    }
  
    inline RectangleF(float x, float y, float w, float h) 
        : m_x(x), m_y(y), m_w(w), m_h(h) 
    {
    }
    
    inline RectangleF(const RectangleF &rect)
        : m_x(rect.m_x), m_y(rect.m_y), m_w(rect.m_w), m_h(rect.m_h) 
    {
    }
    
    inline RectangleF(const PointF &point, const SizeF &size)
        : m_x(point.x()),
          m_y(point.y()),
          m_w(size.width()),
          m_h(size.height())
    {
    }

    inline RectangleF(const SizeF &size, const PointF &point)
        : m_x(point.x()),
          m_y(point.y()),
          m_w(size.width()),
          m_h(size.height())
    {
    }

    inline RectangleF(const PointF &topleft, const PointF &bottomright)
        : m_x(topleft.x()),
          m_y(topleft.y()),
          m_w(bottomright.x()),
          m_h(bottomright.y())
    {
    }

    ~RectangleF()
    {
    }

    inline bool isNull() const { return (m_w == 0.0f && m_h == 0.0f); }
    inline bool isEmpty() const { return (m_w <= 0.0f || m_h <= 0.0f); }
    inline bool isValid() const { return (m_w > 0.0f && m_h > 0.0f); }

    inline float x() const { return m_x; }
    inline float y() const { return m_y; }

    inline void setX(float x) { m_x = x; }
    inline void setY(float y) { m_y = y; }
 
    inline float width() const { return m_w; }
    inline float height() const { return m_h; }

    inline void setWidth(float w) { m_w = w; }
    inline void setHeight(float h) { m_h = h; }

    inline float top() const { return m_y; }
    inline float bottom() const { return m_y + m_h; }
    inline float left() const { return m_x; }
    inline float right() const { return m_x + m_w; }

    void setTop(float pos);
    void setLeft(float pos);

    inline void setBottom(float pos) { m_h = pos - m_y; }
    inline void setRight(float pos) { m_w = pos - m_x; }

    inline float area() const { return m_w * m_h; }
    inline float perimeter() const { return (m_w + m_h) * 2.0f; }

    inline PointF topLeft() const { return PointF(m_x, m_y); }
    inline PointF bottomLeft() const { return PointF(m_x, m_y + m_h); }
    inline PointF topRight() const { return PointF(m_x + m_w, m_y); }
    inline PointF bottomRight() const { return PointF(m_x + m_w, m_y + m_h); }
    inline PointF center() const { return PointF((m_x + m_w) / 2.0f, (m_y + m_h) / 2.0f); }

    inline void setTopLeft(const PointF &point) { setTop(point.y()); setLeft(point.x()); }
    inline void setBottomLeft(const PointF &point) { setBottom(point.y()); setLeft(point.x()); }
    inline void setTopRight(const PointF &point) { setTop(point.x()); setRight(point.y()); }
    inline void setBottomRight(const PointF &point) { setBottom(point.y()); setRight(point.x()); }
    
    void setCenter(const PointF &point);
    void setRectangle(const RectangleF &Rectangle);
    void setRectangle(float x, float y, float w, float h);

	inline SizeF size() const { return SizeF(m_w, m_h); }
    inline void setSize(const SizeF &s) { m_w = s.width(); m_h = s.height(); }

    inline void moveTop(float pos) { m_y = pos; }
    inline void moveBottom(float pos) { m_y = pos - m_h; }
    inline void moveLeft(float pos) { m_x = pos; }
    inline void moveRight(float pos) { m_x = pos - m_w; }
    
    inline void moveTopLeft(const PointF &point) { moveTop(point.x()); moveLeft(point.y()); }
    inline void moveBottomLeft(const PointF &point) { moveBottom(point.x()); moveLeft(point.y()); }
    inline void moveTopRight(const PointF &point) { moveTop(point.y()); moveRight(point.x()); }
    inline void moveBottomRight(const PointF &point) { moveBottom(point.y()); moveRight(point.x()); }
    inline void moveCenter(const PointF &point) { m_x = point.x() - m_w / 2; m_y = point.y() - m_h / 2; }

    inline bool contains(float x, float y) const { return x >= m_x && x <= m_x + m_w && y >= m_y && y <= m_y + m_h; }
    inline bool contains(const PointF &point) const { return contains(point.x(), point.y()); }
    inline void inflate(SizeF &size) { inflate(size.width(), size.height()); }
    //inline void inflate(RectangleF &rect) { inflate(rect.size()); }

    bool contains(const RectangleF &rect) const;
    void inflate(float width, float height);

    static RectangleF intersects(const RectangleF &rect1, const RectangleF &rect2);
    static RectangleF unions(const RectangleF &rect1, const RectangleF &rect2);

    RectangleF &operator=(const RectangleF &rect);
    //RectangleF operator&(RectangleF &rect1, RectangleF &rect2) { return intersects(rect1, rect2); }
    //RectangleF operator|(const RectangleF &rect1, const RectangleF &rect2) { return unions(rect1, rect2); }

    friend bool operator==(const RectangleF &rect1, const RectangleF &rect2);
    friend bool operator!=(const RectangleF &rect1, const RectangleF &rect2);

private:
    float m_x, m_y, m_w, m_h;
};


#endif // RECTANGLE_H 
