#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll > > vec;
vector<ll > temp;
ll vis[100007];
vector<ll>v;
ll mini=9999999999999999;
void dfs(ll index)
{
	if(vis[index]==0)
	{
		v.push_back(index);
		vis[index]=1;
		for(ll i=0;i<vec[index].size();i++)
		{
			dfs(vec[index][i]);
		}
	}
	return;
}
int main()
{
	ll test,n,i,j,k;
	cin >> n;
	for(i=0;i<=n;i++)
	{
		vec.push_back(temp);
		vis[i]=0;
	}
	ll a[n+1],b[n+1],c[n+1];
	for(i=1;i<=n;i++)
		cin >> a[i];
	for(i=1;i<=n;i++)
		cin >> b[i];
	for(i=1;i<=n;i++)
		cin >> c[i];
	ll flag=0;
	for(i=1;i<n;i++)
	{
		cin >> j >> k;
		vec[j].push_back(k);
		vec[k].push_back(j);
		if(vec[j].size()>2|| vec[k].size()>2)
		{
			flag=1;
		}
	}
	if(flag==1)
	{
		cout << "-1\n";
		return 0;
	}
	for(i=1;i<=n;i++)
	{	
		if(vec[i].size()==1)
		{
			dfs(i);
			break;
		}
	}
	ll cur=0,type=0;
	ll ans[n+1];
	cur=0;
	for(i=0;i<v.size();i++)
	{
		if(i%3==0)
			cur=cur+a[v[i]];
		if(i%3==1)
			cur=cur+b[v[i]];
		if(i%3==2)
			cur=cur+c[v[i]];
	}
	if(cur<mini)
	{
		mini=cur;
		type=1;
	}
	cur=0;
	for(i=0;i<v.size();i++)
	{
		if(i%3==0)
			cur=cur+a[v[i]];
		if(i%3==1)
			cur=cur+c[v[i]];
		if(i%3==2)
			cur=cur+b[v[i]];
	}
	if(cur<mini)
	{
		mini=cur;
		type=2;
	}
	cur=0;
	for(i=0;i<v.size();i++)
	{
		if(i%3==0)
			cur=cur+b[v[i]];
		if(i%3==1)
			cur=cur+a[v[i]];
		if(i%3==2)
			cur=cur+c[v[i]];
	}
	if(cur<mini)
	{
		mini=cur;
		type=3;
	}
	cur=0;
	for(i=0;i<v.size();i++)
	{
		if(i%3==0)
			cur=cur+b[v[i]];
		if(i%3==1)
			cur=cur+c[v[i]];
		if(i%3==2)
			cur=cur+a[v[i]];
	}
	if(cur<mini)
	{
		mini=cur;
		type=4;
	}
	cur=0;
	for(i=0;i<v.size();i++)
	{
		if(i%3==0)
			cur=cur+c[v[i]];
		if(i%3==1)
			cur=cur+a[v[i]];
		if(i%3==2)
			cur=cur+b[v[i]];
	}
	if(cur<mini)
	{
		mini=cur;
		type=5;
	}
	cur=0;
	for(i=0;i<v.size();i++)
	{
		if(i%3==0)
			cur=cur+c[v[i]];
		if(i%3==1)
			cur=cur+b[v[i]];
		if(i%3==2)
			cur=cur+a[v[i]];
	}
	if(cur<mini)
	{
		mini=cur;
		type=6;
	}
	cout << mini << "\n";
	if(type==1)
	{
		for(i=0;i<v.size();i++)
		{
			if(i%3==0)
				ans[v[i]]=1;
			if(i%3==1)
				ans[v[i]]=2;
			if(i%3==2)
				ans[v[i]]=3;
		}
	}
	if(type==2)
	{
		for(i=0;i<v.size();i++)
		{
			if(i%3==0)
				ans[v[i]]=1;
			if(i%3==1)
				ans[v[i]]=3;
			if(i%3==2)
				ans[v[i]]=2;
		}
	}
	if(type==3)
	{
		for(i=0;i<v.size();i++)
		{
			if(i%3==0)
				ans[v[i]]=2;
			if(i%3==1)
				ans[v[i]]=1;
			if(i%3==2)
				ans[v[i]]=3;
		}
	}
	if(type==4)
	{
		for(i=0;i<v.size();i++)
		{
			if(i%3==0)
				ans[v[i]]=2;
			if(i%3==1)
				ans[v[i]]=3;
			if(i%3==2)
				ans[v[i]]=1;
		}
	}
	if(type==5)
	{
		for(i=0;i<v.size();i++)
		{
			if(i%3==0)
				ans[v[i]]=3;
			if(i%3==1)
				ans[v[i]]=1;
			if(i%3==2)
				ans[v[i]]=2;
		}
	}
	if(type==6)
	{
		for(i=0;i<v.size();i++)
		{
			if(i%3==0)
				ans[v[i]]=3;
			if(i%3==1)
				ans[v[i]]=2;
			if(i%3==2)
				ans[v[i]]=1;
		}
	}
	for(i=1;i<=n;i++)
		cout << ans[i] << " ";
	cout << "\n";
	return 0;
}