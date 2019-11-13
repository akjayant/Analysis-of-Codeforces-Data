#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;


const int N = (int)1e5 + 5;
const int MOD = (int)1e9 + 7;

int sum(int a, int b)
{
    return (a + b) % MOD;
}
int mult(int a, int b)
{
    return (a * 1LL * b) % MOD;
}
int bin_pow(int a, int n)
{
    int res = 1;
    for (; n; n >>= 1, a = mult(a, a))
        if (n & 1) res = mult(res, a);
    return res;
}
int inv(int a)
{
    return bin_pow(a, MOD - 2);
}

int f[N], rf[N];

int C(int n, int k)
{
    if (k < 0 || k > n) return 0;
    return mult(f[n], mult(rf[n - k], rf[k]));
}

char s[N];

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif


    scanf("%s", s);
    int n = strlen(s);

    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = mult(f[i - 1], i);
    rf[N - 1] = inv(f[N - 1]);
    for (int i = N - 2; i >= 0; --i)
        rf[i] = mult(rf[i + 1], i + 1);

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'w' || s[i] == 'm')
        {
            printf("0");
            return 0;
        }
    }

    int cnt = 1;
    vector< pair<char,int> > v;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] != s[i - 1])
        {
            v.push_back({s[i - 1], cnt});
            cnt = 1;
        }
        else
            ++cnt;
    }
    v.push_back({s[n - 1], cnt});

    int ans = 1;
    for (auto pr : v)
    {
        char ch = pr.first;
        if (ch != 'u' && ch != 'n') continue;
        int cnt = pr.second;
        int cur = 0;
        for (int a = 0; 2 * a <= cnt; ++a)
            cur = sum(cur, C(cnt - a, a));
        ans = mult(ans, cur);
    }

    printf("%d\n", ans);

}
