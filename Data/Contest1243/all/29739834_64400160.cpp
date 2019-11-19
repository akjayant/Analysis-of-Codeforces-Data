#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>
#include <stack>
#include <cmath>
#include <deque>
#include <queue>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void io_optimize() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    io_optimize();
    ll n;
    cin >> n;
    vector<ll> dvs;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0 && i * i != n) {
            dvs.push_back(i);
            dvs.push_back(n / i);
        }
        else if (n % i == 0) {
            dvs.push_back(i);
        }
    }
    sort(dvs.begin(), dvs.end());
    ll ans = dvs.back();
    for (int i = dvs.size() - 2; i > 0; i--) {
        ans = gcd(ans, dvs[i]);
    }
    cout << ans << '\n';
    return 0;
}