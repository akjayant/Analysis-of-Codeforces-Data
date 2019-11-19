#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long LL;
const int mod = 1e9 + 7;

int x, y;
LL dp[maxn][3];

int main(){
	dp[1][1] = 1; dp[2][2] = 1; dp[2][1] = 1;
	for(int i = 3; i <= maxn; ++i){
		dp[i][1] = (dp[i - 1][1] + dp[i - 1][2]) % mod;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][2]) % mod;
	}
	cin >> x >> y;

	cout << (2LL * (dp[x][1] + dp[x][2] + dp[y][1] + dp[y][2] - 1) % mod) % mod << endl;
	return 0;
}