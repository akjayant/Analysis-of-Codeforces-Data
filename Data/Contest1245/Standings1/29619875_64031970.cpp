#include<bits/stdc++.h>
using namespace std;
#define int long long
int num[40][2];
int f[40][2][2];
int dfs(int d,bool ta,bool tb)
{
	if(f[d][ta][tb]!=-1)
		return f[d][ta][tb];
	int ans=0;
	if(num[d][0]&&num[d][1])
	{
		ans+=dfs(d-1,ta,false);
		ans+=dfs(d-1,false,tb);
		ans+=dfs(d-1,false,false);
	}
	else if(!num[d][0]&&num[d][1])
	{
		if(!ta)
			ans+=dfs(d-1,false,false);
		ans+=dfs(d-1,ta,tb);
		ans+=dfs(d-1,ta,false);
	}
	else if(num[d][0])
	{
		if(!tb)
			ans+=dfs(d-1,false,false);
		ans+=dfs(d-1,ta,tb);
		ans+=dfs(d-1,false,tb);
	}
	else
	{
		if(!ta)
			ans+=dfs(d-1,false,tb);
		if(!tb)
			ans+=dfs(d-1,ta,false);
		ans+=dfs(d-1,ta,tb);
	}
	return f[d][ta][tb]=ans;
}
int calc(int a,int b)
{
	if(a<b)
		swap(a,b);
	if(b<0)
		return 0;
	if(!b)
		return a+1;
	int aa=a,bb=b;
	num[0][0]=num[0][1]=0;
	while(a)
	{
		num[++num[0][0]][0]=a&1;
		a>>=1;
	}
	while(b)
	{
		num[++num[0][1]][1]=b&1;
		b>>=1;
	}
	for(int i=1;i<40;i++)
		f[i][0][0]=f[i][0][1]=f[i][1][0]=f[i][1][1]=-1;
	f[0][0][0]=f[0][0][1]=f[0][1][0]=f[0][1][1]=1;
	int ans=0,tot=0;
	for(int i=num[0][0];i>num[0][1];i--)
		tot=(tot<<1)+num[i][0];
	ans+=tot*dfs(num[0][1],false,true);
	ans+=dfs(num[0][1],true,true);
	return ans;
}
signed main()
{
	int t;
	scanf("%lld",&t);
	while(t--)
	{
		int a,b;
		scanf("%lld %lld",&a,&b);
		printf("%lld\n",calc(b,b)-calc(a-1,b)-calc(b,a-1)+calc(a-1,a-1));
	}
	return 0;
}