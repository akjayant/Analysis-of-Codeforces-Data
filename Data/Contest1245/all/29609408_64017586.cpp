#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3000;
int x[N],y[N],c[N],k[N],fa[N];
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
struct node{int l,r;LL v;};
vector<node>g;
bool cmp(node a,node b){
	return a.v<b.v;
}
typedef pair<int,int>pii;
vector<int>ans1;
vector<pii>ans2;
int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<=n;i++) scanf("%d",&k[i]);
	int s=0;
	for(int i=1;i<=n;i++) g.push_back({s,i,c[i]});
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++){
		g.push_back({i,j,1ll*(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]))});
	}
	for(int i=0;i<=n;i++) fa[i]=i;
	int num=0;LL ans=0;
	sort(g.begin(),g.end(),cmp);
	for(auto it:g){
		int l=it.l,r=it.r;LL v=it.v;
		int a=l,b=r;
		l=find(l),r=find(r);
		if(l==r) continue;
		if(a==0) ans1.push_back(b);
		else if(b==0) ans1.push_back(a);
		else{
			ans2.push_back({a,b});
		}
		fa[l]=r;ans+=v;num++;
	}
	printf("%lld\n",ans);
	printf("%d\n",ans1.size());
	if(ans1.size()){
		for(int i=0;i<ans1.size();i++){
			if(i==0) printf("%d",ans1[i]);
			else printf(" %d",ans1[i]);
		}
		printf("\n"); 
	} 
	printf("%d\n",ans2.size());
	if(ans2.size()){
		for(int i=0;i<ans2.size();i++){
			printf("%d %d\n",ans2[i].first,ans2[i].second);
			//else printf(" %d",ans[i]);
		}
	} 
	return 0;
}