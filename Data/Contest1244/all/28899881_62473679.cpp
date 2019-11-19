#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <deque>
#include <queue>
#include <set>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <assert.h>
#include <random>
#include <sstream>
#include <clocale>
#include <cstring>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll MOD = 1e9 + 7;
const ll STRANGE_MOD = 998244353;
const int N = int(3e5) + 111;
const int INF = int(1e9) + 111;
const ll LINF = ll(1e18) + 111;
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) int(v.size())
#define x first
#define y second
using namespace std;

ll n, p, w, d;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //ifstream cin("dinner.in");
    //ofstream cout("dinner.out")
    cin >> n >> p >> w >> d;
    ll x, y;
    x = p / w;
    for (int it = 0; it < 100000 && x >= 0; it++, x--) {
        if ((p - x * w) % d == 0) {
            y = (p - x * w) / d;
            if (x + y <= n) {
                cout << x << " " << y << " " << n - x - y;
                return 0;
            }
        }
    }
    y = p / d;
    for (int it = 0; it < 100000 && y >= 0; it++, y--) {
        if ((p - y * d) % w == 0) {
            x = (p - y * d) / w;
            if (x + y <= n) {
                cout << x << " " << y << " " << n - x - y;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}
