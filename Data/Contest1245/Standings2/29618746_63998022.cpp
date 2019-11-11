#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int g = __gcd(a, b);
        if (g == 1)
            printf("Finite\n");
        else
            printf("Infinite\n");
    }
    return 0;
}