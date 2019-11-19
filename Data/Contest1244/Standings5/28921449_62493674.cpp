#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define max max1
#include<vector>
vector < ll > graph[100005];
ll bb[100005];
void dfs(ll i, ll p, ll count){
	bb[count]=i;
	for(ll j=0;j<graph[i].size();j++)
	{
		if(graph[i][j]!=p)
		{
			dfs(graph[i][j],i,count+1);
		}
	}
}
int main()
{
	ll n;
	cin>>n;
	ll c1[n+1];
	ll c2[n+1];
	ll c3[n+1];
	ll i;
	for(i=1;i<=n;i++)
	{
		cin>>c1[i];
	}
	for(i=1;i<=n;i++)
	{
		cin>>c2[i];
	}
	for(i=1;i<=n;i++)
	{
		cin>>c3[i];
	}
	for(i=0;i<n-1;i++)
	{
		ll a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(i=1;i<=n;i++)
	{
		if(graph[i].size()>2)
		{
			cout<<"-1";
			return 0;
		}
	}
	ll mm=0;
	for(i=1;i<=n;i++)
	{
		if(graph[i].size()==1)
		{
			mm=i;
			break;
		}
	}
	dfs(mm,0,1);
	ll max=0;
	ll ans=0;
	//123 132 231 213 312 321 
	for(i=1;i<n+1;i++)
	{
		if(i%3==0)
		{
			ans=ans+c1[bb[i]];
		}
		else if(i%3==1)
		{
			ans=ans+c2[bb[i]];
		}
		else {
			ans=ans+c3[bb[i]];
		}
	}
	max=ans;
	ll track=1;
	ans=0;
	//123 132 231 213 312 321 
	for(i=1;i<n+1;i++)
	{
		if(i%3==0)
		{
			ans=ans+c1[bb[i]];
		}
		else if(i%3==1)
		{
			ans=ans+c3[bb[i]];
		}
		else {
			ans=ans+c2[bb[i]];
		}
	}
	if(max>ans)
	{
		max=ans;
		track=2;
	}
	ans=0;
	//123 132 231 213 312 321 
	for(i=1;i<n+1;i++)
	{
		if(i%3==0)
		{
			ans=ans+c2[bb[i]];
		}
		else if(i%3==1)
		{
			ans=ans+c3[bb[i]];
		}
		else {
			ans=ans+c1[bb[i]];
		}
	}
	if(max>ans)
	{
		max=ans;
		track=3;
	}
	ans=0;
	//123 132 231 213 312 321 
	for(i=1;i<n+1;i++)
	{
		if(i%3==0)
		{
			ans=ans+c2[bb[i]];
		}
		else if(i%3==1)
		{
			ans=ans+c1[bb[i]];
		}
		else {
			ans=ans+c3[bb[i]];
		}
	}
	if(max>ans)
	{
		max=ans;
		track=4;
	}
	ans=0;
	//123 132 231 213 312 321 
	for(i=1;i<n+1;i++)
	{
		if(i%3==0)
		{
			ans=ans+c3[bb[i]];
		}
		else if(i%3==1)
		{
			ans=ans+c1[bb[i]];
		}
		else {
			ans=ans+c2[bb[i]];
		}
	}
	if(max>ans)
	{
		max=ans;
		track=5;
	}
	ans=0;
	
	//123 132 231 213 312 321 
	for(i=1;i<n+1;i++)
	{
		if(i%3==0)
		{
			ans=ans+c3[bb[i]];
		}
		else if(i%3==1)
		{
			ans=ans+c2[bb[i]];
		}
		else {
			ans=ans+c1[bb[i]];
		}
	}
	if(max>ans)
	{
		max=ans;
		track=6;
	}
	ans=0;
	cout<<max<<endl;
	ll ans1[n+1];
	if(track==1)
	{
		//123 132 231 213 312 321 
		for(i=1;i<=n;i++)
		{
			if(i%3==0)
			{
				ans1[bb[i]]=1;
			}
			else if(i%3==1)
			{
				ans1[bb[i]]=2;
			}
			else{
				ans1[bb[i]]=3;
			}
		}
	}
	else if(track==2)
	{
		//123 132 231 213 312 321 
		for(i=1;i<=n;i++)
		{
			if(i%3==0)
			{
				ans1[bb[i]]=1;
			}
			else if(i%3==1)
			{
				ans1[bb[i]]=3;
			}
			else{
				ans1[bb[i]]=2;
			}
		}
	}
	else if(track==3)
	{
		//123 132 231 213 312 321 
		for(i=1;i<=n;i++)
		{
			if(i%3==0)
			{
				ans1[bb[i]]=2;
			}
			else if(i%3==1)
			{
				ans1[bb[i]]=3;
			}
			else{
				ans1[bb[i]]=1;
			}
		}
	}
	else if(track==4)
	{
		//123 132 231 213 312 321 
		for(i=1;i<=n;i++)
		{
			if(i%3==0)
			{
				ans1[bb[i]]=2;
			}
			else if(i%3==1)
			{
				ans1[bb[i]]=1;
			}
			else{
				ans1[bb[i]]=3;
			}
		}
	}
	else if(track==5)
	{
		//123 132 231 213 312 321 
		for(i=1;i<=n;i++)
		{
			if(i%3==0)
			{
				ans1[bb[i]]=3;
			}
			else if(i%3==1)
			{
				ans1[bb[i]]=1;
			}
			else{
				ans1[bb[i]]=2;
			}
		}
	
	}
	else{
		//123 132 231 213 312 321 
		for(i=1;i<=n;i++)
		{
			if(i%3==0)
			{
				ans1[bb[i]]=3;
			}
			else if(i%3==1)
			{
				ans1[bb[i]]=2;
			}
			else{
				ans1[bb[i]]=1;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		cout<<ans1[i]<<" ";
	}
}