#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 2e3+10;
struct qwq {
	int from,to;
	ll w;
	bool operator < (const qwq& rhs) const {
		return w<rhs.w;
	}
}E[maxn*maxn];
int n;
int c[maxn],k[maxn],x[maxn],y[maxn],fa[maxn],w[maxn],cnt;
int find(int x) {
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void add(int a,int b,ll w) {
	++cnt;
	E[cnt].from = a;
	E[cnt].to = b;
	E[cnt].w = w;
}
int dist(int a,int b) {
	return abs(x[a]-x[b]) + abs(y[a]-y[b]);
}
vector<int> ans;
ll tot;
vector<int> sts;
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d%d",x+i,y+i);
	for(int i=1;i<=n;++i) scanf("%d",c+i);
	for(int i=1;i<=n;++i) scanf("%d",k+i);
	for(int i=1;i<=n+1;++i) fa[i]=i,w[i]=1;
	for(int i=1;i<=n;++i) {
		add(n+1,i,c[i]);
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j) {
			if(i==j) continue;
			ll wet = 1LL*(k[i]+k[j])*dist(i,j);
			add(i,j,wet);
		}
	sort(E+1,E+1+cnt);
	for(int i=1;i<=cnt;++i) {
		int p = find(E[i].from),q = find(E[i].to);
		if(p==q) continue;
		if(w[p] < w[q]) swap(p,q);
		fa[q] = p;
		if(E[i].from != n+1) 
			ans.push_back(i);
		else {
			sts.push_back(i);
		}
		tot+=E[i].w;
	}
	printf("%lld\n",tot);
	printf("%d\n",sts.size());
	for(int i=0;i<sts.size();++i) {
		printf("%d ",E[sts[i]].to);
	}
	puts("");
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();++i) {
		printf("%d %d\n",E[ans[i]].from,E[ans[i]].to);
	}
	return 0;
}
