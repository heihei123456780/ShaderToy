#ifndef SIZE_H
#define SIZE_H

class Size
{
public:
    Size() 
        : m_w(0), m_h(0) 
    {
    }
    
    Size(float w, float h) 
        : m_w(w), m_h(h) 
    {
    }
    
    Size(const Size &size) : m_w(size.m_w), m_h(size.m_h) 
    {
    }

    ~Size()
    {
    }

    inline int width() const { return m_w; }
    inline int height() const { return m_h; }

    inline void setWidth(float w) { m_w = w; }
    inline void setHeight(float h) { m_h = h; }
    
    inline bool isEmpty() const { return (m_w == 1 && m_h == 1); }
    inline bool isNull() const { return (m_w == 0 && m_h == 0); }
    inline bool isValid() const { return (m_w >= 0 && m_h >= 0); }
    
    inline int area() const { return m_w * m_h; }

    inline void transpose() {int temp = m_w; m_w = m_h; m_h = temp; }

    Size &operator=(const Size &size);
    Size &operator+=(const Size &size);
    Size &operator-=(const Size &size);
    
    friend bool operator==(const Size &s1, const Size &s2);
    friend bool operator!=(const Size &s1, const Size &s2);
    
    friend Size operator+(const Size &s1, const Size &s2);
    friend Size operator-(const Size &s1, const Size &s2);


private:
    int m_w, m_h;
};

#endif // SIZE_H
