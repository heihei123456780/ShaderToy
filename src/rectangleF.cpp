#include "g_math.h"
#include "rectangleF.h"

void RectangleF::setTop(float pos)
{
    float diff = pos - m_y;
    m_y += diff;
    m_h -= diff;
}

void RectangleF::setLeft(float pos)
{
    float diff = pos - m_x;
    m_x += diff;
    m_w -= diff; 
}

void RectangleF::setCenter(const PointF &point)
{
    m_x = point.x() - (m_w / 2);
    m_y = point.y() - (m_h / 2);
}

void RectangleF::setRectangle(const RectangleF &rect)
{
    m_x = rect.m_x;
    m_y = rect.m_y;
    m_w = rect.m_w;
    m_h = rect.m_h;
}

void RectangleF::setRectangle(float x, float y, float w, float h)
{
    m_x = x;
    m_y = y;
    m_w = w;
    m_h = h;
}

bool RectangleF::contains(const RectangleF &rect) const
{
    return m_x <= rect.m_x && m_x + m_w >= rect.m_x + rect.m_w &&
           m_y <= rect.m_y && m_y + m_h >= rect.m_y + rect.m_h;
}

void RectangleF::inflate(float width, float height)
{
    m_x -= width;
    m_y -= height;
    m_w += 2.0f * width;
    m_h += 2.0f * height;
}

RectangleF RectangleF::intersects(const RectangleF &rect1, const RectangleF &rect2)
{
    int x1 = Math::max(rect1.m_x, rect2.m_x);
    int x2 = Math::min(rect1.m_x + rect1.m_w, rect2.m_x + rect2.m_w);
    int y1 = Math::max(rect1.m_y, rect2.m_y);
    int y2 = Math::min(rect1.m_y + rect1.m_h, rect2.m_y + rect2.m_h);

    if (x2 >= x1 && y2 >= y1)
        return RectangleF(x1, y1, x2 - x1, y2 - y1);
    else 
        return RectangleF(0.0f, 0.0f, 0.0f, 0.0f);
}

RectangleF RectangleF::unions(const RectangleF &rect1, const RectangleF &rect2)
{
    int x1 = Math::min(rect1.m_x, rect2.m_x);
    int x2 = Math::max(rect1.m_x + rect1.m_w, rect2.m_x + rect2.m_w);
    int y1 = Math::min(rect1.m_y, rect2.m_y);
    int y2 = Math::max(rect1.m_y + rect1.m_h, rect2.m_y + rect2.m_h);

    if (x2 >= x1 && y2 >= y1)
        return RectangleF(x1, y1, x2 - x1, y2 - y1);
    else 
        return RectangleF(0.0f, 0.0f, 0.0f, 0.0f);
}

RectangleF &RectangleF::operator=(const RectangleF &rect)
{
    m_x = rect.m_x;
    m_y = rect.m_y;
    m_w = rect.m_w;
    m_h = rect.m_h;
    return *this;
}

bool operator==(const RectangleF &rect1, const RectangleF &rect2)
{
    return (rect1.m_x == rect2.m_x &&
            rect1.m_y == rect2.m_y &&
            rect1.m_w == rect2.m_w &&
            rect1.m_h == rect2.m_h);
}

bool operator!=(const RectangleF &rect1, const RectangleF &rect2)
{
    return (rect1.m_x != rect2.m_x ||
            rect1.m_y != rect2.m_y ||
            rect1.m_w != rect2.m_w ||
            rect1.m_h != rect2.m_h);
}
