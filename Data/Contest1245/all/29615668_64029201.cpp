#include <bits/stdc++.h>
int n;
int c[1000001];
int k[1000001];
int fa[1000001];
struct fuck{
	int x;
	int y;
}a[100001];
struct edge{
	int l;
	int r;
	long long v;
}e[5000001];
int tot;
int tot1;
int tot2;
int ans1[1000001];
struct aaaa{
	int x;
	int y;
}ans2[1000001];
bool cmp(edge x,edge y){
	return x.v<y.v;
}
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
main(){
	std::cin>>n;
	for(int i=1;i<=n;++i)
		std::cin>>a[i].x>>a[i].y;
	for(int i=1;i<=n;++i)
	  std::cin>>c[i];
	for(int i=1;i<=n;++i)
	  std::cin>>k[i];
	for(int i=1;i<n;++i){
		for(int j=i+1;j<=n;++j){
			e[++tot]={i,j,(1LL*abs(a[i].x-a[j].x)+1LL*abs(a[i].y-a[j].y))*1LL*(k[i]+k[j])};
		}
	}
	for(int i=1;i<=n;++i)
	  e[++tot]={n+1,i,1LL*c[i]};
	std::sort(e+1,e+tot+1,cmp);
	long long s=0;
	for(int i=1;i<=n+1;++i)
	  fa[i]=i;
	for(int i=1;i<=tot;++i){
		int X=get(e[i].l);
		int Y=get(e[i].r);
		if(X==Y)
		  continue;
		if(e[i].l==n+1)
			ans1[++tot1]=e[i].r;
	  else
	    ans2[++tot2]={e[i].l,e[i].r};
		fa[X]=Y;
		s+=e[i].v;
	}
	std::cout<<s<<std::endl<<tot1<<std::endl;
	for(int i=1;i<=tot1;++i)
	  std::cout<<ans1[i]<<" ";
	std::cout<<std::endl<<tot2<<std::endl;
	for(int i=1;i<=tot2;++i)
	  std::cout<<ans2[i].x<<" "<<ans2[i].y<<std::endl;
	return 0;
}