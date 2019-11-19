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

int t;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //ifstream cin("dinner.in");
    //ofstream cout("dinner.out")
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = n;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ans++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ans = max(ans, i + 1 + i + 1);
                ans = max(ans, i + 1 + n - i);
                ans = max(ans, n - i + n - i);
                ans = max(ans, n - i + i + 1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
