#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N = 1e3 + 10;

bool isprime(ll n) {
    for(ll i = 2;i * i <= n;++i) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
   // freopen("in","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    if(n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    if(isprime(n)) {
        cout << n << '\n';
        return 0;
    }
    ll t = n;
    vector<ll> p;
    for(ll i = 2;i * i <= n;++i) {
        if(n % i == 0) {
            p.push_back(i);
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1) p.push_back(n);
    if(p.size() == 1) cout << p[0] << '\n';
    else cout << 1 << '\n';
    return 0;
}