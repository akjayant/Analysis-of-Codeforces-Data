#include <iostream>
#include <algorithm>
#include <bitset>
#include <set>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <stack>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iomanip>
#define int long long
#define double long double
using namespace std;

const int MAXN = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double eps = 1e-5;

int n;

inline int read()
{
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}

int ans[MAXN];

signed main()
{
    ans[0] = ans[1] = 1;
    for (int i = 2; i <= 1e5; i++)
    {
        ans[i] = ans[i - 1] % MOD + ans[i - 2] % MOD;
        ans[i] %= MOD;
    }
    string str;
    cin >> str;
    char ch;
    int len = 0;
    int res = 1;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'u')
        {
            if (len == 0)
            {
                ch = str[i];
                len++;
            }
            else
            {
                if (ch == str[i])
                    len++;
                else
                {
                    res = res % MOD * ans[len] % MOD;
                    ch = str[i];
                    len = 1;
                }
            }
        }
        else if (str[i] == 'n')
        {
            if (len == 0)
            {
                ch = str[i];
                len++;
            }
            else
            {
                if (ch == str[i])
                    len++;
                else
                {
                    res = res % MOD * ans[len] % MOD;
                    ch = str[i];
                    len = 1;
                }
            }
        }
        else if (str[i] == 'm' || str[i] == 'w')
        {
            res = 0;
            break;
        }
        else
        {
            res = res % MOD * ans[len] % MOD;
            len = 0;
        }
    }
    if (len)
    {
        res = res % MOD * ans[len] % MOD;
    }
    cout << res % MOD << endl;
    return 0;
}
