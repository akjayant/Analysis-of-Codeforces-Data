#include <bits/stdc++.h>
using namespace std;


long long gcd(long long x, long long y)
{
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n;
    long long res;
    cin >> n;

    res = n;
    for (long long i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            long long ti = n / i;
            res = gcd(res, i);
            res = gcd(res, ti);
        }
    cout << res;
    return 0;
}
