#include<iostream>
#include<vector>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define arep(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;

vector<ll> factorize(ll x) {
    vector<ll> res;
    for (ll i = 2; i * i <= x; ++i) {
        if (x % i) continue;
        res.push_back(i);
        while (x % i == 0) {
            x /= i;
        }
    }
    if (x != 1) res.push_back(x);
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> d = factorize(N);
    if (d.size() == 1) cout << d[0] << endl;
    else cout << 1 << endl;
    return 0;
}