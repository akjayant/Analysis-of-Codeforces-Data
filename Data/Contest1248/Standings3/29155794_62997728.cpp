#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5+10;
const int MOD = 1e9+7;
int n, m;
long long dp[MAX][2][3];

long long precalc(int t, int left, int count){
	if(t == 0) return 1;
	if(dp[t][left][count] != -1) return dp[t][left][count];
	long long sol = 0;
	if(left == 0){
		if(count == 1)
			sol = sol + precalc(t-1, 0, 2) + precalc(t-1, 1, 1) % MOD;
		else
			sol = sol + precalc(t-1, 1, 1) % MOD;
	}else{
		if(count == 1)
			sol = sol + precalc(t-1, 1, 2) + precalc(t-1, 0, 1) % MOD;
		else
			sol = sol + precalc(t-1, 0, 1) % MOD;
	}
	return dp[t][left][count] = sol;
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	memset(dp, -1, sizeof dp);

	cout << (2 * (precalc(n-1, 0, 1) - 1 + MOD) % MOD + 2 * precalc(m-1, 0, 1) % MOD) % MOD << '\n';

	return 0;
}