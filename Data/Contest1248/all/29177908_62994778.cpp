#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int mod = 1e9 + 7;

long long dp[maxn][3];//dp[第i位][最后一次几个] 有几种可能

int main(){
	dp[1][1] = 1, dp[2][2] = 1, dp[2][1] = 1;
	for(int i = 3 ; i <= 100000 ; i++){
		dp[i][1] = (dp[i - 1][1] + dp[i - 1][2]) % mod;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][2]) % mod;
	}

	long long x,y;cin >>x >>y;


	cout << (2 * (dp[x][1] + dp[x][2] + dp[y][1] + dp[y][2] - 1)) % mod<<endl;
}