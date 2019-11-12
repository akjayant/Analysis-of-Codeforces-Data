#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

long long binpow(long long a, long long p)
{
    long long answer = 1;
    while (p)
    {
        if (p & 1)
        {
            answer *= a;
            answer %= mod;
        }
        a = (a * a) % mod;
        p >>= 1;
    }
    return answer;
}

int answer[302][302];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, m;
    cin >> n >> m;
    cout << binpow(binpow(2, m) - 1, n);

    return 0;
}
