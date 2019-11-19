#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, ans = 0, cat;
    cin >> n;
    if (n == 1)
        return puts("1"), 0;
    ll m = n;
    for (ll x = 2; x * x <= n; x++)
        if (n % x == 0)
        {
            ++ans;
            cat = x;
            while (n % x == 0)
                n /= x;
        }
    if (n > 1)
        ++ans, cat = n;
    if (ans > 1)
        puts("1");
    else if (cat == 2)
        puts("2");
    else
        printf("%lld\n", cat);
}