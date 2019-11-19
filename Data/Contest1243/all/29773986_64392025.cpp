#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long
#define pb push_back
#define ft first
#define sd second
#define inf (int)1e9

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

using namespace std;

ll gcd(ll a , ll b) {
    if (a == 0)
        return b;

    return gcd(b%a,a);
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    ll n;

    cin >> n;

    ll ans = n;
    vector <ll> g1,g2;

    for (ll i = 2; i*i <= n; i++) {
        if (n % i==0) {
            g1.pb(i);
            g2.pb(n/i);
        }
    }

    reverse(g2.begin(),g2.end());

    for (auto i: g1) {
        ans = gcd(ans,i);
    }

    for (auto i: g2) {
        ans = gcd(ans,i);
    }

    cout << ans;
    return 0;
}