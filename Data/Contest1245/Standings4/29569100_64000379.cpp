//Author - Rahil Malhotra
#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int n;
string s;
int cache[100005];
int mod=1e9+7;
int dp(int pos)
{
	if(pos>=n-1)
		return 1;
	if(cache[pos]!=-1)
		return cache[pos];
	if(s[pos]=='n'&&s[pos+1]=='n')
		return cache[pos]=(dp(pos+1)+dp(pos+2))%mod;
	if(s[pos]=='u'&&s[pos+1]=='u')
		return cache[pos]=(dp(pos+1)+dp(pos+2))%mod;
	return cache[pos]=dp(pos+1)%mod;
}
int32_t main()
{
    IOS;
	cin>>s;
	n=s.length();
	int fl=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='m'||s[i]=='w')
			fl=1;
	}
	if(fl)
    	return cout<<0,0;
    memset(cache,-1,sizeof(cache));
    cout<<dp(0);
}