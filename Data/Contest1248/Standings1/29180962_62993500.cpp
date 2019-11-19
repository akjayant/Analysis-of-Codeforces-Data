#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
const int P = 1e9 + 7;

int dp[100008];
int fib[100008];
int main()
{
	int n, m;
	cin >> n >> m;
	dp[1] = dp[2] = 1;
	for (int i = 3; i < m; ++i) dp[i] = (dp[i - 1] + dp[i - 2]) % P;
	for (int i = 2; i < m; ++i) dp[i] = (dp[i] + dp[i - 1]) % P;
	fib[1] = 1, fib[2] = 2;
	for (int i = 3; i <= n; ++i) fib[i] = (fib[i - 1] + fib[i - 2]) % P;
	printf("%lld\n", 2LL * ((fib[n] + dp[m - 1]) % P) % P);
}