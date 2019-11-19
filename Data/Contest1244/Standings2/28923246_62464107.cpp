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
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int x = a / c;
    if (a % c) {
        ++x;
    }
    int y = b / d;
    if (b % d) {
        ++y;
    }
    if (x + y > k) {
        cout << "-1\n";
    } else {
        cout << x << " " << y << "\n";
    }
}

int main() {
    // freopen("moscow.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
