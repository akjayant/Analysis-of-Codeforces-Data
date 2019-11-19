#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <bitset>
using namespace std;


long long dp[100011][2];

long long mod = 1e9+7;

long long fun(int n, int m)
{
    dp[0][0] = 2;
    dp[1][0] = 2;
    dp[1][1] = 2;
    for (int i = 2; i < n; i++)
    {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
        dp[i][1] = (dp[i - 2][0] + dp[i - 2][1]) % mod;
    }
    return (dp[n - 1][0] + dp[n - 1][1]) % mod;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    long long ans = fun(n, m) + fun(m, n) - 2;
    if (ans < 0)
        ans += mod;
    ans %= mod;
    cout << ans;


	return 0;
}
