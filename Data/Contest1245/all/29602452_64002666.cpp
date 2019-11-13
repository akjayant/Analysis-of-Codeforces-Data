#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define mod 1000000007
#define int long long
#define ll long long
#define EPS 0.00000000000001
#define ld long double
#define inf 1000000002
#define N 500000

string s;
int n;
int dp[N];

int rec(int i)
{
	if(i == n)
		return 1;
	if(dp[i] == -1)
	{
		int& ans = dp[i];
		ans = 0;
		if(s[i] == 'w' or s[i] == 'm')
			return ans;
		if(s[i] == 'u')
		{
			if(i + 1 < n and s[i + 1] == 'u')
				ans += rec(i + 2);
			ans += rec(i + 1);
			if(ans >= mod)
				ans -= mod;
			return ans;
		}
		else
			if(s[i] == 'n')
			{
				if(i + 1 < n and s[i + 1] == 'n')
					ans += rec(i + 2);
				ans += rec(i + 1);
				if(ans >= mod)
					ans -= mod;
				return ans;
			}
			else
				return dp[i] = rec(i  + 1);
	}
	else
		return dp[i];
}

int32_t main()
{
	IOS;
	#ifndef ONLINE_JUDGE
    freopen("int.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    memset(dp,-1,sizeof(dp));
   	cin >> s;
   	n = s.length();
   	cout << rec(0);

	return 0;
}