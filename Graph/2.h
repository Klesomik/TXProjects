#include <TXLib.h>

//--------------------------------------------------------------------------------------------

#define x_size 650
#define y_size 650

//--------------------------------------------------------------------------------------------

class Draw
{
    private:

    //Draw (const Draw&);
    //Draw& operator = (const Draw&);

    struct Push
    {
        int x, y, size_for_x, size_for_y, began;
    };

    HDC fon;

    protected:

    COLORREF color;

    public:

    Draw() :
        fon   (txLoadImage ("Pictures\\Push.bmp")),
        color (TX_BLACK)
        {}

    ~Draw()
    {
        //txDeleteDC(fon);
    }

    void ClearWindow();
    void FillColor();
    void DrawWeb(int* zoom);
    void X(int* zoom);
    void Y(int* zoom);
    void DrawAxis(int* zoom);
    void Divisions(int* zoom);
    void DrawGraph(int* zoom);
    void DrawPush();
};

//--------------------------------------------------------------------------------------------

void Draw::ClearWindow()
{
    txSetFillColor(TX_WHITE);
    txClear();
}

//--------------------------------------------------------------------------------------------

void Draw::FillColor()
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

void Draw::DrawWeb(int* zoom)
{
    FillColor();

    txSetColor(TX_GRAY);

    for (double x = 25; x <= 650; x += 25 * (*zoom)) txLine(x, 0, x, y_size);

    for (double y = 25; y <= 650; y += 25 * (*zoom)) txLine(0, y, x_size, y);
}

//--------------------------------------------------------------------------------------------

void Draw::X(int* zoom)
{
    txSetColor(color, 3);

    txLine(0, y_size / 2, x_size, y_size / 2);

    txLine(x_size, y_size / 2, x_size - 25 * (*zoom), y_size / 2 - 25 * (*zoom));
    txLine(x_size, y_size / 2, x_size - 25 * (*zoom), y_size / 2 + 25 * (*zoom));

    txSetColor(color);

    for (int i = 25; i <= 625; i += 50 * (*zoom)) txLine(i, 318.75, i, 331.25);
}

//--------------------------------------------------------------------------------------------

void Draw::Y(int* zoom)
{
    txSetColor(color, 3);

    txLine(x_size / 2, 0, x_size / 2, y_size);

    txLine(x_size / 2, 0, x_size / 2 - 25 * (*zoom), 25 + 25 * (*zoom));
    txLine(x_size / 2, 0, x_size / 2 + 25 * (*zoom), 25 + 25 * (*zoom));

    txSetColor(color);

    for (int i = 25; i <= 625; i += 50 * (*zoom)) txLine(318.75, i, 331.25, i);
}

//--------------------------------------------------------------------------------------------

void Draw::DrawAxis(int* zoom)
{
    X(zoom);
    Y(zoom);
}

//--------------------------------------------------------------------------------------------

void Draw::DrawGraph(int* zoom)
{
    DrawAxis(zoom);
}

//--------------------------------------------------------------------------------------------

void Draw::DrawPush()
{
    Push p = {0, 0, 50, 50, 0};

    //Зум
    if ((txMouseX() >= 30 && txMouseX() <=  80) && (txMouseY() >= 5 && txMouseY() <= 55)) txBitBlt(txDC(), p.x + 30, p.y + 5, p.size_for_x, p.size_for_y, fon, p.began + 750, 0);
    else txBitBlt (txDC(), p.x +  30, p.y +   5, p.size_for_x, p.size_for_y, fon, p.began, 0);

    if ((txMouseX() >= 85 && txMouseX() <= 135) && (txMouseY() >= 5 && txMouseY() <= 55)) txBitBlt(txDC(), p.x + 85, p.y + 5, p.size_for_x, p.size_for_y, fon, p.began + 800, 0);
    else txBitBlt (txDC(), p.x +  85, p.y +   5, p.size_for_x, p.size_for_y, fon, p.began + 50, 0);

    //Режим
    if ((txMouseX() >= 510 && txMouseX() <=  560) && (txMouseY() >= 5 && txMouseY() <= 55)) txBitBlt(txDC(), p.x + 510, p.y + 5, p.size_for_x, p.size_for_y, fon, p.began + 850, 0);
    else txBitBlt (txDC(), p.x + 510,   p.y + 5, p.size_for_x, p.size_for_y, fon, p.began + 100, 0);

    if ((txMouseX() >= 565 && txMouseX() <=  615) && (txMouseY() >= 5 && txMouseY() <= 55)) txBitBlt(txDC(), p.x + 565, p.y + 5, p.size_for_x, p.size_for_y, fon, p.began + 900, 0);
    else txBitBlt (txDC(), p.x + 565,   p.y + 5, p.size_for_x, p.size_for_y, fon, p.began + 150, 0);

    //Графики
    if ((txMouseX() >= 25 && txMouseX() <=  75) && (txMouseY() >= 568 && txMouseY() <= 618)) txBitBlt(txDC(), p.x +  25, p.y + 568, p.size_for_x, p.size_for_y, fon, p.began + 950, 0);
    else txBitBlt (txDC(), p.x +  25, p.y + 568, p.size_for_x, p.size_for_y, fon, p.began + 200, 0);

    if ((txMouseX() >= 80 && txMouseX() <=  130) && (txMouseY() >= 568 && txMouseY() <= 618)) txBitBlt(txDC(), p.x +  80, p.y + 568, p.size_for_x, p.size_for_y, fon, p.began + 1000, 0);
    else txBitBlt (txDC(), p.x +  80, p.y + 568, p.size_for_x, p.size_for_y, fon, p.began + 250, 0);

    if ((txMouseX() >= 135 && txMouseX() <=  185) && (txMouseY() >= 568 && txMouseY() <= 618)) txBitBlt(txDC(), p.x + 135, p.y + 568, p.size_for_x, p.size_for_y, fon, p.began + 1050, 0);
    else txBitBlt (txDC(), p.x +  135, p.y + 568, p.size_for_x, p.size_for_y, fon, p.began + 300, 0);

    if ((txMouseX() >= 190 && txMouseX() <=  240) && (txMouseY() >= 568 && txMouseY() <= 618)) txBitBlt(txDC(), p.x + 190, p.y + 568, p.size_for_x, p.size_for_y, fon, p.began + 1100, 0);
    else txBitBlt (txDC(), p.x +  190, p.y + 568, p.size_for_x, p.size_for_y, fon, p.began + 350, 0);

    if ((txMouseX() >= 245 && txMouseX() <=  295) && (txMouseY() >= 568 && txMouseY() <= 618)) txBitBlt(txDC(), p.x + 245, p.y + 568, p.size_for_x, p.size_for_y, fon, p.began + 1150, 0);
    else txBitBlt (txDC(), p.x +  245, p.y + 568, p.size_for_x, p.size_for_y, fon, p.began + 400, 0);


    if ((txMouseX() >= 355 && txMouseX() <=  405) && (txMouseY() >= 568 && txMouseY() <= 618)) txBitBlt(txDC(), p.x + 355, p.y + 568, p.size_for_x, p.size_for_y, fon, p.began + 1200, 0);
    else txBitBlt (txDC(), p.x +  355, p.y + 568, p.size_for_x, p.size_for_y, fon, p.began + 450, 0);

    if ((txMouseX() >= 410 && txMouseX() <=  460) && (txMouseY() >= 568 && txMouseY() <= 618)) txBitBlt(txDC(), p.x + 410, p.y + 568, p.size_for_x, p.size_for_y, fon, p.began + 1250, 0);
    else txBitBlt (txDC(), p.x +  410, p.y + 568, p.size_for_x, p.size_for_y, fon, p.began + 500, 0);

    if ((txMouseX() >= 465 && txMouseX() <=  515) && (txMouseY() >= 568 && txMouseY() <= 618)) txBitBlt(txDC(), p.x + 465, p.y + 568, p.size_for_x, p.size_for_y, fon, p.began + 1300, 0);
    else txBitBlt (txDC(), p.x +  465, p.y + 568, p.size_for_x, p.size_for_y, fon, p.began + 550, 0);

    if ((txMouseX() >= 520 && txMouseX() <=  570) && (txMouseY() >= 568 && txMouseY() <= 618)) txBitBlt(txDC(), p.x + 520, p.y + 568, p.size_for_x, p.size_for_y, fon, p.began + 1350, 0);
    else txBitBlt (txDC(), p.x +  520, p.y + 568, p.size_for_x, p.size_for_y, fon, p.began + 600, 0);
}
