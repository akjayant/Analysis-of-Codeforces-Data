#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
	int out=0,fh=1;
	char jp=getchar();
	while ((jp>'9'||jp<'0')&&jp!='-')
		jp=getchar();
	if (jp=='-')
		fh=-1,jp=getchar();
	while (jp>='0'&&jp<='9')
		out=out*10+jp-'0',jp=getchar();
	return out*fh;
}
const int K=32;
ll f[K][2][2];
int x,y;
int kp(int s,int i)
{
	return (s>>i)&1;
}
ll dfs(int k,bool lx,bool ly)
{
	if(k<0)
		return 1LL;
	if(f[k][lx][ly]!=-1)
		return f[k][lx][ly];
	ll &res=f[k][lx][ly];
	res=0;
	int maxx=lx?kp(x,k):1;
	int maxy=ly?kp(y,k):1;
	for(int i=0;i<=maxx;++i)
		for(int j=0;j<=maxy;++j)
			if(i+j<2)
				res+=dfs(k-1,lx&&i==maxx,ly&&j==maxy);
	return res;
}
ll calc(int l,int r)
{
	memset(f,-1,sizeof f);
	x=l,y=r;
	if(x<0 || y<0)
		return 0;
	return dfs(31,true,true);
}
void solve()
{
	int l=read(),r=read();
	ll ans=calc(r,r)-2LL*calc(r,l-1)+calc(l-1,l-1);
	cout<<ans<<endl;
}
int main()
{
	int T=read();
	while(T--)
		solve();
	return 0;
}
