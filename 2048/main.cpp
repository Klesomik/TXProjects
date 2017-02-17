#include <TXLib.h>

struct Quadrats
{
    int x, y, size_for_x, size_for_y, began;
};

void MainWhile(int data[4][4], HDC table, HDC fon);
void Control(int data[4][4], HDC table, HDC fon);
void Spawn(int data[4][4], HDC table);
void Null(int data[4][4]);
void DrawWindow(HDC fon, HDC table, int data[4][4]);
void LeftPush(HDC fon, HDC table, int data[4][4]);

int data[4][4];

int main()
{
    const int x_size = 415, y_size = 515;

    txCreateWindow(x_size, y_size);

    HDC fon = txLoadImage("Pictures\\mainfon.bmp"), table = txLoadImage("Pictures\\photos.bmp");

    Null(data);

    DrawWindow(fon, table, data);

    MainWhile(data, table, fon);

    txDeleteDC(table);
    txDeleteDC(fon);

    return 0;
}

void MainWhile(int data[4][4], HDC table, HDC fon)
{
    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        Control(data, table, fon);
    }
}

void Control(int data[4][4], HDC table, HDC fon)
{
    if(GetAsyncKeyState(VK_UP))
    {
        Spawn(data, table);

        txSleep(200);
    }

    if(GetAsyncKeyState(VK_DOWN))
    {
        Spawn(data, table);

        txSleep(200);
    }

    if(GetAsyncKeyState(VK_LEFT))
    {
        LeftPush(fon, table, data);
    }

    if(GetAsyncKeyState(VK_RIGHT))
    {
        Spawn(data, table);

        txSleep(200);
    }
}

void LeftPush(HDC fon, HDC table, int data[4][4])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(data[i][j] != 0)
            {
                for(int t = i; t < 3; t++)
                {
                    if(data[t][j] == data[t + 1][j])
                    {
                        data[t + 1][j] += data[t][j];

                        DrawWindow(fon, table, data);
                    }
                }
            }
        }
    }

    Spawn(data, table);

    txSleep(200);
}

void Spawn(int data[4][4], HDC table)
{
    int a = 0, b = 0;

    while(a != -1)
    {
        a = rand() % 4, b = rand() % 4;

        if(data[a - 1][b - 1] == 0)
        {
            data[a - 1][b - 1] = 2;

            txBitBlt(txDC(), 10 + 100 * a, 110 + 100 * b, 95, 95, table, 0, 0);

            a = -1;
        }

        if(GetAsyncKeyState(VK_ESCAPE)) break;
    }
}

void Null(int data[4][4])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++) data[i][j] = 0;
    }
}

void DrawWindow(HDC fon, HDC table, int data[4][4])
{
    txBitBlt(txDC(), 0, 0, 415, 515, fon, 0, 0);

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(data[i][j] != 0) txBitBlt(txDC(), 10 + 100 * i, 110 + 100 * j, 95, 95, table, 0, 0);
        }
    }
}
