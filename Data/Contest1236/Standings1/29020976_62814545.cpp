#include<bits/stdc++.h>
#define FOR(i,a,b) for (register LL i=(a);i<=(b);i++)
#define For(i,a,b) for (register LL i=(a);i>=(b);i--)
#define mem(i,j) memset(i,j,sizeof(i))
#define GO(u) for (register LL j=f[u];j!=-1;j=nxt[j])
#define fi first
#define se second
#define pb push_back
#define pii pair<LL,LL>
#define MP make_pair
using namespace std;
typedef long long LL;
const LL N=2e5+5;
LL n,m,k,x[N],y[N],a=1,b=1,now=1,cnt=1,hh[2],ll[2];
vector <LL> h[N],l[N];
inline LL read()
{
	LL x=0,f=1;
	char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') {x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return f*x;
}
inline void write(LL x)
{
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+'0');
	return;
}
inline void init()
{
	FOR(i,1,n) h[i].pb(0),h[i].pb(m+1);
	FOR(i,1,m) l[i].pb(0),l[i].pb(n+1);
	FOR(i,1,k) h[x[i]].pb(y[i]),l[y[i]].pb(x[i]);
	FOR(i,1,n) sort(h[i].begin(),h[i].end());
	FOR(i,1,m) sort(l[i].begin(),l[i].end());
	hh[0]=0,hh[1]=n+1;
	ll[0]=0,ll[1]=m+1;
	return;
}
inline void solve()
{
	LL pos;
	while (cnt<n*m-k)
	{
		switch (now)
		{
			case 1:
				pos=upper_bound(h[a].begin(),h[a].end(),b)-h[a].begin();
				pos=h[a][pos];
				pos=min(pos,ll[1]);
				if (pos-b==1) return;
				cnt+=pos-b-1;
				b=pos-1;
				now=2;
				hh[0]=max(hh[0],a);
				break;
			case 2:
				pos=upper_bound(l[b].begin(),l[b].end(),a)-l[b].begin();
				pos=l[b][pos];
				pos=min(pos,hh[1]);
				if (pos-a==1) return;
				cnt+=pos-a-1;
				a=pos-1;
				now=3;
				ll[1]=min(ll[1],b);
				break;
			case 3:
				pos=lower_bound(h[a].begin(),h[a].end(),b)-h[a].begin();
				pos--;
				pos=h[a][pos];
				pos=max(pos,ll[0]);
				if (b-pos==1) return;
				cnt+=b-pos-1;
				b=pos+1;
				now=4;
				hh[1]=min(hh[1],a);
				break;
			case 4:
				pos=lower_bound(l[b].begin(),l[b].end(),a)-l[b].begin();
				pos--;
				pos=l[b][pos];
				pos=max(pos,hh[0]);
				if (a-pos==1) return;
				cnt+=a-pos-1;
				a=pos+1;
				now=1;
				ll[0]=max(ll[0],b);
				break;
		}
	}
	return;
}
int main()
{
	n=read(),m=read(),k=read();
	FOR(i,1,k) x[i]=read(),y[i]=read();
	init();
	solve();
	if (cnt==n*m-k) {printf("Yes\n");exit(0);}
	hh[0]=0,hh[1]=n+1;
	ll[0]=0,ll[1]=m+1;
	a=b=1;
	cnt=1;
	now=2;
	solve();
	if (cnt==n*m-k)printf("Yes\n");
	else printf("No\n");
	return 0;
}
/*
4 2 4
1 2
2 2 
3 2
4 2
*/