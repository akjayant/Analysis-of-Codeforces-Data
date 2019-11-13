#include <bits/stdc++.h>
#define ll long long int
#define Zeroes ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Auto int main()
#define Accepted {return 0;}
int const Max = 1e5 + 7;
int const MOD = 1e9 + 7;

using namespace std;

ll powMod(ll a, ll n, ll m) {
    if(n == 0)
        return 1%m;
    if(n == 1)
        return a%m;
    ll t = powMod(a,n/2,m) % m;
    t = (t * t) % m;

    if(n % 2)
        t = (t * a) % m;

    return t%m;
}

ll n, m;

Auto {
    Zeroes
    cin >> n >> m;
    ll x = powMod(2,m,MOD) - 1;
    ll ans = powMod(x,n,MOD);

    cout << ans;

    Accepted
}
