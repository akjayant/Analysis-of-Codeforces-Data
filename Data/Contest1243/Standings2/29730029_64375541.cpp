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

int t, n, a[maxn];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    if(fopen("1.inp", "r"))
    {
       freopen("1.inp", "r", stdin);
       freopen("1.out", "w", stdout);
    }
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + 1 + n, greater < int > ());
        int j; a[n + 1] = n;
        for(int i = 1; i <= n + 1; i++)
            if(a[i] < i)
            {
                j = i;
                break;
            }
        cout << j - 1 << '\n';
    }
}
