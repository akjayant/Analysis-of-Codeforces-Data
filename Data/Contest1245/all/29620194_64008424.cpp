/*#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")*/
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define Str(x) to_string(x)
#define len(s) (int)s.size()
#define int long long
typedef long long ll;
typedef long double lld;
typedef string str;
typedef unsigned long long ull;

int mod = 1e9 + 7;

int dp[200000];

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < 2e5; i++) {
        dp[i] = dp[i-2] + dp[i-1];
        dp[i] %= mod;
    }
    int ans = 1;
    string s;
    cin >> s;
    char c = s[0];
    int cnt = 1;
    for (auto it : s) {
        if (it == 'm' || it == 'w') {
            cout << 0;
            return 0;
        }
    }
    for (int i = 1;i < len(s); i++) {
        if (s[i] != s[i-1]) {
            if (s[i-1] == 'u' || s[i-1] == 'n') {
                ans *= dp[cnt];
                ans %= mod;
            }
            cnt = 0;
        }
        cnt++;
    }
    if (s[len(s)-1] == 'u' || s[len(s)-1] == 'n') {
        ans *= dp[cnt];
        ans %= mod;
    }
    cout << ans;

    return 0;
}
