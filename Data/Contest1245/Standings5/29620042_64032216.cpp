#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N 4000005 

struct Edge{
	ll u,v,w;
	Edge(){}
	Edge(ll u,ll v,ll w):u(u),v(v),w(w){}
}e[N];
ll n,m;
ll k[N],c[N],x[N],y[N];

int cmp(Edge & a,Edge &b){
	return a.w<b.w;
}

int F[N];
ll sum; 
int find(int x){
	return F[x]==x?x:F[x]=find(F[x]);
}
vector<ll>ans1;
vector<pair<ll,ll> >ans2;

void krus(){
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=n+1;i++)F[i]=i;
	int tot=0,id;
	for(int i=1;i<=m;i++){
		if(ans1.size()==0 && tot==n-1){
			id=i;break;
		}
		Edge now=e[i];
		ll u=now.u,v=now.v,w=now.w;
		int fu=find(u),fv=find(v);
		if(fu==fv)continue;
		F[fu]=fv;
		sum+=w;
		tot++;
		
		if(v==n+1){
			ans1.push_back(u);
		}
		else ans2.push_back(make_pair(u,v));
		
		if(tot==n)break;
	}
	if(tot==n-1){
		for(int i=id;i<=m;i++)
			if(e[i].v==n+1){
				sum+=e[i].w;
				ans1.push_back(e[i].u);
				break;
			}
	}
}


int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&x[i],&y[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&k[i]);
	
	int s=n+1;
	for(int i=1;i<=n;i++)	
		e[++m]=Edge(i,s,c[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			ll dis=abs(x[i]-x[j])+abs(y[i]-y[j]);
			e[++m]=Edge(i,j,(k[i]+k[j])*dis);
		}
	
	krus();
	cout<<sum<<'\n';
	cout<<ans1.size()<<'\n';
	for(int i=0;i<ans1.size();i++){
		cout<<ans1[i]<<" ";
	}
	puts("");
	
	
	cout<<ans2.size()<<'\n';
	for(int i=0;i<ans2.size();i++){
		cout<<ans2[i].first<<" "<<ans2[i].second<<'\n';
	}
}