#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ft first
#define sd second
#define pb push_back
using namespace std;
const ll mod = 1e9+7;
ll power(ll a, ll b, ll m = mod) {
    ll x = 1;
    while(b) {
        if(b & 1) {
            x = 1ll * x * a % m;
        }
        a = 1ll * a * a % m;
        b /= 2;
    }
    return x;
}

const int N = 1e6+9;
// int a[N];

signed main() {  
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);    
        
    ll n; cin >> n;
    ll c = 0, p = 1;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            c++;
            p = i;
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1) {
        c++;
        p = n;
    }
    if(c > 1) p = 1;
    cout << p << endl;


    return 0;
    
}
