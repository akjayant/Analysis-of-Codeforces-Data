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

int n;
ll k;
ll a[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //ifstream cin("dinner.in");
    //ofstream cout("dinner.out")
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int l = 0;
    int r = n - 1;
    ll ans = INF;
    for (int i = 0; i < n; i++) {
        while (l < n - 1 && a[l] == a[l + 1]) {
            l++;
        }
        while (r > 0 && a[r] == a[r - 1]) {
            r--;
        }
        if (l == n - 1 || r < l) {
            cout << 0;
            return 0;
        }
        ll cnt1 = l + 1;
        ll cnt2 = n - r;
        if (cnt1 < cnt2) {
            if ((a[l + 1] - a[l]) * cnt1 < k) {
                k -= (a[l + 1] - a[l]) * cnt1;
                a[l] = a[l + 1];
            } else {
                cout << a[r] - (a[l] + k / cnt1);
                return 0;
            }
        } else {
            if ((a[r] - a[r - 1]) * cnt2 < k) {
                k -= (a[r] - a[r - 1]) * cnt2;
                a[r] = a[r - 1];
            } else {
                cout << (a[r] - k / cnt2) - (a[l]);
                return 0;
            }
        }
    }
    return 0;
}
