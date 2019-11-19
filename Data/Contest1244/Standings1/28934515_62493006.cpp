#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const int N = 2 * 1e5 + 10;
 
int main(){
    //ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll n, p, w, d;
    cin >> n >> p >> w >> d;
    ll gg = __gcd(w, d);
    if(p % gg == 0){
        ll x = p / w, fl = 0;
        for(ll i = x; i >= 0; --i){
            ll wp = (p - i * w) / d;
            if((p - i * w) % d == 0 and i + wp <= n)    return cout << i << " " << wp << " " << n - i - wp, 0;
            if(i + wp > n)  break;
        }
        cout << "-1\n";
    }
    else    cout << "-1\n";
}