#include <bits/stdc++.h>
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
using namespace std;
 
typedef long long ll;

int main() 
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    fastio

    ll MOD = (ll)1e9+7;

    ll a[(ll)1e5+1];
    a[0] = 0; a[1] = 0; a[2] = 2; a[3] = 2;

    for(ll i=4;i<(ll)1e5+1;i++){
        a[i] = (a[i-1]%MOD+a[i-2]%MOD)%MOD;
    }

    ll prefix[(ll)1e5+1];
    prefix[0] = 0; prefix[1] = 0;

    ll sum = 0;
    for(ll i=2;i<(ll)1e5+1;i++){
        sum = (sum%MOD+a[i]%MOD)%MOD;
        prefix[i] = sum;
    }


    ll n, m;
    cin >> n >> m;

    ll x = max(n, m);
    ll y = min(n, m);

    ll ans = 2;
    ans += (prefix[x]%MOD+prefix[y]%MOD)%MOD;
    cout << ans;

    return 0;
}