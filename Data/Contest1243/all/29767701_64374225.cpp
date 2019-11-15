#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = (1 << 30) - 1;
const long long oo = (1ll << 62) - 1;
const long double PI = 3.1415926535898;

const int N = 10000 + 5;

int n;
int a[N];

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1, greater<int> ());
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        int val = min(i, a[i]);
        res = max(res, val);
    }
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
        solve();

}

/**
TEST:


*/
