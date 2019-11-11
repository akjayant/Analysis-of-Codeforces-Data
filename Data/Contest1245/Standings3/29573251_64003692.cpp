#include <bits/stdc++.h>

/*
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/

#define mp make_pair
#define ll long long
#define ld long double
#define pb push_back
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fs first
#define sc second
#define getfiles ifstream cin("input.txt"); ofstream cout("output.txt");
#define endl '\n'
#define con continue
#define pii pair<int, int>
#define all(x) x.begin(), x.end()

const int INF = 2000000005;
const ll BIG_INF = 2000000000000000005;
const int mod = 1000000007;
const int P = 31;
const ld PI = 3.141592653589793238462643;
const double eps = 1e-9;

using namespace std;

vector< pair<int, int> > dir = {
    {
        -1, 0
    },
    {
        0, 1
    },
    {
        1, 0
    },
    {
        0, -1
    }
};

bool valid(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

mt19937 rng(1999999973);

const int N = 100000 + 50;

int dp[N], ans = 0, n;

signed main() {
    fast_io;


    string s;
    cin >> s;

    n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'w' || s[i] == 'm') {
            cout << 0;
            return 0;
        }
    }

    s = '#' + s;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        if(s[i] == 'n' && s[i - 1] == 'n')
            dp[i] += dp[i - 2];
        if(s[i] == 'u' && s[i - 1] == 'u')
            dp[i] += dp[i - 2];
        dp[i] %= mod;
    }
    cout << dp[n];

    return 0;
}
