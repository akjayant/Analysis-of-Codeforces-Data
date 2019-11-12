#include<bits/stdc++.h>
#define pb push_back
#define int long long
#define M 1000000007
using namespace std;
const int inf=4e18;
int dp[200000];
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int k;cin>>k;
	while(k--)
	{
		int n,i,pos1=-1,pos2=-1;cin>>n;
		string s,t;cin>>s>>t;
		bool b=1;
		for(i=0;i<n;i++)
		{
			if(s[i]!=t[i])
			{
				pos1=i;
				break;
			}
		}
		i++;
		for(;i<n;i++)
		{
			if(s[i]!=t[i])
			{
				pos2=i;
				break;
			}
		}
		i++;
		for(;i<n;i++)
		{
			if(s[i]!=t[i])
			{
				b=0;
				break;
			}
		}
		if(pos1==-1)
			b=0;
		if(s[pos1]!=s[pos2]||t[pos2]!=t[pos1])
			b=0;
		if(b)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}
