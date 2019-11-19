#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll vis[2][1007];
ll ans=0;
ll n;
set<ll> :: iterator itr;
string str;
ll v;
void dfs(ll i,ll j, set<ll>s)
{
//	cout << str << "\n";
	if(j>=0 && j<(n*2) && i>=0 && i<2 && s.find(j)==s.end())
	{
		ll flag=0;
		if(i==0)
		{
			if(s.find(j)==s.end())
			{
				flag=1;
				s.insert(j);
				if(str[j]=='1')
					{dfs(i+1,j+n,s);}
				if(j>0)
					dfs(i,j-1,s);
				if(j<(n-1))
					dfs(i,j+1,s);	
			}
		}
		else
		{
			if(s.find(j)==s.end())
			{
				flag=1;
				s.insert(j);
				if(str[j-n]=='1')
				{
					dfs(i-1,j-n,s);
				}
				if(j>n)
					dfs(i,j-1,s);
				if(j<(n*2-1))
					dfs(i,j+1,s);
			}
		}
		v=s.size();
		if(flag==0)
			ans=max(ans,v);
	}
	v=s.size();
	ans=max(ans,v);
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll test,i,j,k;
	cin >> test;
	while(test--)
	{
		cin >> n;
		ans=0;		
		cin >> str;
		ans=n;
		for(i=0;i<n;i++)
		{
			if(str[i]=='1')
			{
				j=n-i;
				k=i+1;
				j*=2;
				k*=2;
				ans=max(ans,j);
				ans=max(ans,k);
			}
		}
		/*for(i=0;i<2;i++)
		{
			if(ans==n*2)
				break;
			for(j=0;j<n;j++)
			{
				if(ans==n*2)
					break;
				set<ll>s;
				if(i==1)
					dfs(i,j+n,s);
				else
					dfs(i,j,s);
			}
		}*/
		cout << ans << "\n";
	}
	return 0;
}