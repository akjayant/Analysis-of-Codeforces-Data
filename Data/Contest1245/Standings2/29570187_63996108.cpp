#include <iostream>
#include <cstdio>

using namespace std;


int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

bool solve()
{
    int a, b;
    scanf("%d %d", &a, &b);
    return gcd(a, b) == 1;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif


    int t;
    scanf("%d", &t);
    while(t--)
        solve() ? printf("Finite\n") : printf("Infinite\n");

}
