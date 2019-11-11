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
const ll MOD = 1E9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    for (auto cur : s) {
        if ((cur == 'm') || (cur == 'w')) {
            cout << "0\n";
            return 0;
        }
    }

    int n = s.length();
    ll prev = 1, ans = 1;
    for (int i = 1; i < n; ++i) {
        ll tmp = ans;
        if (((s[i] == 'u') || (s[i] == 'n')) && (s[i] == s[i - 1])) {
            ans = (ans + prev) % MOD;
        }
        prev = tmp;
    }
    cout << ans << '\n';
}
