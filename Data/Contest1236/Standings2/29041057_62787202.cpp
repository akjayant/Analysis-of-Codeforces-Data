#include <bits/stdc++.h>

using namespace std;

using ll =  long long;
using Pll = pair<ll, ll>;
using Pii = pair<int, int>;

constexpr ll MOD = 1000000007;
constexpr long double EPS = 1e-10;
constexpr int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int a_ = a, b_ = b, c_ = c;
    int ans1 = 0;
    while(a >= 1 && b >= 2) {
        ans1 += 3;
        a -= 1;
        b -= 2;
    }
    while(b >= 1 && c >= 2) {
        ans1 += 3;
        b -= 1;
        c -= 2;
    }

    int ans2 = 0;
    a = a_;
    b = b_;
    c = c_;
    while(b >= 1 && c >= 2) {
        ans2 += 3;
        b -= 1;
        c -= 2;
    }
    while(a >= 1 && b >= 2) {
        ans2 += 3;
        a -= 1;
        b -= 2;
    }

    cout << max(ans1, ans2) << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
