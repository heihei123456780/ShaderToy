#include "size.h"

/*void Size::scale(float xfactor, float yfactor)
{ 
    m_w *= xfactor; 
    m_h *= yfactor; 
}*/

inline Size &Size::operator=(const Size &size)
{
    m_w = size.m_w;
    m_h = size.m_h;
    return *this;
}

inline Size &Size::operator+=(const Size &size)
{
    m_w += size.m_w;
    m_h += size.m_h;
    return *this;
}

inline Size &Size::operator-=(const Size &size)
{
    m_w -= size.m_w;
    m_h -= size.m_h;
    return *this;
}

inline bool operator==(const Size &s1, const Size &s2)
{ 
    return (s1.m_w == s2.m_w && s1.m_h == s2.m_h); 
}

inline bool operator!=(const Size &s1, const Size &s2)
{ 
    return (s1.m_w != s2.m_w || s1.m_h != s2.m_h); 
}

inline Size operator+(const Size &s1, const Size &s2)
{ 
    return Size(s1.m_w + s2.m_w, s1.m_h + s2.m_h); 
}

inline Size operator-(const Size &s1, const Size &s2)
{ 
    return Size(s1.m_w - s2.m_w, s2.m_h - s2.m_h); 
}
