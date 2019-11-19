// Volgograd STU: Zeber
#pragma GCC optimize ("O3")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <random>
#include <ctime>
#include <map>
#include <stack>
#include <bitset>
#include <queue>
#include <cstring>
#include <unordered_map>

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef unsigned char si;

#define mp make_pair
#define pb push_back

using namespace std;
#define PI acos(-1.0)

static const int MAX = 1e5 + 1;
const int MOD = 1e9 + 7;
LL dp[MAX];

void solve() {
    int n, m;
    cin >> n >> m;
    dp[0] = 1;
    dp[1] = 1;
    LL curMx = max(n, m);
    for(int i = 2; i <= curMx; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    cout << ((dp[n] - 1) * 2 + dp[m] * 2) % MOD << endl;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //test(); return 0;
    //cout.setf(ios::fixed);
    //cout.precision(2);

    //time_t cur = time(NULL);
    //freopen("wifi.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //srand(time(NULL));
    int test = 1;
    //cin >> test;
    //scanf("%d", &test); int n = test;
    while (test-- > 0) {
        //cout << "Case #" << n - test << ": ";
        solve();
    }

    //cerr << (time(NULL) - cur) << endl;

    return 0;
}