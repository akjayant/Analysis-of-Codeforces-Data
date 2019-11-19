#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> divs(ll n) {
   vector<ll> res;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            while (n % i == 0)
                n /= i;
        }   
    }
    if (n > 1)
        res.push_back(n);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> v = divs(n);
    cout << (v.size() == 1? v[0]: 1) << "\n";
    return 0;
}