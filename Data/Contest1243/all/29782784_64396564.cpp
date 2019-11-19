#include <bits/stdc++.h>
#define fi first
#define se second
using ll = long long;
using namespace std;

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    int ans = 0;
    ll N = n;
    vector<ll> p;
    for(ll i = 2; i * i <= N; ++i) {
        if(n % i == 0) {
            p.push_back(i);
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1) p.push_back(n);
    if(p.size() > 1) cout << 1 << endl;
    else if(p.size() == 1) cout << p.back() << endl;
    else cout << N << endl;
}
