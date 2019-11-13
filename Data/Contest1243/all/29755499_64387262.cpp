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
        vector < pll > v;
        bool f = 1;
        for (int i = 0; i < n; i ++)
        {
            //cout << '#' << s << ' ' << t << ' ';
            if (s[i] == t[i])
                continue;
            ll ind = -1;
            for (int j = i + 1; j < n; j ++)
            {
                if (t[j] == t[i])
                {
                    ind = j;
                }
            }
            //cout << ind << '\n';
            if (ind == -1)
            {
                ll ind2 = -1;
                for (int j = i + 1; j < n; j ++)
                {
                    if (s[j] == t[i])
                    {
                        ind2 = j;
                    }
                }
                if (ind2 == -1)
                    f = 0;
                else
                {
                    v.pb({ind2, ind2});
                    v.pb({i, ind2});
                    swap(s[ind2], t[ind2]);
                    swap(s[i], t[ind2]);
                }
            }
            else
            {
                v.pb({i, ind});
                swap(s[i], t[ind]);
            }
        }
        if (!f)
            cout << "NO\n";
        else
        {
            cout << "YES\n" << v.size() << '\n';
            for (auto x : v)
                cout << x.F + 1 << ' ' << x.S + 1 << '\n';
        }
    }
    return 0;
}
