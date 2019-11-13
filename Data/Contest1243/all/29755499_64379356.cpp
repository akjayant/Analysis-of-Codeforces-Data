//In The Name of Allah
#include <bits/stdc++.h>

using namespace std;

typedef long long            ll;
typedef long double          ld;
typedef string               str;
typedef pair < ll , ll >     pll;

#define F               first
#define S               second
#define pb              push_back
#define sep             ' '
#define endl            '\n'
#define fast_io         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define dbl_io(x)       cout << fixed << setprecision(x);

const int N = 1e5 + 10;
const ll mod = 1e9 + 7;
const ll inf = 1e18 + 10;

int main()
{
    fast_io
    //dbl_io(10);
    ll q;
    cin >> q;
    while (q --)
    {
        ll n;
        string s, t;
        cin >> n >> s >> t;
        vector < ll > v;
        for (int i = 0; i < n; i ++)
            if (s[i] != t[i])
                v.pb(i);
        if (v.size() == 2)
        {
            if (t[v[0]] == t[v[1]] && s[v[1]] == s[v[0]])
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
            cout << "NO\n";
    }
    return 0;
}
