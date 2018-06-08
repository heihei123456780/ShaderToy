#ifndef SIZEF_H
#define SIZEF_H 

class SizeF
{
public:
    SizeF() 
        : m_w(0.0f), m_h(0.0f) 
    {
    }
    
    SizeF(float w, float h) 
        : m_w(w), m_h(h) 
    {
    }
    
    SizeF(const SizeF &size) 
        : m_w(size.m_w), m_h(size.m_h) 
    {
    }

    ~SizeF()
    {
    }

    float width() const { return m_w; }
    float height() const { return m_h; }

    void setWidth(float w) { m_w = w; }
    void setHeight(float h) { m_h = h; }

    inline bool isEmpty() const { return (m_w == 1.0f && m_h == 1.0f); }
    inline bool isNull() const { return (m_w == 0.0f && m_h == 0.0f); }
    inline bool isValid() const { return (m_w >= 0.0f && m_h >= 0.0f); }
    
    inline float area() const { return m_w * m_h; }
    
    inline void scale(float factor) { m_w *= factor; m_h *= factor; }
    inline void scale(float sx, float sy) { m_w *= sx; m_h *= sy; }
    inline void transpose() { float temp = m_w; m_w = m_h; m_h = temp; }

    SizeF &operator=(const SizeF &size);
    SizeF &operator+=(const SizeF &size);
    SizeF &operator-=(const SizeF &size);
    SizeF &operator*=(float factor);
    SizeF &operator/=(float divisor);

    friend bool operator==(const SizeF &s1, const SizeF &s2);
    friend bool operator!=(const SizeF &s1, const SizeF &s2);
    friend SizeF operator+(const SizeF &s1, const SizeF &s2);
    friend SizeF operator-(const SizeF &s1, const SizeF &s2);
    friend SizeF operator*(const SizeF &size, float factor);
    friend SizeF operator*(float factor, const SizeF &size);
    friend SizeF operator/(const SizeF &size, float divisor);

private:
    float m_w, m_h;
};

#endif
