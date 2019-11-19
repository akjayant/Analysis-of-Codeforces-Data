#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstdio>

#define fastIO do { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); } while (false);

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void solve() {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;

    int x = (a + c - 1) / c;
    int y = (b + d - 1) / d;

    if (x + y <= k) {
        cout << x << " " << y << endl;

    } else {
        cout << -1 << endl;
    }
}

int main() {
    fastIO;

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}