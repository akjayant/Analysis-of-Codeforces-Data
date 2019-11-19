#include <iostream>

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int a, b, c, d, k;
        std::cin >> a >> b >> c >> d >> k;

        int x = (a + c - 1)/c, y = (b + d - 1)/d;
        if (x + y <= k)
            std::cout << x << " " << y << "\n";
        else
            std::cout << "-1\n";
    }
}
