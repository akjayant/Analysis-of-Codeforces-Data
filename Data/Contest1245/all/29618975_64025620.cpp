/*
Author: WangXP
Date:
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inc(i,n) for (int i=0;i<n;i++)
#define icc(i,n) for (int i=1;i<=n;i++)
#define rep(i,a,b) for (int i=a;i<b;i++)
#define rpp(i,a,b) for (int i=a;i<=b;i++)
#define dec(i,n) for (int i=n-1;i>=0;i--)
#define dcc(i,n) for (int i=n;i;i--)
ll rd(){
	ll x=0,f=1;char c=getchar();
	while (!isdigit(c) && c!='-') c=getchar();
	if (c=='-') f=-1,c=getchar();
	while (isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*f;
}
const int N=2010;
ll a[N],b[N],fa[N],smin[N],x[N],y[N];

struct Node{
	int a,b; ll x;
	bool operator<(const Node &v)const{return x<v.x;}
}ed[N*N/2];
int edc=0;
int fi(int x){
	if (fa[x]!=x) fa[x]=fi(fa[x]);
	return fa[x];
}
vector<pair<int,int> > sed;
int sel[N], vis[N];

int main(){
	ll ans=0;int n=rd();
	icc(i,n) x[i]=rd(),y[i]=rd();
	icc(i,n) ans+=(a[i]=smin[i]=rd()),fa[i]=i;
	icc(i,n) b[i]=rd();
	icc(i,n) rpp(j,i+1,n){
		ed[edc++]={i,j,1ll*(abs(x[i]-x[j])+abs(y[i]-y[j]))*(b[i]+b[j])};
	}
	sort(ed,ed+edc);
	for (int i=0;i<edc;i++){
		int pa=fi(ed[i].a), pb=fi(ed[i].b);
		ll mi=min(smin[pa],smin[pb]);
		if (pa!=pb && ed[i].x-(max(smin[pa],smin[pb]))<0){
			fa[pa]=pb;
			ans+=ed[i].x-(max(smin[pa],smin[pb]));
			sed.emplace_back(ed[i].a,ed[i].b);
			smin[pb]=mi;
		}
	}
	cout<<ans<<'\n';

	icc(i,n) {vis[fi(i)]=1; if (a[i]==smin[fa[i]]) sel[fa[i]]=i;}
	cout<<accumulate(vis+1,vis+1+n,0)<<'\n';
	icc(i,n) if (vis[i]) printf("%d ",sel[i]);
	puts("");
	cout<<sed.size()<<'\n';
	for (auto &x:sed)
		printf("%d %d\n",x.first,x.second);
	return 0;
}
