#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+5;
typedef long long ll;
int fa[maxn];
int getfa(int t){
	if(fa[t]==t) return fa[t];
	return fa[t]=getfa(fa[t]);
}
void merge(int x,int y){
	fa[getfa(x)]=getfa(y);
}
struct cc{
	int u,v;
	ll w;
	bool operator<(const cc &h)const{
		return w<h.w; 
	}
}e[maxn*maxn+maxn];
int cnt;
int x[maxn],y[maxn];
int c[maxn],k[maxn];
vector<int> ans1;
vector<pair<int,int> > ans2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<=n;++i) fa[i]=i;
	for(int i=1;i<=n;++i){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=n;++i)
		cin>>c[i],e[++cnt]=(cc){0,i,c[i]};
	for(int i=1;i<=n;++i)
		cin>>k[i];
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			e[++cnt]=(cc){i,j,1ll*(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]))};
		}
	}
	sort(e+1,e+cnt+1);
	ll ans=0;
	for(int i=1;i<=cnt;++i){
		int u=e[i].u,v=e[i].v;
		if(getfa(u)!=getfa(v)){
			merge(u,v);
			if(u==0) ans1.emplace_back(v);
			else ans2.emplace_back(u,v);
			ans+=e[i].w;
		}
	}
	cout<<ans<<'\n';
	cout<<ans1.size()<<'\n';
	for(auto i:ans1) cout<<i<<' ';
	cout<<'\n';
	cout<<ans2.size()<<'\n';
	for(int i=0;i<ans2.size();++i) cout<<ans2[i].first<<' '<<ans2[i].second<<'\n';
	return 0;
}
