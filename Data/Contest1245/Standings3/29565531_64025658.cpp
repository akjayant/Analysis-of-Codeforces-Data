#pragma GCC optimze(2)
#pragma GCC optimze(3)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=2e3+5;
struct node{
	ll u,v,w;
	bool operator<(const node &n1)const{
		return w>n1.w;
	}
};
priority_queue<node> q;
ll au[maxn],av[maxn];
ll x[maxn],y[maxn],ufs[maxn],n,k[maxn],c[maxn],ans,vis[maxn],cost[maxn][maxn];
ll find(ll u){
	if (ufs[u]==u) return u;
	return ufs[u]=find(ufs[u]);
}
void join(int u,int v){
	ufs[find(u)]=find(v);
}
int main(){
	memset(cost,0x3f,sizeof(cost));
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%lld%lld",&x[i],&y[i]);
		ufs[i]=i;
	}
	for (int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	for (int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
	}
	for (int i=1;i<=n;i++){
		cost[i][n+1]=cost[n+1][i]=c[i];
		for (int j=i+1;j<=n;j++){
			cost[i][j]=cost[j][i]=(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]);
		}
	}
	//cout<<"YES"<<endl;
	ll cou1=0,cou2=0,cnt=0;
	node t;
	t.u=-1;
	t.v=1;
	t.w=0;
	q.push(t);
	while(!q.empty()){
		t=q.top();
		q.pop();
		ll u=t.v;
		//cout<<"P U "<<u<<endl;
		if (vis[u]) continue;
 		vis[u]=1;
		if (t.u!=-1){
			cnt++;
			if (t.u==n+1||t.v==n+1) cou1++;
			else cou2++;
			au[cnt]=t.u;
			av[cnt]=t.v;
			ans+=t.w;
		}
		
		for (int i=1;i<=n+1;i++){
			if (vis[i]) continue;
			node t1;
			t1.u=u;
			t1.v=i;
			t1.w=cost[u][i];
			q.push(t1);
		}
	}
	//cout<<"yes"<<endl;
	cout<<ans<<endl;
	cout<<cou1<<endl;
	for (int i=1;i<=cnt;i++){
		if (au[i]==n+1||av[i]==n+1) cout<<min(au[i],av[i])<<' ';
	}
	cout<<endl;
	cout<<cou2<<endl;
	for (int i=1;i<=cnt;i++){
		if (vis[i]==0) continue;
		if (au[i]!=n+1&&av[i]!=n+1) cout<<au[i]<<' '<<av[i]<<endl;
	}
}