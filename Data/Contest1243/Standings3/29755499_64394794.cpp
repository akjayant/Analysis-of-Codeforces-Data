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
    ll n;
    cin >> n;
    for (ll i = 2; i * i <= n; i ++)
    {
        if (n % i == 0)
        {
            ll k = n;
            while (k % i == 0)
                k /= i;
            if (k == 1)
                return cout << i, 0;
            return cout << 1, 0;
        }
    }
    cout << n;
    return 0;
}
