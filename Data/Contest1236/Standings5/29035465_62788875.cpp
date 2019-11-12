#include<iostream>

using namespace std;

#define ll long long 


ll dp[110][110][110];

int t;

ll solve(ll aa, ll bb, ll cc)
{
	if(dp[aa][bb][cc] != -1)
		return dp[aa][bb][cc];
	ll ret = 0;
	bool can = false;
	if(aa >= 1 && bb >= 2)
	{
		can = true;
		ret = max(ret, 3 + solve(aa-1, bb - 2, cc));
	}
	if(bb >= 1 && cc >= 2)
	{
		can = true; 
		ret = max(ret, 3 + solve(aa, bb-1, cc-2));
	}
	dp[aa][bb][cc] = ret;
	return ret;
}

int a, b, c;

int main()
{
	cin>>t;
	for(int tt = 1; tt <= t; ++tt)
	{
		for(int i = 0; i <= 100; ++i)
		for(int j = 0; j <= 100; ++j)
		for(int k = 0; k <= 100; ++k)
			dp[i][j][k] = -1;
		
		cin>>a>>b>>c;
		cout<<solve(a, b, c)<<endl;
	
	
	
	}	
}
