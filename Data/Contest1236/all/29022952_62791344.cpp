#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;

ll quickpow(ll a, ll b){
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
int main()
{
    ll n, m;
    cin >> n >> m;
    cout << quickpow((quickpow(2LL, m) - 1 + mod) % mod, n * 1LL) << endl;
}
