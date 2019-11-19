#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double

#define int int64_t

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = (1 << 30) - 1;
const long long oo = (1ll << 62) - 1;
const long double PI = 3.1415926535898;
///BEGIN CODE
const int N = 100000 + 5;

int n, m;

void solve()
{
    cin >> n;
    int dc1 = 0, dl1 = 0, dc2 = 0, dl2 = 0;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if(x & 1) dl1 += 1;
        else dc1 += 1;
    }
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        if(x & 1) dl2 += 1;
        else dc2 += 1;
    }
    cout << (1ll * dc1 * dc2) +(1ll * dl1 * dl2) << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        solve();
    }

}

/**
    Code by: Best_Nakroth 12TH.


*/
