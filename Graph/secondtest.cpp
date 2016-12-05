#include <TXLib.h>
#include "APLib.h"

struct Points
{
    double x, y;
    COLORREF color;
    const int k;
};

int p1 = 300, p2 = 300;
const int g = 10;
int vx = 5, vy = 5;
int x = 50, y = 100;

Points p = {100, 0, 0, 1};

typedef double Tip (Points p, bool COP);
typedef void f(int x, int y);
void Draw(int x, int y);
void Print(f* func, int p1, int p2);
void Count(Tip* func);
double Res(Points p, bool COP);

int main()
{
    txCreateWindow(800, 600);

    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        Count(Res);

        Print(Draw, p1, p2);
    }

    return 0;
}

double Res(Points p, bool COP)
{
    if(COP == true) return p.y = 2 * p.x;

    else return p.color = RGB(random(256), random(256), random(256));
}

void Count(Tip* func)
{
    p.color = func(p, false);
    p.y = func(p, true);

    txSetColor(p.color);
    txSetFillColor(p.color);

    x += vx * g;
    y += vy * g;

    if(x <= 0)
    {
        x = 0;

        vx = -vx;
    }

    if(x >= 800)
    {
        x = 800;

        vx = -vx;
    }

    if(y <= 0)
    {
        y = 0;

        vy = -vy;
    }

    if(y >= 800)
    {
        y = 800;

        vy = -vy;
    }

    if(GetAsyncKeyState(VK_UP)) vx += 10;

    txSetFillColor(TX_BLACK);
    txClear();

    txSetFillColor(p.color);
    txCircle(x, y, 10);

    txSleep(100);
}

void Draw(int x, int y)
{
    COLORREF color = RGB(random(256), random(256), random(256));
    COLORREF color2 = RGB(random(256), random(256), random(256));

    txSetColor(color, random(100));
    txSetFillColor(color);

    txRectangle(x, y, x + 50, y + 50);
    //txLine(random(800), random(600), random(800), random(600));

    //txCreateWindow(800, 300);

    for(int i = 0; i < 10; i++) txSetPixel(random(800), random(600), color);
}

void Print(f* func, int p1, int p2)
{
    func(p1, p2);

    p1 = random(800), p2 = random(600);

    if(p1 < 500 && p2 < 300) Print(Draw, p1, p2);
}
