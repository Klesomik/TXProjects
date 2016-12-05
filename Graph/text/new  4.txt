#include <TXLib.h>

//--------------------------------------------------------------------------------------------

class Timeline
{
    private:

    struct Points
    {
        double x, y;
        COLORREF color;
    };

    public:

    Timeline() {}
    ~Timeline() {}
    void Straight();
    void Parabola(int* zoom);
    void CubParabola(int* zoom);
    void Sqrt(int* zoom);
    void Giper(int* zoom);
    void Sin(int* zoom);
    void Cos(int* zoom);
    void Tan(int* zoom);
    void CTan(int* zoom);
    void ParabolaPlus(int* zoom);
    void Change(int* zoom);
    void ChangePlus(int* zoom);
};

//--------------------------------------------------------------------------------------------

void Timeline::Straight()
{
    Points p = {-20, 0, TX_BLACK};

    txSetColor(p.color);
    txSetFillColor(p.color);

    const int k = 1;

    for (p.x = -20; p.x <= +20; p.x += 0.01)
    {
        if (fabs(p.x) <= 0.001) continue;

        p.y = -(k * p.x);

        txCircle(p.x * 25 + x_size / 2, p.y * 25 + y_size / 2, 3);
    }
}

//--------------------------------------------------------------------------------------------

void Timeline::Parabola(int* zoom)
{
    Points p = {-20, 0, TX_RED};

    txSetColor(p.color);
    txSetFillColor(p.color);

    for (p.x = -20; p.x <= +20; p.x += 0.01)
    {
        if (fabs(p.x) <= 0.001) continue;

        p.y = -(p.x * p.x);

        txCircle(p.x * (*zoom) * 25 + x_size / 2, p.y * (*zoom) * 25 + y_size / 2, 3);
    }
}

//--------------------------------------------------------------------------------------------

void Timeline::CubParabola(int* zoom)
{
    Points p = {-20, 0, TX_BLUE};

    txSetColor(p.color);
    txSetFillColor(p.color);

    for (p.x = -20; p.x <= +20; p.x += 0.01)
    {
        if (fabs(p.x) <= 0.001) continue;

        p.y = -(p.x * p.x * p.x);

        txCircle(p.x * (*zoom) * 25 + x_size / 2, p.y * (*zoom) * 25 + y_size / 2, 3);
    }
}

//--------------------------------------------------------------------------------------------

void Timeline::Sqrt(int* zoom)
{
    Points p = {0, 0, TX_ORANGE};

    txSetColor(p.color);
    txSetFillColor(p.color);

    for (p.x = 0; p.x <= 20; p.x += 0.01)
    {
        if (fabs(p.x) <= 0.001) continue;

        p.y = -(sqrt(p.x));

        txCircle(p.x * (*zoom) * 25 + x_size / 2, p.y * (*zoom) * 25 + y_size / 2, 3);
    }
}

//--------------------------------------------------------------------------------------------

void Timeline::Giper(int* zoom)
{
    Points p = {-20, 0, TX_LIGHTGREEN};

    txSetColor(p.color);
    txSetFillColor(p.color);

    const int k = 1;

    for (p.x = -20; p.x <= +20; p.x += 0.01)
    {
        if (fabs(p.x) <= 0.001) continue;

        p.y = -(k / p.x);

        txCircle(p.x * (*zoom) * 25 + x_size / 2, p.y * (*zoom) * 25 + y_size / 2, 3);
    }
}

//--------------------------------------------------------------------------------------------

void Timeline::Sin(int* zoom)
{
    Points p = {-20, 0, TX_LIGHTBLUE};

    txSetColor(p.color);
    txSetFillColor(p.color);

    for (p.x = -20; p.x <= +20; p.x += 0.01)
    {
        if (fabs(p.x) <= 0.001) continue;

        p.y = -(sin(p.x));

        txCircle(p.x * (*zoom) * 25 + x_size / 2, p.y * (*zoom) * 25 + y_size / 2, 3);
    }
}

//--------------------------------------------------------------------------------------------

void Timeline::Cos(int* zoom)
{
    Points p = {-20, 0, TX_YELLOW};

    txSetColor(p.color);
    txSetFillColor(p.color);

    for (p.x = -20; p.x <= +20; p.x += 0.01)
    {
        if (fabs(p.x) <= 0.001) continue;

        p.y = -(cos(p.x));

        txCircle(p.x * (*zoom) * 25 + x_size / 2, p.y * (*zoom) * 25 + y_size / 2, 3);
    }
}

//--------------------------------------------------------------------------------------------

void Timeline::Tan(int* zoom)
{
    Points p = {-20, 0, TX_PINK};

    txSetColor(p.color);
    txSetFillColor(p.color);

    for (p.x = -20; p.x <= +20; p.x += 0.01)
    {
        if (fabs(p.x) <= 0.001) continue;

        p.y = -(tan(p.x));

        txCircle(p.x * (*zoom) * 25 + x_size / 2, p.y * (*zoom) * 25 + y_size / 2, 3);
    }
}

//--------------------------------------------------------------------------------------------

void Timeline::CTan(int* zoom)
{
    Points p = {-20, 0, TX_LIGHTCYAN};

    txSetColor(p.color);
    txSetFillColor(p.color);

    for (p.x = -20; p.x <= +20; p.x += 0.01)
    {
        if (fabs(p.x) <= 0.001) continue;

        p.y = -(1 / tan(p.x));

        txCircle(p.x * (*zoom) * 25 + x_size / 2, p.y * (*zoom) * 25 + y_size / 2, 3);
    }
}

//--------------------------------------------------------------------------------------------

void Timeline::ParabolaPlus(int* zoom)
{
    Points p = {-20, 0, TX_GREEN};

    txSetColor(p.color);
    txSetFillColor(p.color);

    for (p.x = -20; p.x <= +20; p.x += 0.01)
    {
        if (fabs(p.x) <= 0.001) continue;

        p.y = -((p.x + 5) * (p.x + 5));

        txCircle(p.x * (*zoom) * 25 + x_size / 2, p.y * (*zoom) * 25 + y_size / 2, 3);
    }
}

//--------------------------------------------------------------------------------------------

void Timeline::Change(int* zoom)
{
    Points p = {-20, 0, TX_PINK};

    txSetColor(p.color);
    txSetFillColor(p.color);

    for (p.x = -20; p.x <= +20; p.x += 0.01)
    {
        if (fabs(p.x) <= 0.001) continue;

        for (int k = -10; k <= +10; k++)
        {
            p.y = -(k * p.x);

            txCircle(p.x * (*zoom) * 25 + x_size / 2, p.y * (*zoom) * 25 + y_size / 2, 3);
        }
    }
}

//--------------------------------------------------------------------------------------------

void Timeline::ChangePlus(int* zoom)
{
    Points p = {-20, 0, TX_WHITE};

    txSetColor(p.color);
    txSetFillColor(p.color);

    for (p.x = -20; p.x <= +20; p.x += 0.01)
    {
        if (fabs(p.x) <= 0.001) continue;

        for (int k = -10; k <= +10; k++)
        {
            p.y = -(k * p.x * p.x);

            txCircle(p.x * (*zoom) * 25 + x_size / 2, p.y * (*zoom) * 25 + y_size / 2, 3);
        }
    }
}
