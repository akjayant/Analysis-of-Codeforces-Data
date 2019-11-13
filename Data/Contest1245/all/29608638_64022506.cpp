//#pragma GCC optimize("Ofast")
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <bitset>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define zy 2333333
#define bql 2147483647
using namespace std;
const int mod=1e9+7;
long long dp[100005];
string s;
int main()
{
	fast;
	cin>>s;
	dp[0]=1,dp[1]=1;
	for (int i=0;i<=s.size()-1;i++)
	{
		if (s[i]=='m' || s[i]=='w')
		{
			cout<<0<<endl;
			return 0;
		}
	}
	for (int i=1;i<=s.size()-1;i++)
	{
		if (s[i]=='u' && s[i-1]=='u' || s[i]=='n' && s[i-1]=='n')
		{
			dp[i+1]=(dp[i]+dp[i-1])%mod;
		}
		else
			dp[i+1]=dp[i];
	}
	cout<<dp[s.size()]<<endl;
	return 0;
}