#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <memory>
#include <initializer_list>
#include <iomanip>
#include <stack>
#include <bitset>
#include <cstdio>
// #include <complex>
#include <random>
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using ld = long double;
// const ll INF = 1e9;
// const ld INF = 1e20;
// const ll MOD = 1e9 + 7;
//const double EPS = 1e-9;
//const double PI = acos(-1);

void solve() {
    ll n, p, w, d;
    cin >> n >> p >> w >> d;
    ll x = p / w;
    for (int i = 0; i <= 1000000; ++i) {
        if (x < 0) {
            break;
        }
        if ((p - x * w) % d == 0) {
            ll y = (p - x * w) / d;
            if (x + y <= n) {
                cout << x << " " << y << " " << n - x - y << "\n";
                return;
            } else {
                break;
            }
        }
        --x;
    }
    cout << -1 << "\n";
}

int main() {
    // freopen("moscow.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();
    return 0;
}
