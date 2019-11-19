#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t,l,r;
ll f[40][2][2],a,b;
ll dfs(int pos,int f1,int f2)
{
	if(pos==-1) return 1;
	if(~f[pos][f1][f2]) return f[pos][f1][f2];
	ll t=f[pos][f1][f2]; t=0;
	if(f1&&f2)
	{
		if((a>>pos&1)) t+=dfs(pos-1,f1,f2&((b>>pos&1)==0));
		if((b>>pos&1)) t+=dfs(pos-1,f1&((a>>pos&1)==0),f2);
		t+=dfs(pos-1,f1&((a>>pos&1)==0),f2&((b>>pos&1)==0));
	}
	if((!f1)&&f2)
	{
		if((b>>pos&1)) t+=dfs(pos-1,0,f2);
		t+=dfs(pos-1,0,f2&((b>>pos&1)==0))*2;
	}
	if(f1&&!f2)
	{
		if((a>>pos&1)) t+=dfs(pos-1,f1,0);
		t+=dfs(pos-1,f1&((a>>pos&1)==0),0)*2;
	}
	if(f1+f2==0)
		t+=dfs(pos-1,0,0)*3;
	return t;
}
ll ans=0;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&l,&r);
		memset(f,-1,sizeof(f));
		a=r,b=r,ans+=dfs(30,1,1);
		if(l>0)
		{
			memset(f,-1,sizeof(f));
			a=r,b=l-1,ans-=dfs(30,1,1)*2;
			memset(f,-1,sizeof(f));
			a=l-1,b=l-1,ans+=dfs(30,1,1);			
		}
		printf("%lld\n",ans),ans=0;
	}
	return 0;
}