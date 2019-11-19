//Coded by dst
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,pii> plp;
plp e[5000005];
int n,num,numh,he[2005],ansx[2005],ansy[2005],fa[2005],numc;
ll x[2005],y[2005];
ll c[2005],k[2005],ans;
inline ll ab(ll x){
	return x>0?x:-x;
}
int fnd(int x){
	return x==fa[x]?x:fa[x]=fnd(fa[x]);
}
void unionn(int x,int y){
	x=fnd(x);
	y=fnd(y);
	fa[x]=y;
}
int main(){
	int i,j,u,v;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld%lld",&x[i],&y[i]);
		fa[i]=i;
	}
	fa[n+1]=n+1;
	for(i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	for(i=1;i<=n;i++)
		scanf("%lld",&k[i]);
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			e[++num]=make_pair((k[i]+k[j])*(ab(x[i]-x[j])+ab(y[i]-y[j])),make_pair(i,j));
	for(i=1;i<=n;i++)
		e[++num]=make_pair(c[i],make_pair(i,n+1));
	sort(e+1,e+num+1);
	for(i=1;i<=num;i++)
		if(fnd(u=e[i].second.first)!=fnd(v=e[i].second.second)){
			unionn(u,v);
			if(v==n+1)
				he[++numh]=u;
			else
				ansx[++numc]=u,ansy[numc]=v;
			ans+=e[i].first;
		}
	printf("%lld\n%d\n",ans,numh);
	for(i=1;i<=numh;i++)
		printf("%d ",he[i]);
	printf("\n%d\n",numc);
	for(i=1;i<=numc;i++)
		printf("%d %d\n",ansx[i],ansy[i]);
	
	return 0;
}