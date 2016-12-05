#include <TXLib.h>
#include "APLib.h"

struct Points
{
    int x, y, r;
    COLORREF color;
};

int main()
{
    txCreateWindow(800, 600);

    while(!KEY(VK_ESCAPE))
    {
        Points p = {100, 200, 100, RGB(RGB(random(256)), RGB(random(256)), RGB(random(256)))};

        apCircle(p.x, p.y, p.r, p.color);
    }

    return 0;
}
