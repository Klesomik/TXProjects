#include <TXLib.h>

#define x_size 650
#define y_size 650

void DrawWeb(bool TFW);
void FillColor();

bool TFW = true;

int main()
{
    txCreateWindow(650, 650);

    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        if(GetAsyncKeyState('Q'))
        {
            TFW = true;
            DrawWeb(TFW);
        }

        if(GetAsyncKeyState('W'))
        {
            TFW = false;
            DrawWeb(TFW);
        }
    }

    return 0;
}

void FillColor()
{
    txSetFillColor(RGB(255, 255, 128));
    txRectangle(x_size / 2, 0, x_size, y_size / 2);

    txSetFillColor(RGB(255, 128, 128));
    txRectangle(0, 0, x_size / 2, y_size / 2);

    txSetFillColor(RGB(128, 255, 128));
    txRectangle(0, y_size / 2, x_size / 2, y_size);

    txSetFillColor(RGB(0, 255, 255));
    txRectangle(x_size / 2, y_size / 2, x_size, y_size);
}

//--------------------------------------------------------------------------------------------

void DrawWeb(bool TFW)
{
    FillColor();

    if(TFW == true)
    {
        txSetColor(TX_GRAY);

        for (double x = 25; x <= 650; x += 25) txLine(x, 0, x, y_size);

        for (double y = 25; y <= 650; y += 25) txLine(0, y, x_size, y);
    }
}