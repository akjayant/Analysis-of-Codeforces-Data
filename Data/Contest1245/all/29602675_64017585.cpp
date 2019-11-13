#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#define gc getchar
#define il inline
#define re register
#define LL long long
using namespace std;
template <typename T>
void read(T &s)
{
    s = 0;
    bool p = 0;
    char ch;
    while (ch = gc(), p |= ch == '-', !isdigit(ch))
        ;
    while (s = s * 10 + ch - '0', ch = gc(), isdigit(ch))
        ;
    s *= p ? -1 : 1;
}
int gcd(int a, int b)
{
    return !b ? a : gcd(b, a % b);
}
int main()
{
    int t;
    read(t);
    while (t--)
    {
        int a, b;
        read(a), read(b);
        if (gcd(a, b) != 1)
            printf("Infinite\n");
        else
            printf("Finite\n");
    }
    return 0;
}