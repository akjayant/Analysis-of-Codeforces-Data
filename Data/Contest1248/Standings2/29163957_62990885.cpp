//Author: gkashish

#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define mod 1000000007
#define x first
#define y second


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int n, m;
    cin >> n >> m;
    if (m > n)
        n = n + m - (m = n);

    long long int dp[n][2][2];
    dp[0][0][0] = 1;
    dp[0][1][0] = 1;
    dp[0][0][1] = 0;
    dp[0][1][1] = 0;
    for (int i = 1; i < n; i++) {
        dp[i][0][0] = (dp[i - 1][1][0] + dp[i - 1][1][1]) % mod;
        dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1]) % mod;
        dp[i][0][1] = dp[i - 1][0][0];
        dp[i][1][1] = dp[i - 1][1][0];
    }
    cout << (dp[n - 1][0][0] + dp[n - 1][0][1] + dp[n - 1][1][1] + dp[n - 1][1][0] +
             dp[m - 1][0][0] + dp[m - 1][0][1] + dp[m - 1][1][1] + dp[m - 1][1][0] - 2) % mod;

    return 0;
}
