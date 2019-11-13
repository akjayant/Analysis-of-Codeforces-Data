#include <iostream>

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a%b);
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    int t;
    std::cin >> t;
    while (t--)
    {
        int a,b;
        std::cin >> a >> b;
        std::cout << (gcd(a,b) == 1 ? "Finite" : "Infinite" ) << "\n"; 
    }
    return 0;
}