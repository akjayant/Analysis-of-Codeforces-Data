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

const int N = 500 + 5;

int t, n;
char a[N], b[N];

int d[N];
vector<II> res;

void solve()
{
    cin >> n;
    for(int i=  1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    res.clear();
    for(int i = 0; i <= 26; i++)
    {
        d[i] = 0;
    }
    for(int i = 1; i <= n + n; i++)
    {
        if(i <= n) d[a[i] - 'a'] += 1;
        else d[b[i - n] - 'a'] += 1;
    }

    for(int i = 0; i <= 26; i++)
    {
        if(d[i] & 1)
        {
            cout << "No" << '\n';
            return;
        }
    }

    for(int t = 1; t <= n; t++)
    {
        if(a[t] != b[t])
        {
            bool kt = false;
            for(int j = t + 1; j <= n; j++)
            {
                if(b[j] == b[t])
                {
                    res.pb(mp(t, j));
                    swap(a[t], b[j]);
                    kt = true;
                    break;
                }
            }
            if(kt) continue;
            for(int i = t + 1; i <= n; i++)
            {
                if(a[i] == b[t])
                {
                    res.pb(mp(i, n));
                    res.pb(mp(t, n));
                    swap(a[i], b[n]);
                    swap(a[t], b[n]);
                    kt = true;
                    break;
                }
            }
            if(kt == false)
            {
                cout << "No" << '\n';
                return;
            }
        }
    }
    cout << "Yes" << '\n';
    cout << res.size() << '\n';
    for(int i = 0; i < res.size(); i++)
        cout << res[i].fi << " " << res[i].se << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    cin >> t;
    for(int i = 1; i <= t; i++)
        solve();

}

/**
TEST:


*/
