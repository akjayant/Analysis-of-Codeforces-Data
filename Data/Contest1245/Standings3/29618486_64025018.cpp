#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e3+10;
ll x[N], y[N], c[N], k[N];
int fa[N], S, cnt;
struct node
{
	int u,v;
	ll w;
}a[N * N];
vector<int>ans1;
vector<node>ans2;
int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0;i<=n;++i) fa[i]=i;
	for(int i = 1; i <= n; ++i)
	scanf("%lld%lld", &x[i], &y[i]);
	for(int i = 1; i <= n; ++i) scanf("%lld", &c[i]);
	for(int i = 1; i <= n; ++i) scanf("%lld", &k[i]);
		S = 0;
	for(int i = 1; i <= n; ++i) 
		a[++cnt] = {S, i, c[i]};
	for(int i = 1; i <= n; ++i){
		for(int j = i + 1; j <= n; ++j){
			ll tmp = ((ll)abs(x[i] - x[j]) + (ll)abs(y[i] - y[j])) * (k[i] + k[j]);
			a[++cnt] = {i, j, tmp};
		}
	}
	sort(a+1,a+1+cnt,cmp);
	ll ans=0;
	for(int i=1;i<=cnt;++i)
	{
		int f1=find(a[i].u);
		int f2=find(a[i].v);
		if(f1!=f2)
		{
			fa[f1]=f2;
			ans+=a[i].w;
			if(a[i].u==0||a[i].v==0)
			{
				ans1.push_back(max(a[i].u,a[i].v));
			}
			else 
			{
				ans2.push_back({a[i].u,a[i].v});
			}
		}

	}
	printf("%lld\n",ans);
	printf("%d\n",ans1.size());
	for(int v:ans1) printf("%d ",v);
	puts("");
	printf("%d\n",ans2.size());
	for(node now:ans2)
	{
		printf("%d %d\n",now.u,now.v);
	}
}