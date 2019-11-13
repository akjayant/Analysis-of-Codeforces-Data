#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <ctime>
#include <cassert>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>
#include <sstream>
#include <stack>
#include <queue>
#include <numeric>
#include <iterator>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define sz(c) ((int)c.size())
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define x first
#define y second

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;

const int N = int(1e6) + 111;
const int INF = int(1e9) + 111;
const ll LINF = ll(1e18) + 111;
const ld EPS = 1e-7;
const ld PI = 3.141592653589793238462643;
const ll MOD = ll(1e9) + 7;
const int M = int(1e6) + 111;
const int P = int(1e6) + 3;

template<class T> void chmin(T& a, const T& b) { if (a > b) a = b; }
template<class T> void chmax(T& a, const T& b) { if (a < b) a = b; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T abs(T a) { return a >= 0 ? a : -a; }

int n;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s, t;
        int n;
        cin >> n;
        cin >> s >> t;
        vector <int> a;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                a.pb(i);
            }
        }
        if (sz(a) != 2) {
            cout << "No" << endl;
            continue;
        }
        swap(s[a[0]], t[a[1]]);
        if (s == t) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
