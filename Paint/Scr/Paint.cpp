#include "..//..//TXLib.h"

void MainWhile ();
void WhileCompany ();
void WhilePresents ();
void WhileMenu ();
void WhileInstructions ();
void DrawInstructions ();
void DrawMenu ();
void Paint ();
void DrawSubtitles (const char text[]);
void DrawMan (int x_Man, int y_Man, int r_Man, int s_Man, int speed_Man);
void DrawHouse (int x_House, int y_House, int s_House, int speed_House);
void DrawSnowMen (int x_SnowMen, int y_SnowMen, int r_SnowMen, int s_SnowMen, int speed_SnowMen);
void DrawCar (int x_Car, int y_Car, int r_Car, int s_Car, int speed_Car);
void DrawTree (int x_Tree, int y_Tree, int s_Tree, int speed_Tree);
void DrawSun (int x_Sun, int y_Sun, int r_Sun, int s_Sun, int speed_Sun);

int main()
{

int x_Man = 100, y_Man = 100, r_Man = 100, s_Man = 0, speed_Man = 10;
int x_House = 100, y_House = 100, s_House = 0, speed_House = 10;
int x_SnowMen = 100, y_SnowMen = 100, r_SnowMen = 100, s_SnowMen = 0, speed_SnowMen = 10;
int x_Car = 100, y_Car = 100, r_Car = 100, s_Car = 0, speed_Car = 10;
int x_Tree = 100, y_Tree = 100, s_Tree = 0, speed_Tree = 10;
int x_Sun = 100, y_Sun = 100, r_Sun = 100, s_Sun = 0, speed_Sun = 10;
int x_Window = 800, y_Window = 700;
txCreateWindow (x_Window, y_Window);
txPlaySound ("Music//Sound1 (Harlem shake).wav", SND_LOOP);
WhileCompany ();
WhilePresents ();
WhileMenu ();
return 0;
}

void MainWhile ()
{
txClear ();
txSetColor (TX_WHITE);
txSelectFont ("Times New Roman", 19);
txTextOut (350, 25, "����� ������");
txTextOut (50, 100, "Z - �������, X - �������, C - ������, V - �����, B - �����, N - �������, M - ���� - �������");
txTextOut (50, 200, "A - �����-�����, S - ���������, D - ���������, F - ���������, G - ������ , H - �����, J - �������");
txTextOut (50, 300, "K - ���� - ���������, L - ���� - �������, Q - ������ - �������");
txSleep (5000);
txClear ();
txSetColor (TX_NULL);

while (!GetAsyncKeyState (VK_ESCAPE))
    {

    if (GetAsyncKeyState ('1')) {txPlaySound (NULL, SND_LOOP); txPlaySound ("Music//Sound1 (Harlem shake).wav", SND_LOOP);}

    if (GetAsyncKeyState ('2')) {txPlaySound (NULL, SND_LOOP); txPlaySound ("Music//Sound2 (Du hast).wav", SND_LOOP);}

    if (GetAsyncKeyState (VK_F7))
    {
        txSetFillColor (TX_BLACK);
        txClear();
        COLORREF oldColor = txGetColor ();
        txSetFillColor (oldColor);
        txSetColor (oldColor, 5);
    }

    if (GetAsyncKeyState (VK_F1)) DrawMan (100, 100, 100, 0, 10);

    if (GetAsyncKeyState (VK_F2)) DrawHouse (100, 100, 0, 10);

    if (GetAsyncKeyState (VK_F4)) DrawSnowMen (100, 100, 100, 0, 10);

    if (GetAsyncKeyState (VK_F5)) DrawCar (100, 100, 100, 0, 10);

    if (GetAsyncKeyState (VK_F3)) DrawTree (100, 100, 0, 10);

    if (GetAsyncKeyState (VK_F6)) DrawSun (100, 100, 100, 0, 10);

    Paint ();

    }
}

void WhileCompany ()
{

for (int b = 200; b >= 0; b--)
{
    txSetFillColor (TX_BLACK);
    txClear();

    txSetColor (TX_GREEN, 5);
    txLine (25 + b, 175, 25 - b, 350);
    txLine (25, 175 - b, 50, 175 + b);
    txLine (50 + b, 175, 50, 250);
    txLine (50, 250, 100 + b, 175 - b);
    txLine (100 + b, 175, 100, 212.5 + b * 2);
    txLine (100, 212.5 + b, 62.5, 275);
    txLine (62.5 + b, 275 - b, 100, 350 + b * 2);
    txLine (100 - b * 2, 350 - b, 75, 350 + b);
    txLine (75, 350 + b * 2, 50 - b, 300);
    txLine (50 + b, 300, 50 - b, 350 + b);
    txLine (50, 350 - b, 25, 350);
    txLine (25 + b, 350 - b, 25, 175 + b);

    txSetColor (TX_RED, 5);
    txLine (125, 175, 125 - b, 350);
    txLine (125 + b, 350 + b, 200, 350);
    txLine (200, 350, 200 + b, 325 - b * 2);
    txLine (200 + b, 325, 150, 325);
    txLine (150, 325 + b * 2, 150 - b, 175);
    txLine (150, 175 - b, 125, 175 + b);

    txSetColor (TX_ORANGE, 5);
    txLine (225 + b, 175, 225 - b, 350);
    txLine (225 - b, 350 + b, 300, 350);
    txLine (300, 350 - b, 300 - b, 325 + b);
    txLine (300 + b, 325 - b, 250 + b * 2, 325);
    txLine (250, 325, 250 - b, 275 - b);
    txLine (250 - b, 275 + b * 2, 275 + b, 275);
    txLine (275 + b, 275, 275 + b, 250 + b);
    txLine (275, 250 + b, 250, 250);
    txLine (250 + b * 2, 250, 250, 200 + b);
    txLine (250 + b * 2, 200 + b, 300, 200);
    txLine (300, 200, 300, 175);
    txLine (300 + b * 2, 175 + b, 225, 175);

    txSetColor (TX_YELLOW, 5);
    txLine (325 + b, 175 - b, 325, 275);
    txLine (325 + b * 2, 275 + b, 375, 275);
    txLine (375, 275 - b, 375 + b, 325 + b * 2);
    txLine (375, 325, 325 - b, 325 + b);
    txLine (325 + b * 2, 325 - b, 325 + b, 350);
    txLine (325, 350 + b, 400, 350);
    txLine (400 + b, 350, 400 - b, 250 + b * 2);
    txLine (400, 250, 350, 250);
    txLine (350 + b * 2, 250 + b, 350, 200 + b * 2);
    txLine (350, 200, 400, 200);
    txLine (400 + b * 2, 200 - b, 400, 175 + b);
    txLine (400, 175 + b, 325, 175);

    txSetColor (TX_WHITE, 5);
    txLine (425 + b, 175, 425, 350);
    txLine (425, 350 - b, 500, 350);
    txLine (500 + b, 350, 500 + b, 175);
    txLine (500 + b * 2, 175, 425, 175 + b * 2);
    txLine (450 + b, 200 - b, 450 + b, 325);
    txLine (450, 325 + b * 2, 475, 325);
    txLine (475 - b, 325 + b, 475, 200);
    txLine (475 + b, 200, 450 + b, 200);

    txSetColor (TX_LIGHTGREEN, 5);
    txLine (525 + b, 175, 525, 350);
    txLine (525 - b, 350 + b, 550, 350);
    txLine (550, 350 + b * 2, 550 + b, 250);
    txLine (550 - b, 250, 575, 275 + b);
    txLine (575, 275 + b, 600 + b * 2, 250);
    txLine (600 - b, 250, 600 + b, 350);
    txLine (600, 350 + b, 625, 350 - b);
    txLine (625 + b * 2, 350, 625, 175);
    txLine (625 - b, 175, 600 + b, 175);
    txLine (600, 175 + b, 575, 250);
    txLine (575, 250, 550 + b, 175 + b * 2);
    txLine (550, 175 + b, 525, 175);

    txSetColor (TX_PINK, 5);
    txLine (650, 175 + b, 650, 350 - b);
    txLine (650 + b * 2, 350, 675 + b, 350);
    txLine (675 - b, 350 + b, 675 + b * 2, 175);
    txLine (675, 175 + b * 2, 650 + b, 175);

    txSetColor (TX_BROWN, 5);
    txLine (700 + b, 175 + b * 2, 700 - b, 350);
    txLine (700, 175 - b, 725, 175 + b);
    txLine (725 + b, 175, 725, 250);
    txLine (725, 250, 775 + b, 175 - b);
    txLine (775 + b, 175, 775, 212.5 + b * 2);
    txLine (775, 212.5 + b, 737.5 + b * 2, 275);
    txLine (737.5 + b, 275 - b, 775, 350 + b * 2);
    txLine (775 - b * 2, 350 - b, 750 + b * 2, 350 + b);
    txLine (750, 350 + b * 2, 725 - b, 300);
    txLine (725 + b, 300 + b * 2, 725 - b, 350 + b);
    txLine (725, 350 - b, 700, 350 + b * 2);
    txLine (700 + b, 350 - b, 700, 175 + b);

    txSleep (10);
}
txSetColor (TX_WHITE);
txSelectFont ("Times New Roman", 50);
txTextOut (300, 400, "PRESENTS");
txSleep (2000);
txClear();

}

void WhilePresents ()
{

for (int b = 200; b >= 0; b--)
{
    txSetFillColor (TX_BLACK);
    txClear();

    txSetColor (TX_WHITE, 5);
    txLine (50 + b, 200 - b, 50 + b * 2, 250);
    txLine (50, 250 + b, 175 - b, 250);
    txLine (175, 250 - b, 175 + b, 100);
    txLine (175, 100 - b, 250 + b * 2, 100 + b);
    txLine (250 + b * 2, 100 - b, 250 + b, 250);
    txLine (250, 250 + b, 300, 250);
    txLine (300 + b, 250 + b * 2, 300 - b, 50);
    txLine (300, 50 + b, 125 - b, 50);
    txLine (125, 50 + b * 2, 125 + b, 200);
    txLine (125 + b * 2, 200 - b, 50, 200 + b);

    txLine (325 + b, 50 - b, 450, 50);
    txLine (450, 50 + b, 450, 175);
    txLine (450 + b * 2, 175 - b, 375 + b, 175);
    txLine (375, 175 - b, 375, 200 + b);
    txLine (375, 200 + b * 2, 475 + b, 200);
    txLine (475, 200 + b, 475, 250);
    txLine (475 + b, 250 + b * 2, 325 - b, 250);
    txLine (325 + b * 2, 250 + b, 325, 150);
    txLine (325 + b * 2, 150 - b, 400 + b, 150);
    txLine (400, 150 + b * 2, 400 - b, 100 + b);
    txLine (400, 100 - b, 325 + b, 100);
    txLine (325 + b * 2, 100 + b, 325 - b, 50);

    txLine (500 + b, 50 + b * 2, 550 - b, 50);
    txLine (550, 50 + b, 550 + b * 2, 200);
    txLine (550 + b * 2, 200 - b, 600 + b, 200);
    txLine (600 + b * 2, 200, 600 - b, 100 + b);
    txLine (600, 100 - b, 650 + b, 100 + b * 2);
    txLine (650, 100 + b, 650 + b * 2, 200);
    txLine (650 + b, 200, 700 - b, 200 + b * 2);
    txLine (700 + b * 2, 200 + b, 700, 50);
    txLine (700 + b * 2, 50, 750 - b, 50 + b);
    txLine (750 + b, 50 + b * 2, 750 - b, 250);
    txLine (750, 250 + b, 500 - b, 250 + b * 2);
    txLine (500 + b * 2, 250 - b, 500 + b, 50);
    txSleep (10);
}
txSelectFont ("Times New Roman", 45);
txTextOut (175, 325, "���� Paint");
txTextOut (250, 400, "������������ �����");
txTextOut (325, 475, "7 ����� 2014 ���");
txSleep (3000);
txClear();
}

void DrawInstructions ()
{
    txSelectFont ("Times New Roman", 19);
    txSetColor (TX_WHITE);
    txTextOut (50, 125, "Z - �������, X - �������, C - ������, V - �����, B - �����, N - �������, M - ���� - �������");
    txTextOut (200, 225, "A - �����-�����, S - ���������, D - ���������, F - ���������");
    txTextOut (50, 325, "����� ����������: 1 - Harlem shake, 2 - Du hast");
    txTextOut (50, 425, "����� �����: F1 - �������, F2 - ���, F3 - ������, F4 - ��������, F5 - ������, F6 - ������");

    txSetColor (TX_RED, 5);
    txLine (625, 25, 625, 100);
    txLine (625, 100, 787.5, 100);
    txLine (787.5, 100, 787.5, 25);
    txLine (787.5, 25, 625, 25);
    txSelectFont ("Times New Roman", 70);
    txTextOut (635, 25, "�����");

    if ((txMouseX() >= 625 & txMouseX() <= 787.5) & (txMouseY() >= 25 & txMouseY() <= 100))
    {
        txSetColor (TX_LIGHTRED, 5);
        txLine (625, 25, 625, 100);
        txLine (625, 100, 787.5, 100);
        txLine (787.5, 100, 787.5, 25);
        txLine (787.5, 25, 625, 25);
        txSelectFont ("Times New Roman", 70);
        txTextOut (635, 25, "�����");
        txSleep (100);
    }

}

void WhileInstructions ()
{
txClear();

while (!((txMouseX() >= 625 & txMouseX() <= 787.5) & (txMouseY() >= 25 & txMouseY() <= 100) & (txMouseButtons() & 1)))
{
    DrawInstructions ();
}

if ((txMouseX() >= 625 & txMouseX() <= 787.5) & (txMouseY() >= 25 & txMouseY() <= 100) & (txMouseButtons() & 1))
{
    txClear ();
    WhileMenu ();
}

}

void WhileMenu ()
{

while ((!((txMouseX() >= 270 & txMouseX() <= 515) & (txMouseY() >= 375 & txMouseY() <= 450) & (txMouseButtons() & 1))) && (!((txMouseX() >= 240 & txMouseX() <= 547.5) & (txMouseY() >= 475 & txMouseY() <= 550) & (txMouseButtons() & 1))))

{
    DrawMenu ();
    DrawSubtitles ( "����� ������ ��������, ������� ��������!, ����� ������ �������, ������� �����������");
}

if ((txMouseX() >= 270 & txMouseX() <= 515) & (txMouseY() >= 375 & txMouseY() <= 450) & (txMouseButtons() & 1))
{
    MainWhile ();
}

if ((txMouseX() >= 240 & txMouseX() <= 547.5) & (txMouseY() >= 475 & txMouseY() <= 550) & (txMouseButtons() & 1))
{
    WhileInstructions ();
}

}

void DrawMenu ()
{

txSetColor (TX_WHITE);
txSelectFont ("Times New Roman", 175);
txTextOut (200, 70, "PAINT");
txSelectFont ("Times New Roman", 70);
txTextOut (250, 275, "Klesomiklab");

txSetColor (TX_GREEN, 5);
txSelectFont ("Times New Roman", 70);
txTextOut (275, 375, "��������!");

txSetColor (TX_CYAN, 5);
txLine (240, 475, 240, 550);
txLine (240, 550, 547.5, 550);
txLine (547.5, 550, 547.5, 475);
txLine (547.5, 475, 240, 475);
txSelectFont ("Times New Roman", 70);
txTextOut (243, 475, "�����������");

if ((txMouseX() >= 270 & txMouseX() <= 515) & (txMouseY() >= 375 & txMouseY() <= 450))
{
    txSetColor (TX_LIGHTGREEN, 5);
    txLine (270, 375, 270, 450);
    txLine (270, 450, 515, 450);
    txLine (515, 450, 515, 375);
    txLine (515, 375, 270, 375);
    txSelectFont ("Times New Roman", 70);
    txTextOut (275, 375, "��������!");
}

if ((txMouseX() >= 240 & txMouseX() <= 547.5) & (txMouseY() >= 475 & txMouseY() <= 550))
{
    txSetColor (TX_LIGHTCYAN, 5);
    txLine (240, 475, 240, 550);
    txLine (240, 550, 547.5, 550);
    txLine (547.5, 550, 547.5, 475);
    txLine (547.5, 475, 240, 475);
    txSelectFont ("Times New Roman", 70);
    txTextOut (243, 475, "�����������");
}

if (!((txMouseX() >= 270 & txMouseX() <= 515) & (txMouseY() >= 375 & txMouseY() <= 450)))
{
    txSetColor (TX_GREEN, 5);
    txLine (270, 375, 270, 450);
    txLine (270, 450, 515, 450);
    txLine (515, 450, 515, 375);
    txLine (515, 375, 270, 375);
    txSelectFont ("Times New Roman", 70);
    txTextOut (275, 375, "��������!");
}

if (!((txMouseX() >= 240 & txMouseX() <= 547.5) & (txMouseY() >= 475 & txMouseY() <= 550)))
{
    txSetColor (TX_CYAN, 5);
    txLine (240, 475, 240, 550);
    txLine (240, 550, 547.5, 550);
    txLine (547.5, 550, 547.5, 475);
    txLine (547.5, 475, 240, 475);
    txSelectFont ("Times New Roman", 70);
    txTextOut (243, 475, "�����������");
}

}


void Paint ()
{

if (txMouseButtons() & 1)
    txCircle (txMouseX(), txMouseY(), 20);

if (txMouseButtons() & 2) txLine   (txMouseX(), txMouseY(), 0, 0);
    txSleep (0);

if (GetAsyncKeyState ('Z'))
{
    txSetFillColor (TX_GREEN);
    txSetColor (TX_GREEN, 5);
}

if (GetAsyncKeyState ('X'))
{
    txSetFillColor (TX_RED);
    txSetColor (TX_RED, 5);
}

if (GetAsyncKeyState ('C'))
{
    txSetFillColor (TX_YELLOW);
    txSetColor (TX_YELLOW, 5);
}

if (GetAsyncKeyState ('V'))
{
    txSetFillColor (TX_WHITE);
    txSetColor (TX_WHITE, 5);
}

if (GetAsyncKeyState ('B'))
{
    txSetFillColor (TX_GRAY);
    txSetColor (TX_GRAY, 5);
}

if (GetAsyncKeyState ('N'))
{
    txSetFillColor (TX_PINK);
    txSetColor (TX_PINK, 5);
}

if (GetAsyncKeyState ('M'))
{
    txSetFillColor (TX_LIGHTCYAN);
    txSetColor (TX_LIGHTCYAN, 5);
}

if (GetAsyncKeyState ('A'))
{
    txSetFillColor (TX_DARKGRAY);
    txSetColor (TX_DARKGRAY, 5);
}

if (GetAsyncKeyState ('S'))
{
    txSetFillColor (TX_MAGENTA);
    txSetColor (TX_MAGENTA, 5);
}

if (GetAsyncKeyState ('D'))
{
    txSetFillColor (TX_LIGHTGREEN);
    txSetColor (TX_LIGHTGREEN, 5);
}

if (GetAsyncKeyState ('F'))
{
    txSetFillColor (TX_ORANGE);
    txSetColor (TX_ORANGE, 5);
}

if (GetAsyncKeyState ('G'))
{
    txSetFillColor (TX_BLACK);
    txSetColor (TX_BLACK, 5);
}

if (GetAsyncKeyState ('H'))
{
    txSetFillColor (TX_BLUE);
    txSetColor (TX_BLUE, 5);
}

if (GetAsyncKeyState ('J'))
{
    txSetFillColor (TX_CYAN);
    txSetColor (TX_CYAN, 5);
}

if (GetAsyncKeyState ('K'))
{
    txSetFillColor (TX_LIGHTMAGENTA);
    txSetColor (TX_LIGHTMAGENTA, 5);
}

if (GetAsyncKeyState ('L'))
{
    txSetFillColor (TX_LIGHTRED);
    txSetColor (TX_LIGHTRED, 5);
}

if (GetAsyncKeyState ('Q'))
{
    txSetFillColor (TX_LIGHTBLUE);
    txSetColor (TX_LIGHTBLUE, 5);
}

}

void DrawSubtitles (const char text[])

{

int x = 820, y = 600;

while ((!((txMouseX() >= 270 & txMouseX() <= 515) & (txMouseY() >= 375 & txMouseY() <= 450) & (txMouseButtons() & 1))) && (!((txMouseX() >= 240 & txMouseX() <= 547.5) & (txMouseY() >= 475 & txMouseY() <= 550) & (txMouseButtons() & 1))))

{
    txSetColor (TX_WHITE);
    txSelectFont ("Times New Roman", 30);
    txTextOut (x, y, "����� ������ ��������, ������� ��������!, ����� ������ �������, ������� �����������");
    txSleep (10);
    txClear();
    DrawMenu ();
    x -= 2;

    if (x <= - 1000)
    {
        x = 820;
    }

}

}

void DrawMan (int x_Man, int y_Man, int r_Man, int s_Man, int speed_Man)
{

txSetFillColor (TX_GREEN);
txSetColor(TX_GREEN, s_Man + 5);

txCircle ( x_Man + 75,  y_Man + 75,  r_Man - 50);
txLine   ( x_Man + 60, y_Man + 125,  x_Man + 25, y_Man + 200);
txLine   ( x_Man + 90, y_Man + 125, x_Man + 125, y_Man + 200);
txLine   ( x_Man + 25,  y_Man + 75,       x_Man, y_Man + 125);
txLine   (x_Man + 125,  y_Man + 75, x_Man + 150, y_Man + 125);
txCircle ( x_Man + 75,       y_Man,  r_Man - 75);

}

void DrawHouse (int x_House, int y_House, int s_House, int v_House)
{

txSetFillColor (TX_YELLOW);
txSetColor(TX_YELLOW, s_House + 5);

txLine (x_House + 200,  y_House + 25, x_House + 200, y_House + 200);
txLine (x_House + 200, y_House + 200, x_House + 400, y_House + 200);
txLine (x_House + 400,  y_House + 25, x_House + 400, y_House + 200);
txLine (x_House + 400,  y_House + 25, x_House + 200,  y_House + 25);
txLine (x_House + 225,  y_House + 50, x_House + 225, y_House + 150);
txLine (x_House + 225, y_House + 150, x_House + 375, y_House + 150);
txLine (x_House + 375, y_House + 150, x_House + 375,  y_House + 50);
txLine (x_House + 375,  y_House + 50, x_House + 225,  y_House + 50);
txLine (x_House + 300,  y_House - 75, x_House + 200,  y_House + 25);
txLine (x_House + 300,  y_House - 75, x_House + 400,  y_House + 25);

}

void DrawSnowMen (int x_SnowMen, int y_SnowMen, int r_SnowMen, int s_SnowMan, int v_SnowMen)
{

txSetFillColor (TX_BROWN);
txSetColor (TX_BROWN, s_SnowMan + 5);

txCircle (x_SnowMen +  75, y_SnowMen + 225, r_SnowMen -   75);
txCircle (x_SnowMen +  75, y_SnowMen + 300, r_SnowMen -   50);
txCircle (x_SnowMen +  75, y_SnowMen + 425, r_SnowMen -   25);
txLine   (x_SnowMen +  25, y_SnowMen + 300, x_SnowMen -   25, y_SnowMen + 375);
txLine   (x_SnowMen + 125, y_SnowMen + 300, x_SnowMen +  175, y_SnowMen + 375);
txLine   (x_SnowMen -  25, y_SnowMen + 250, x_SnowMen -   25, y_SnowMen + 500);
txLine   (x_SnowMen -  25, y_SnowMen + 250, x_SnowMen -   50, y_SnowMen + 200);
txLine   (x_SnowMen -  25, y_SnowMen + 250, x_SnowMen -   25, y_SnowMen + 200);
txLine   (x_SnowMen -  25, y_SnowMen + 250, x_SnowMen,        y_SnowMen + 200);
txLine   (x_SnowMen -  25, y_SnowMen + 250, x_SnowMen - 37.5, y_SnowMen + 200);
txLine   (x_SnowMen -  25, y_SnowMen + 250, x_SnowMen - 12.5, y_SnowMen + 200);
txLine   (x_SnowMen -  25, y_SnowMen + 250, x_SnowMen - 37.5, y_SnowMen + 275);
txLine   (x_SnowMen -  25, y_SnowMen + 250, x_SnowMen - 12.5, y_SnowMen + 275);

}

void DrawCar (int x_Car, int y_Car, int r_Car, int s_Car, int v_Car)
{

txSetFillColor (TX_RED);
txSetColor (TX_RED, s_Car + 5);

txLine   (x_Car + 225, y_Car + 375, x_Car + 225, y_Car + 425);
txLine   (x_Car + 225, y_Car + 425, x_Car + 450, y_Car + 425);
txLine   (x_Car + 450, y_Car + 425, x_Car + 450, y_Car + 375);
txLine   (x_Car + 450, y_Car + 375, x_Car + 325, y_Car + 375);
txLine   (x_Car + 325, y_Car + 375, x_Car + 325, y_Car + 325);
txLine   (x_Car + 325, y_Car + 325, x_Car + 275, y_Car + 325);
txLine   (x_Car + 275, y_Car + 325, x_Car + 275, y_Car + 375);
txLine   (x_Car + 275, y_Car + 375, x_Car + 225, y_Car + 375);
txLine   (x_Car + 275, y_Car + 375, x_Car + 375, y_Car + 375);
txLine   (x_Car + 275, y_Car + 375, x_Car + 275, y_Car + 425);
txLine   (x_Car + 325, y_Car + 375, x_Car + 325, y_Car + 425);
txCircle (x_Car + 250, y_Car + 450, r_Car - 75);
txCircle (x_Car + 325, y_Car + 450, r_Car - 75);
txCircle (x_Car + 425, y_Car + 450, r_Car - 75);

}

void DrawTree (int x_Tree, int y_Tree, int s_Tree, int v_Tree)
{

txSetColor (TX_LIGHTGREEN, s_Tree + 5);

txLine (x_Tree + 525,  y_Tree - 75, x_Tree + 475,       y_Tree);
txLine (x_Tree + 525,  y_Tree - 75, x_Tree + 575,       y_Tree);
txLine (x_Tree + 475,       y_Tree, x_Tree + 500,       y_Tree);
txLine (x_Tree + 575,       y_Tree, x_Tree + 550,       y_Tree);
txLine (x_Tree + 500,       y_Tree, x_Tree + 450,  y_Tree + 75);
txLine (x_Tree + 550,       y_Tree, x_Tree + 600,  y_Tree + 75);
txLine (x_Tree + 450,  y_Tree + 75, x_Tree + 500,  y_Tree + 75);
txLine (x_Tree + 600,  y_Tree + 75, x_Tree + 550,  y_Tree + 75);
txLine (x_Tree + 500,  y_Tree + 75, x_Tree + 425, y_Tree + 150);
txLine (x_Tree + 550,  y_Tree + 75, x_Tree + 625, y_Tree + 150);
txLine (x_Tree + 425, y_Tree + 150, x_Tree + 625, y_Tree + 150);

txSetColor (TX_BROWN, s_Tree + 5);

txLine (x_Tree + 500, y_Tree + 150, x_Tree + 500, y_Tree + 200);
txLine (x_Tree + 550, y_Tree + 150, x_Tree + 550, y_Tree + 200);
txLine (x_Tree + 500, y_Tree + 200, x_Tree + 550, y_Tree + 200);

}

void DrawSun (int x_Sun, int y_Sun, int r_Sun, int s_Sun, int v_Sun)
{

txSetFillColor (TX_ORANGE);
txSetColor (TX_ORANGE, s_Sun + 5);

txCircle (x_Sun + 575, y_Sun + 400, r_Sun -   50);
txLine   (x_Sun + 575, y_Sun + 275, x_Sun +   575, y_Sun +   350);
txLine   (x_Sun + 625, y_Sun + 400, x_Sun +   675, y_Sun +   400);
txLine   (x_Sun + 575, y_Sun + 450, x_Sun +   575, y_Sun +   500);
txLine   (x_Sun + 525, y_Sun + 400, x_Sun +   475, y_Sun +   400);
txLine   (x_Sun + 675, y_Sun + 300, x_Sun + 612.5, y_Sun + 362.5);
txLine   (x_Sun + 475, y_Sun + 300, x_Sun + 537.5, y_Sun + 362.5);
txLine   (x_Sun + 475, y_Sun + 500, x_Sun + 537.5, y_Sun + 437.5);
txLine   (x_Sun + 675, y_Sun + 500, x_Sun + 612.5, y_Sun + 437.5);

}
