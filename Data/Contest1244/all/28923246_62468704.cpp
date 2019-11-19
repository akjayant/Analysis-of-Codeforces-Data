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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = 0;
    while (l < n && s[l] == '0') {
        ++l;
    }
    int r = n - 1;
    while (r >= 0 && s[r] == '0') {
        --r;
    }
    if (l == n) {
        cout << n << "\n";
        return;
    }
    int x = max(n - l, r + 1);
    cout << 2 * x << "\n";

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
