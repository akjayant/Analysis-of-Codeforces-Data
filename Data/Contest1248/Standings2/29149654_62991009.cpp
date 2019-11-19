#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, m;
vector <int> dp;
long long mod = 1e9 + 7;
long long answer;

void In()
{
	cin >> n >> m;
	dp.resize(max(n,m) + 1);
}

void FillDP()
{
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < dp.size(); i++)
	{
		dp[i] = (dp[i-2] + dp[i-1]) % mod;
	}	
}

void Solve()
{
	FillDP();
	answer = ( (dp[m] + dp[n] - 1 + mod) % mod * 2) % mod;  
}

void Out()
{
	cout << answer << endl;
}

int main()
{__
	In();
	Solve();
	Out();
}