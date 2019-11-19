#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

#define int long long

const int INF = 1e18;

using namespace std;

void solve() {
    int n;
    cin >> n;
    set<int> p;
    int m = n;
    for (int i = 2; i * i <= m; i++) {
        while (n % i == 0) {
            p.insert(i);
            n /= i;
        }
    }
    if (n > 1) p.insert(n);
    if (p.size() == 1) {
        cout << *p.begin();
    } else {
        cout << 1;
    }
}

int32_t main() {
#ifdef local
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int q = 1;
    while (q --) solve();
    return 0;
}