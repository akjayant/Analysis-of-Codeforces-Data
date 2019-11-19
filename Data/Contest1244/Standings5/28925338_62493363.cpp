#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <ctime>
#define ll long long
#define N 110000
using namespace std;
vector<int>a[N];
int n,c[N][10],cc[N],fl[5],fa[N],u,v;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0' or '9'<c) f=(c=='-'?-1:f),c=getchar();
	while('0'<=c and c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
bool check(int u,int f){
	if(a[u].size()>2) return true;
	for(int i=0;i<a[u].size();++i)
		if(a[u][i]!=f) if(check(a[u][i],u)) return true;
	return false;
}
ll dfs(int u,int f,int dep){
	fa[u]=f;
	if(dep>2){
		memset(fl,0,sizeof fl);
		fl[cc[f]]=1;fl[cc[fa[f]]]=1;
		for(int i=1;i<=3;++i) if(!fl[i]) cc[u]=i; 
	}
	ll ans=c[u][cc[u]];
	for(int i=0;i<a[u].size();++i)
		if(a[u][i]!=f) ans+=dfs(a[u][i],u,dep+1);
	return ans;
}
void draw(int u,int f,int dep){
	fa[u]=f;
	if(dep>2){
		memset(fl,0,sizeof fl);
		fl[cc[f]]=1;fl[cc[fa[f]]]=1;
		for(int i=1;i<=3;++i) if(!fl[i]) cc[u]=i; 
	}
	for(int i=0;i<a[u].size();++i)
		if(a[u][i]!=f) draw(a[u][i],u,dep+1);
}
int main(){
	srand(time(0));
//	freopen("a.in","r",stdin); 
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&c[i][1]);
	for(int i=1;i<=n;++i) scanf("%d",&c[i][2]);
	for(int i=1;i<=n;++i) scanf("%d",&c[i][3]);
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	if(check(1,0)){
		printf("-1");return 0;
	}
	if(a[1].size()==1){
		ll ans=1e18,x,y;
		for(int i=1;i<=3;++i)
		for(int j=1;j<=3;++j)
		if(i!=j){
			cc[1]=i;cc[a[1][0]]=j;
			ll yu=dfs(1,0,1);
			if(yu<ans) ans=yu,x=i,y=j;
		}
		cc[1]=x;cc[a[1][0]]=y;
		printf("%I64d\n",ans);
		draw(1,0,1);
		for(int i=1;i<=n;++i) printf("%d ",cc[i]);
	}
	if(a[1].size()==2){
		ll ans=1e18,x,y,z;
		for(int i=1;i<=3;++i)
		for(int j=1;j<=3;++j)
		for(int k=1;k<=3;++k)
		if(i!=j and j!=k and i!=k){
			cc[1]=i;cc[a[1][0]]=j;cc[a[1][1]]=k;
			ll yu=dfs(1,0,1);
			if(yu<ans) ans=yu,x=i,y=j,z=k;
		} 
		cc[1]=x;cc[a[1][0]]=y;cc[a[1][1]]=z;
		printf("%I64d\n",ans);
		draw(1,0,1);
		for(int i=1;i<=n;++i) printf("%d ",cc[i]);
	}
	return 0;
}
