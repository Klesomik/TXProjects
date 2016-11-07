#include "TXLib.h"

struct CBall
    {
        double x, y;
        double vx, vy;
        double r;
        COLORREF color, new_color;
    };

double Distance (CBall* b, CBall* b2);
void PlayBall ();
void ControlBall (CBall* b, int left, int right, int up, int down);
void DrawBall (CBall b);
void MoveBall (CBall* b, double dt);
void ChangeColor (CBall* b);

int main()
{
    txCreateWindow (800, 600);

    PlayBall ();

    return 0;
}

void PlayBall ()
{
    CBall b  = {100, 200, 1, 1, 10, TX_GREEN, TX_WHITE};

    CBall b2 = {200, 200, 1, 1, 15, TX_RED, TX_ORANGE};

    CBall b3 = {300, 400, 1, 1, 20, TX_YELLOW, TX_BLUE};

    double dt = 1;
    txBegin();
    while (!GetAsyncKeyState (VK_ESCAPE))
    {
        txSetFillColor (TX_BLACK);
        txClear ();

        DrawBall (b);
        DrawBall (b2);
        DrawBall (b3);

        double d09 = Distance (&b,  &b2);
        double d10 = Distance (&b,  &b3);
        double d11 = Distance (&b2, &b3);

        if (d09 <=  b.r + b2.r) break;
        if (d10 <=  b.r + b3.r) break;
        if (d11 <= b2.r + b3.r) break;

        ControlBall (&b, VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN);
        ControlBall (&b2, 'A', 'D', 'W', 'S');
        ControlBall (&b3, 'F', 'H', 'T', 'G');

        MoveBall (&b,  dt);
        MoveBall (&b2, dt);
        MoveBall (&b3, dt);

        txSleep (1);
    }
    txBegin();

}

void DrawBall (CBall b)
{
    txSetColor (b.color, 5);
    txSetFillColor (b.color);
    txCircle (b.x, b.y, b.r);
}

void ControlBall (CBall* b, int left, int right, int up, int down)
{
    int up_speed = 1;

    if (GetAsyncKeyState (VK_SHIFT)) up_speed = 10;

    if (GetAsyncKeyState (left))  b -> vx -= up_speed;
    if (GetAsyncKeyState (right)) b -> vx += up_speed;
    if (GetAsyncKeyState (up))    b -> vy -= up_speed;
    if (GetAsyncKeyState (down))  b -> vy += up_speed;
}

void MoveBall (CBall* b, double dt)
{
    b -> x += b -> vx * dt;
    b -> y += b -> vy * dt;

    if (b -> x > 800 - b -> r)
    {
        ChangeColor (b);

        b -> vx = - b -> vx;
        b -> x = 800 - b -> r;
    }

    if (b -> y > 600 - b -> r)
    {
        ChangeColor (b);

        b -> vy = - b -> vy;
        b -> y = 600 - b -> r;
    }

    if (b -> x < b -> r)
    {
        ChangeColor (b);

        b -> vx = - b -> vx;
        b -> x = b -> r;
    }

    if (b -> y < b -> r)
    {
        ChangeColor (b);

        b -> vy = - b -> vy;
        b -> y = b -> r;
    }
}

double Distance (CBall* b, CBall* b2)
{
    double dist = sqrt((b -> x - b2 -> x) * (b -> x - b2 -> x) + (b -> y - b2 -> y) * (b -> y - b2 -> y));
    double d12 = dist;

    if (d12 <= b -> r + b2 -> r)
    {
        txSetColor (TX_RED, 5);
        txSetFillColor (TX_RED);
        txRectangle (b -> x - 50, b -> y - 50, b2 -> x + 50, b2 -> y + 50);
        printf ("The End.");
    }

    return d12;
}

void ChangeColor (CBall* b)
{
    COLORREF t = b -> color;
    b -> color = b -> new_color;
    b -> new_color = t;
}
