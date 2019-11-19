/// Quality Over Quantity
 
#include <bits/stdc++.h>
 
#define FILE_NAME "D"
 
using namespace std;
using ll = long long;
 
#define f first
#define s second 
#define pb push_back
#define pp pop_back
#define SZ(x) ((int) x.size())
#define all(x) x.begin(), x.end()
#define what_is(x) cerr << #x << " is " << x << endl;
 
void freekick() {
#ifndef ONLINE_JUDGE
    freopen(FILE_NAME".in", "r", stdin);
    freopen(FILE_NAME".out", "w", stdout);
#endif
}
 
const int DX[] = {+1, 0, -1, 0, +1, +1, -1, -1};
const int DY[] = {0, +1, 0, -1, +1, -1, +1, -1};
 
void freegoal() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
}

ll gcd(ll a, ll b) {
    return a ? gcd(b % a, a) : b;
} 

signed main() {
    freekick();
    freegoal();              
    ll n;
    cin >> n;
    vector<ll> dp;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0) {
            dp.pb(i); if (i * i != n)
                dp.pb(n / i);
        }
    dp.pb(n); 
    ll res = false;
    for (ll i = 0; i < SZ(dp); i++) 
        res = gcd(res, dp[i]);
    cout << res << '\n';
    return false;
}        