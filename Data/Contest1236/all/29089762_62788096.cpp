#include <bits/stdc++.h>

using namespace std;

long long MOD = 1000000007;

long long Power(long long a, long long k)
{
    long long t = 1, S=a, A=1;
    while (k > 0)
    {
        if (k % (2*t) != 0)
        {
            k -= t;
            A *= S;
            A %= MOD;
        }
        S *= S;
        S %= MOD;
        t *= 2;
    }
    return A;
}

int main()
{
    ios::sync_with_stdio(false);
    long long n, m, Su;
    cin >> n >> m;
    Su = Power(2, m) - 1;
    Su = Power(Su, n);
    cout << Su;
    return 0;
}
