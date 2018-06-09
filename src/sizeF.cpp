#include "sizeF.h"

SizeF &SizeF::operator=(const SizeF &size)
{
    m_w = size.m_w;
    m_h = size.m_h;
    return *this;
}

SizeF &SizeF::operator+=(const SizeF &size)
{
    m_w += size.m_w;
    m_h += size.m_h;
    return *this;
}

SizeF &SizeF::operator-=(const SizeF &size)
{
    m_w -= size.m_w;
    m_h -= size.m_h;
    return *this;
}

SizeF &SizeF::operator*=(float factor)
{
    m_w *= factor;
    m_h *= factor;
    return *this;
}

SizeF &SizeF::operator/=(float divisor)
{
    m_w /= divisor;
    m_h /= divisor;
    return *this;
}

bool operator==(const SizeF &s1, const SizeF &s2)
{ 
    return (s1.m_w == s2.m_w && s1.m_h == s2.m_h); 
}

bool operator!=(const SizeF &s1, const SizeF &s2)
{ 
    return (s1.m_w != s2.m_w || s1.m_h != s2.m_h); 
}

SizeF operator+(const SizeF &s1, const SizeF &s2)
{ 
    return SizeF(s1.m_w + s2.m_w, s1.m_h + s2.m_h); 
}

SizeF operator-(const SizeF &s1, const SizeF &s2)
{ 
    return SizeF(s1.m_w - s2.m_w, s2.m_h - s2.m_h); 
}

SizeF operator*(const SizeF &size, float factor)
{ 
    return SizeF(size.m_w * factor, size.m_h * factor); 
}

SizeF operator*(float factor, const SizeF &size)
{ 
    return SizeF(size.m_w * factor, size.m_h * factor); 
}

SizeF operator/(const SizeF &size, float divisor)
{ 
    return SizeF(size.m_w / divisor, size.m_h / divisor); 
}
