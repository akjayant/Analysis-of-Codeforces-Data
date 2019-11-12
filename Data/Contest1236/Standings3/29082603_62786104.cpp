#include<bits/stdc++.h>
using namespace std;
const int MX = (1<<20);
typedef  long long ll;
ll MOD = 1e9 + 7;
ll POW(ll x , ll y){
    if(y == 0) return 1;
    ll ret = POW(x , y / 2);
    ret *= ret; ret %= MOD;
    if(y % 2) ret *= x;
    return ret % MOD;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("exptree.in", "r", stdin);
#endif
    ll a, b;
    cin >> a >> b;
    ll ans = POW(2, b);
    ans--;
    ans = POW(ans, a);
    cout << ans << endl;
}