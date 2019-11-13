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
    
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        string s; cin >> s;
        string t; cin >> t;
        int p = -1, q = -1, c = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] != t[i]) {
                if(p == -1) p = i;
                else if(q == -1) q = i;
                c++;
            }
        }
        if(c == 0 || c == 2 && s[p] == s[q] && t[p] == t[q]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }







    return 0;
    
}
