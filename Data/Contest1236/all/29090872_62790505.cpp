#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define mp make_pair
ll mod = 1e9 + 7;
ll power(ll num, ll idx) {
    if(!idx) {
        return 1;
    }
    ll temp = power(num, idx / 2);
    temp %= mod;
    temp *= temp;
    temp %= mod;
    if(idx % 2) {
        temp *= num;
        temp %= mod;
    }
    return temp;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n, m, i, j;
    cin >> n >> m;
    ll num = power(2, m) % mod;
    num--;
    if(num < 0) {
        num += mod;
    }
    ll ans = power(num, n) % mod;
    cout << ans << endl;
    // num %= mod;

    return 0;
}