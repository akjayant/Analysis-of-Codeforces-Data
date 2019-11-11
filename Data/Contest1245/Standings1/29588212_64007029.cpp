#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;

string str;
int dp[100001];
int vis[100001];

int solve(int x)
{
	if(x == str.size())
		return 1;
	if(str[x] == 'm' || str[x] == 'w')
		return 0;
	if(vis[x])
		return dp[x];
	vis[x] = 1;
	int ret = solve(x+1);
	if(x < str.size()-1 && (str[x] == 'u' || str[x] == 'n') && str[x+1] == str[x])
		ret += solve(x+2);
	return dp[x] = ret%MOD;
}

main()
{
	cin >> str;
	printf("%d\n", solve(0));
	return 0;
}
