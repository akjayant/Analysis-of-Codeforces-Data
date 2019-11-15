#include<iostream>
#include<vector>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define arep(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;

int calc_gcd(int x, int y) {
    if (y == 0) return x;
    return calc_gcd(y, x % y);
}

void solve() {
    int A, B;
    cin >> A >> B;
    if (calc_gcd(A, B) == 1) cout << "Finite" << endl;
    else cout << "Infinite" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    rep(i, 0, T) solve();
    return 0;
}