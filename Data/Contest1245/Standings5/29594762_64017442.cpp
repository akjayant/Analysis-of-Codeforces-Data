#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
#include<set>
#include<queue>

using namespace std;

#define MOD 1000000007

int main()
{
	string s;
	cin >> s;
	int n=s.size();
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='m' or s[i]=='w')
		{
			cout << 0 << endl;
			return 0;
		}
	}

	long long dp[200000][3]={};

	// [0] not u not n, [1] u, [2] n

	dp[0][0]=1;

	for(int i=1;i<=s.size();i++)
	{
		dp[i][0]=dp[i-1][0];
		if(s[i-1]=='u')
		{
			dp[i][0]=dp[i-1][1];
			dp[i][1]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
		}
		else if(s[i-1]=='n')
		{
			dp[i][0]=dp[i-1][2];
			dp[i][2]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
		}
		else
		{
			dp[i][0]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
		}
//		cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
		for(int j=0;j<3;j++)
			dp[i][j]%=MOD;
	}

	cout << (dp[n][0]+dp[n][1]+dp[n][2])%MOD << endl;





}
