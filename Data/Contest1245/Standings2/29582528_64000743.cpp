#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main()
{
    int t;
    scanf("%d", &t);
    int a, b;
    while (t--)
    {
        scanf("%d%d", &a, &b);
        if (__gcd(a, b) == 1)
            puts("Finite");
        else puts("Infinite");
    }
    return 0;

}
