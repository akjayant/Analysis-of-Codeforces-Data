#include <bits/stdc++.h>
#define C 1000000007
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int N,M;
	cin>>N>>M;
	long long dp[100000][2];
	dp[0][0]=1;
	dp[0][1]=1;
	dp[1][0]=2;
	dp[1][1]=2;
	for(int i=2;i<max(N,M);i++)
	{
		dp[i][0]=(dp[i-1][1] + dp[i-2][1])%C;
		dp[i][1]=(dp[i-1][0] + dp[i-2][0])%C;
	}
	long long total1=(dp[M-1][0] + dp[M-1][1])%C, total2=(dp[N-1][0] + dp[N-1][1])%C;
	long long ans=(((total1-2+C)%C) + (total2)%C)%C;
	cout<<ans<<endl;
}
