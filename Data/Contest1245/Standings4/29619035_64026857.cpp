#include<bits/stdc++.h>
using namespace std;
struct edge{int u,v;long long s;}e[4100005];
int tot,cnt,ans1,ans2;
int n,fa[2005];
long long X[2005],Y[2005],c[2005],k[2005],ans;
int inq[2005];
int vis[41000005];
void add(int u,int v,long long s){e[++tot].u=u;e[tot].v=v;e[tot].s=s;} 
int find(int x){return x==fa[x]?fa[x]:fa[x]=find(fa[x]);}
bool cmp(edge a,edge b){return a.s<b.s;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=n;++i)
		cin>>X[i]>>Y[i];
	for(int i=1;i<=n;++i)
		cin>>c[i];
	for(int i=1;i<=n;++i)
		cin>>k[i];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			add(i,j,(k[i]+k[j])*(abs(X[i]-X[j])+abs(Y[i]-Y[j])));
	for(int i=1;i<=n;++i)
		add(0,i,c[i]);
	sort(e+1,e+1+tot,cmp);
	for(int i=1;i<=tot;++i){
		int u=e[i].u,v=e[i].v;
		int p=find(u),q=find(v);
		if(p!=q){
			cnt++;
			fa[p]=q;
			ans+=e[i].s;
			vis[i]=1;
			ans2++;
		}
		if(cnt==n)break;
	}
	for(int i=1;i<=tot;++i){
		if(vis[i]){
			if(e[i].u==0){
				inq[e[i].v]=1;
				vis[i]=0;
				ans1++;
				ans2--;
			}
		}
	}
	cout<<ans<<endl;
	printf("%d\n",ans1);
	for(int i=1;i<=n;++i)
		if(inq[i])printf("%d ",i);
	puts("");
	printf("%d\n",ans2);
	for(int i=1;i<=tot;++i)
		if(vis[i])printf("%d %d\n",e[i].u,e[i].v);
	return 0;
}
