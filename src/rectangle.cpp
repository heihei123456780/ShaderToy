#include "g_math.h"
#include "rectangle.h"

void Rectangle::setCenter(const Point &point)
{
    int w = width();
    int h = height();
    m_t = point.y() - Math::round(h / 2);
    m_b = point.y() + Math::round(h / 2);
    m_l = point.x() - Math::round(w / 2);
    m_r = point.x() + Math::round(w / 2);
}

void Rectangle::setRectangle(const Rectangle &rect)
{
    m_t = rect.m_t;
    m_b = rect.m_b;
    m_l = rect.m_l;
    m_r = rect.m_r;
}

void Rectangle::setRectangle(int top, int bottom, int left, int right)
{
    m_t = top;
    m_b = bottom;
    m_l = left;
    m_r = right;
}

void Rectangle::moveTo(int dx, int dy)
{
    m_r += dx - m_l;
    m_b += dy - m_t;
    m_l = dx;
    m_t = dy;
}

void Rectangle::moveTo(const Point &point)
{
    m_r += point.x() - m_l;
    m_b += point.y() - m_t;
    m_l = point.x();
    m_t = point.y();
}

void Rectangle::moveCenter(const Point &point)
{
    int w = m_r - m_l;
    int h = m_b - m_t;
    m_l = point.x() - w / 2;
    m_t = point.y() - h / 2;
    m_r = m_l + w;
    m_b = m_t + h;
}

bool Rectangle::contains(const Rectangle &rect) const
{
    return (m_t <= rect.m_t && m_b >= rect.m_b &&
            m_l <= rect.m_l && m_r >= rect.m_r); 
}

void Rectangle::inflate(int width, int height)
{
    m_l -= width;
    m_t -= height;
    m_r += width;
    m_b += height;
}

Rectangle Rectangle::intersects(const Rectangle &rect1, const Rectangle &rect2)
{
    int l = Math::max(rect1.m_l, rect2.m_l);
    int r = Math::min(rect1.m_r, rect2.m_r);
    int t = Math::max(rect1.m_t, rect2.m_t);
    int b = Math::min(rect1.m_b, rect2.m_b);

    if (r >= l  && b >= t)
        return Rectangle(t, b, l, r);
    else 
        return Rectangle(0, 0, 0, 0);
}

Rectangle Rectangle::unions(const Rectangle &rect1, const Rectangle &rect2)
{
    int l = Math::min(rect1.m_l, rect2.m_l);
    int r = Math::max(rect1.m_b, rect2.m_b);
    int t = Math::min(rect1.m_t, rect2.m_t);
    int b = Math::max(rect2.m_b, rect2.m_b);

    return Rectangle(t, b, l, r);
}

Rectangle &Rectangle::operator=(const Rectangle &r)
{
    m_t = r.m_t;
    m_b = r.m_b;
    m_l = r.m_l;
    m_r = r.m_r;
    return *this;
}

bool operator==(const Rectangle &r1, const Rectangle &r2)
{
    return (r1.m_t == r2.m_t &&
            r1.m_b == r2.m_b &&
            r1.m_l == r2.m_l &&
            r1.m_r == r2.m_r);
}

bool operator!=(const Rectangle &r1, const Rectangle &r2)
{
    return (r1.m_t != r2.m_t ||
            r1.m_b != r2.m_b ||
            r1.m_l != r2.m_l ||
            r1.m_r != r2.m_r);
}

