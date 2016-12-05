#include <TXLib.h>

typedef int (*func)(int a, int b);

inline int call_func(int a, int b)
{
    return a + b;
}

inline void t(int a, int b, func f)
{
    int sum = f(a, b);
    std::cout << "Sum = " << sum << std::endl;
}

int main()
{
    txCreateWindow(800, 600);

    t(5, 2, &call_func);

    return 0;
}
