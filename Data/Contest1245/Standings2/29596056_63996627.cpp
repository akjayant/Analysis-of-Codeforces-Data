#include<bits/stdc++.h>

using namespace std;
using ll = int64_t;

#define fo(i,a,z) for(ll i=(a);i<(z);++i)
#define MAX 100005

ll t, a, b, ans;

ll gcd(ll a, ll b) {
    if(a > b) return gcd(b,a);
    if(a <= 0) return b;
    return gcd(b % a, a);
}

int main() {
    cin >> t;
    fo(i,0,t) {
        cin >> a >> b;
        if (gcd(a,b) == 1) cout << "Finite\n";
        else cout << "Infinite\n";
    }
    return 0;
}
