#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <bitset>
#include <stack>
#include <chrono>
#include <random>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define ll long long
#define MOD 1000000007 
#define INF 1000000000000000000
#define uid uniform_int_distribution <int>
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
// Read the question carefully and see all the given sample tests
// Think about the correctness before implementing

ll power(ll a, ll b)
{
	ll res = 1;
	while(b != 0)
	{
		if(b & 1)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		b /= 2;
	}
	return res;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector <vector<ll>> dp(max(n, m) + 1, vector<ll>(2, 0));
	dp[0][0] = 1;
	dp[0][1] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= max(n, m); i++)
	{
		dp[i][0] = (dp[i - 1][1] + dp[i - 2][1]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 2][0]) % MOD;
	}
	//cout << dp[m][0] + dp[m][1] << "\n";
	cout << (dp[m][0] + dp[m][1] - 2 + dp[n][0] + dp[n][1]) % MOD; 
}
