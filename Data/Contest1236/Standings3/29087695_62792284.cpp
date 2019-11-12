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

    int n;
    cin >> n;

    int i = 0, j = 0;
    int num = 1;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            answer[i][j] = num++;
        if (i % 2 == 1)
            reverse(answer[i], answer[i] + n);
    }

    for (int j = 0; j < n; ++j)
    {
        for (int i = 0; i < n; ++i)
            cout << answer[i][j] << ' ';
        cout << '\n';
    }


    return 0;
}
