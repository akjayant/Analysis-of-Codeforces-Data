#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2009;

int n,tot,pre[N];
struct node{
	ll x,y;
}p[2009];
ll c[N],k[N],dis[N][N];

struct node1{
	ll u,v,w;
	bool operator <(const node1 &b)const 
	{
		return w<b.w;
	}
}e[N*N];

int aa[N],bb[N*N][2],tot1,tot2;

int find(int x){return x==pre[x]?pre[x]:pre[x]=find(pre[x]);}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<N;i++)pre[i]=i;
	for(int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].y;
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)cin>>k[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y);
		}
	}
	for(int i=1;i<=n;i++){
		e[++tot].u=0;
		e[tot].v=i;
		e[tot].w=c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			e[++tot].u=i;
			e[tot].v=j;
			e[tot].w=dis[i][j]*(k[i]+k[j]);
		}
	}
	sort(e+1,e+1+tot);
	ll ans=0;
	for(int i=1;i<=tot;i++){
		int fa=find(e[i].u);
		int fb=find(e[i].v);
		if(fa!=fb){
			if(e[i].u==0){
				aa[++tot1]=e[i].v;
			} else if(e[i].v==0){
				aa[++tot1]=e[i].u;
			} else {
				bb[++tot2][0]=e[i].u;
				bb[tot2][1]=e[i].v;
			}
			pre[fa]=fb;
			ans+=e[i].w;
		}
	}
	cout<<ans<<endl;
	cout<<tot1<<endl;
	for(int i=1;i<=tot1;i++){
		cout<<aa[i];
		if(i!=tot1)cout<<" ";
	}
	cout<<endl;
	cout<<tot2<<endl;
	for(int i=1;i<=tot2;i++){
		cout<<bb[i][0]<<" "<<bb[i][1]<<endl;
	}
	return 0;
}