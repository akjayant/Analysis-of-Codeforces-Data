#include<stdio.h>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b;
int t,n,m; 
ll ans,dana,shuanga,danb,shuangb;
int main()
{
	cin>>t;
	for(int ii=1;ii<=t;ii++)
	{
		ans=0,dana=0,shuanga=0,danb=0,shuangb=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
		cin>>a;
		if(a%2==0)shuanga++;
		else
		dana++;
	}
		cin>>m;
		for(int i=1;i<=m;i++)
		{
		cin>>b;
		if(b%2==0)shuangb++;
		else
		danb++;
	}
		ans=dana*danb+shuanga*shuangb;
		cout<<ans<<endl;	
	}
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
	return 0;
}
