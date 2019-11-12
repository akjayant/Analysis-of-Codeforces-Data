#include<iostream>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define arep(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

ll calc_pow(ll x, ll y) {
    ll z = 1;
    while (y > 0) {
        if (y & 1) {
            z = (z * x) % MOD;
        }
        x = (x * x) % MOD;
        y /= 2;
    }
    return z;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    cout << calc_pow(calc_pow(2, M) - 1, N) << endl;
    return 0;
}