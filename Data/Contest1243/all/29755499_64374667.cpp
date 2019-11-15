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

const int N = 1e3 + 10;
const ll mod = 1e9 + 7;
const ll inf = 1e18 + 10;

ll a[N];

int main()
{
    fast_io
    //dbl_io(10);
    ll q;
    cin >> q;
    while (q --)
    {
        ll n;
        cin >> n;
        for (int i = 0; i < n; i ++)
            cin >> a[i];
        ll ans = 1;
        for (int i = 1; i <= n; i ++)
        {
            ll t = 0;
            for (int j = 0; j < n; j ++)
            {
                if (a[j] >= i)
                    t ++;
            }
            if (t >= i)
                ans = i;
        }
        cout << ans << '\n';
    }
    return 0;
}
