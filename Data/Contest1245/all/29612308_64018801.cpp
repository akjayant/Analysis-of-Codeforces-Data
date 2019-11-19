#include<bits/stdc++.h>
#define pb push_back

using namespace std;

const int N=2010;

struct node{
	int u,fr;
	long long dis;
	bool idz;
	node(int ru=0,int rf=0,long long rd=0,bool ri=0){
		u=ru;fr=rf;dis=rd;idz=ri;
	}
	bool operator<(const node&rhs)const{
		if(dis^rhs.dis){
			return dis>rhs.dis;
		}
		return idz<rhs.idz;
	}
};

int n,x[N],y[N],c[N],k[N],fr[N],to[N],dz[N],cnte,cntd;

long long ans;

bool vis[N];

int mdis(int u,int v){
	return abs(x[u]-x[v])+abs(y[u]-y[v]);
}

vector<int>G[N];vector<long long>edge[N];

priority_queue<node>pq;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		pq.push(node(i,0,c[i],1));
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i^j){
				G[i].pb(j);edge[i].pb(1LL*mdis(i,j)*(k[i]+k[j]));
			}
		}
	}
	int u,ffr;bool id;long long dd;
	while(!pq.empty()){
		u=pq.top().u;
		ffr=pq.top().fr;
		dd=pq.top().dis;
		id=pq.top().idz;
		pq.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		ans+=dd;
		if(id){
			dz[++cntd]=u;			
		}
		else{
			++cnte;
			fr[cnte]=ffr;to[cnte]=u;
		}
		for(int i=0,v;i<(int)G[u].size();i++){
			v=G[u][i];
			if(u==v){
				continue;
			}
			if(!vis[v]){
				pq.push(node(v,u,edge[u][i],0));
			}
		}
	}
	printf("%lld\n",ans);
	printf("%d\n",cntd);
	for(int i=1;i<=cntd;i++){
		printf("%d%c",dz[i]," \n"[i==cntd]);
	}
	printf("%d\n",cnte);
	for(int i=1;i<=cnte;i++){
		printf("%d %d\n",fr[i],to[i]);
	}
	return 0;
}