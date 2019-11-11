#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <bitset>
#include <complex>
#include <deque>
#include <iomanip>
#include <list>
#include <map>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define em emplace_back
#define sqr(x) (x) * (x)
#define sqr(x) ((x) * (x))
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define forb(n, i) for (int i = n - 1; i >= 0; --i)
#define readp(v) cin >> (v).x >> (v).y

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld PI = 3.141592653589793116;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        int a, b, c;
        cin >> n >> a >> b >> c;
        string s;
        cin >> s;
        string t;
        t.resize(s.length());
        int wins = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R') {
                if (b > 0) {
                    --b;
                    ++wins;
                    t[i] = 'P';
                }
            } else if (s[i] == 'P') {
                if (c > 0) {
                    --c;
                    ++wins;
                    t[i] = 'S';
                }
            } else if (s[i] == 'S') {
                if (a > 0) {
                    --a;
                    ++wins;
                    t[i] = 'R';
                }
            }
        }

        if (wins < (n + 1) / 2) {
            cout << "NO\n";
            continue;
        }

        for (int i = 0; i < n; ++i) {
            if (t[i] == char(0)) {
                if (a > 0) {
                    t[i] = 'R';
                    --a;
                } else if (b > 0) {
                    t[i] = 'P';
                    --b;
                } else if (c > 0) {
                    t[i] = 'S';
                    --c;
                }
            }
        }
        cout << "YES\n";
        cout << t << '\n';
    }
}
