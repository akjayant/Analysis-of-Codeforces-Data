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
const ld INF = 1e20;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
//const double PI = acos(-1);


void solve() {
    int n;
    cin >> n;
    int l = 1, r = n * n;
    int res = (n / 2) * n + 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            cout << l << " ";
            ++l;
        }
        for (int j = 0; j < n / 2; ++j) {
            cout << r << " ";
            --r;
        }
        if (n % 2) {
            cout << res;
            ++res;
        }
        cout << "\n";
    }
}

int main() {
    // freopen("moscow.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();
    return 0;
}

