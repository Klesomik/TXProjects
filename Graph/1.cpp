#include <TXLib.h>
#include "Draw.h"
#include "Write.h"
#include "Graphics.h"

//--------------------------------------------------------------------------------------------

struct Push
{
    int xMin, xMax, yMin, yMax, mode;
};

struct Hoope
{
    int x, y, mode;
};

//--------------------------------------------------------------------------------------------

void DrawWindow (int* zoom, Draw draw, Write write);
void DrawGraphics (int* zoom, Draw darw, Write write, Timeline timeline, Hoope* t);
void Zoom (int* zoom, Draw draw, Write write, Hoope* t);
void Scaner(Hoope* t);
void MainWhile (int* zoom, Draw draw, Write write, Timeline timeline, Hoope* t);

//--------------------------------------------------------------------------------------------

int main()
{
    txCreateWindow (x_size, y_size);

    Draw draw;

    Write write;

    Timeline timeline;

    Hoope t;

    int zoom = 1;

    txTextCursor (false);

    MainWhile (&zoom, draw, write, timeline, &t);

    return 0;
}

//--------------------------------------------------------------------------------------------

void MainWhile (int* zoom, Draw draw, Write write, Timeline timeline, Hoope* t)
{
    DrawWindow (zoom, draw, write);

    while (!GetAsyncKeyState (VK_ESCAPE))
    {
        Scaner(t);

        DrawGraphics (zoom, draw, write, timeline, t);

        Zoom (zoom, draw, write, t);

        draw.DrawPush ();
    }
}

//--------------------------------------------------------------------------------------------

void DrawWindow(int* zoom, Draw draw, Write write)
{
    draw.ClearWindow();

    draw.DrawWeb(zoom);

    draw.DrawGraph(zoom);

    draw.DrawPush();

    write.Digit_x(zoom);
    write.Digit_y(zoom);

    write.Numbers();
}

//--------------------------------------------------------------------------------------------

void Scaner(Hoope* t)
{
    t -> x = txMouseX();
    t -> y = txMouseY();
    t -> mode = txMouseButtons();
}

//--------------------------------------------------------------------------------------------

void DrawGraphics(int* zoom, Draw draw, Write write, Timeline timeline, Hoope* t)
{
    Push p = {0, 0, 0, 568, 618};

    if ((GetAsyncKeyState (VK_F1)) || (((t -> x >= p.xMin +  80) && (t -> x <= p.xMax + 130)) && ((t -> y >= p.yMin + 568) &&  (t -> y <= p.yMax + 618)) && (t -> mode))) timeline.Parabola(zoom);

    if ((GetAsyncKeyState (VK_F2)) || (((t -> x >= p.xMin + 135) && (t -> x <= p.xMax + 187)) && ((t -> y >= p.yMin + 568) &&  (t -> y <= p.xMax + 618)) && (t -> mode))) timeline.CubParabola(zoom);

    if (GetAsyncKeyState (VK_F3)) timeline.Change(zoom);

    if (GetAsyncKeyState (VK_F4)) timeline.ChangePlus(zoom);

    if (GetAsyncKeyState (VK_F5)) timeline.ParabolaPlus(zoom);

    if (GetAsyncKeyState (VK_F7)) DrawWindow(zoom, draw, write);

    if ((GetAsyncKeyState  ('Z')) || (((t -> x >= p.xMin +  25) && (t -> x <= p.xMax +  75)) && ((t -> y >= p.yMin + 568) && (t -> y <= p.yMax + 618)) && (t -> mode))) timeline.Straight();

    if ((GetAsyncKeyState  ('X')) || (((t -> x >= p.xMin + 190) && (t -> x <= p.xMax + 242)) && ((t -> y >= p.yMin + 568) && (t -> y <= p.yMax + 618)) && (t -> mode))) timeline.Sqrt(zoom);

    if ((GetAsyncKeyState  ('C')) || (((t -> x >= p.xMin + 245) && (t -> x <= p.xMax + 297)) && ((t -> y >= p.yMin + 568) && (t -> y <= p.yMax + 618)) && (t -> mode))) timeline.Giper(zoom);

    if ((GetAsyncKeyState  ('V')) || (((t -> x >= p.xMin + 350) && (t -> x <= p.xMax + 402)) && ((t -> y >= p.yMin + 568) && (t -> y <= p.yMax + 618)) && (t -> mode))) timeline.Sin(zoom);

    if ((GetAsyncKeyState  ('B')) || (((t -> x >= p.xMin + 405) && (t -> x <= p.xMax + 457)) && ((t -> y >= p.yMin + 568) && (t -> y <= p.yMax + 618)) && (t -> mode))) timeline.Cos(zoom);

    if ((GetAsyncKeyState  ('N')) || (((t -> x >= p.xMin + 460) && (t -> x <= p.xMax + 512)) && ((t -> y >= p.yMin + 568) && (t -> y <= p.yMax + 618)) && (t -> mode))) timeline.Tan(zoom);

    if ((GetAsyncKeyState  ('M')) || (((t -> x >= p.xMin + 515) && (t -> x <= p.xMax + 567)) && ((t -> y >= p.yMin + 568) && (t -> y <= p.yMax + 618)) && (t -> mode))) timeline.CTan(zoom);
}

//--------------------------------------------------------------------------------------------

void Zoom(int* zoom, Draw draw, Write write, Hoope* t)
{
    if (((GetAsyncKeyState (VK_UP)) && ((*zoom) < 4)) || ((t -> x >= 30 && t -> x <= 80) && (t -> y >= 5 && t -> y <= 55) && (t -> mode) && ((*zoom) < 4)))
    {
        (*zoom) *= 2;

        DrawWindow(zoom, draw, write);

        txSleep(100);
    }

    if (((GetAsyncKeyState (VK_DOWN)) && ((*zoom) > 1))|| ((t -> x >= 85 && t -> x <= 135) && (t -> y >= 5 && t -> y <= 55) && (t -> mode) && ((*zoom) > 1)))
    {
        (*zoom) /= 2;

        DrawWindow(zoom, draw, write);
