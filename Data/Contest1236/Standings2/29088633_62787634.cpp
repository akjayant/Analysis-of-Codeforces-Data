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

ll binPow(ll a, ll n) {
    ll res = 1;
    while (n) {
        if (n % 2) {
            res = res * a % MOD;
            --n;
        } else {
            a = a * a % MOD;
            n /= 2;
        }
    }
    return res;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    ll k = binPow(2, m);
    k = (k + MOD - 1) % MOD;
    cout << binPow(k, n);
}

int main() {
    // freopen("moscow.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();
    return 0;
}

