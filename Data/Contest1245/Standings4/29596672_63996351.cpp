#include <bits/stdc++.h>

#define input   std::cin
#define output  std::cout

#define num     int

int main()
{
    std::ios_base::sync_with_stdio(false);

    int N;
    input >> N;
    while (N--) {
        num x, y;
        input >> x >> y;
        num gcd = std::__gcd(x, y);
        if (gcd == 1) output << "Finite\n";
        else          output << "Infinite\n";
    }

    return 0;
}
