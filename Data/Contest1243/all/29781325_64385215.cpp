#include <bits/stdc++.h>
#define FI(_n) for(int i = 0; i < _n; ++i)
#define FJ(_n) for(int j = 0; j < _n; ++j)
#define mp make_pair
#define pb push_back
#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
//    ifstream cin("input.txt");
//    ofstream cout("output.txt");

    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    vector<ll> div;
    div.pb(n);
    for (int i = 2; 1ll * i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            div.pb(i);
            div.pb(n / i);
        }
        if (1ll * i * i == n)
            div.pop_back();
    }
    ll ans = div[0];
    for (int i = 1; i < div.size(); ++i)
        ans = __gcd(ans, div[i]);
    cout << ans;

    return 0;
}
