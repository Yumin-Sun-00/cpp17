class E
{
    int m_x, m_y;
    mutable int var = 0;
public:

    int getX() const
    {
        var++;
        return m_x;
    }

    int getX()
    {
        return m_x;
    }

    void setX(int x)
    {
        m_x = x;
    }
};


