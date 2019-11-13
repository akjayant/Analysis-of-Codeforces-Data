#include <bits/stdc++.h>
#define getbit(x, i) (x >> (i - 1) & 1)
#define onbit(x, i) (x | (1 << (i - 1)))
#define offbit(x, i) (x ^ (1 << (i - 1)))
#define cntone(x) (__builtin_popcount(x))
#define sum(x, y, u, v) (f[u][v] - f[x - 1][v] - f[u][y - 1] + f[x - 1][y - 1])

using namespace std;

typedef long long ll;
const int oo = 1e9;
const int maxn = 1e5 + 10;

int T, n, m;
string s, t;

bool check()
{
    int cnt = 0, x1 = -1, x2 = -1;
    for(int i = 0; i < n; i++)
        if(s[i] != t[i])
    {
        cnt++; if(cnt > 2) return false;
        if(x1 == -1) x1 = i;
        else x2 = i;
    }
    if(cnt != 2) return false;
    return (s[x1] == s[x2] && t[x1] == t[x2]);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    if(fopen("1.inp", "r"))
    {
       freopen("1.inp", "r", stdin);
       freopen("1.out", "w", stdout);
    }
    cin >> T;
    while(T--)
    {
        cin >> n >> s >> t;
        if(check()) cout << "Yes\n";
        else cout << "No\n";
    }
}
