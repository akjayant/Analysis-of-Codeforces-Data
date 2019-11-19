#include<bits/stdc++.h>
#define MAX_N 100005
#define MAX_M 55
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(V) (V).begin(),(V).end()
#define reset(V) (V).clear();(V).resize(0);
#define sq(x) ((x)*(x))
#define abs(x) ((x)>0?(x):(-(x)))
#define fi first
#define se second
#define LL_inf (1LL<<40)
#define full_inf 0x7fffffff
#define half_inf 0x3fffffff
#define inf (1LL<<60)
#define MOD 1000000007
#define cpx_mod(x) (((LD)(((LL)x.real())%MOD)),((LD)(((LL)x.imag())%MOD)))
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pil;
typedef pair<LL,string> pls;
typedef complex<LD> Complex;
typedef long double LD;
LL n,ans[MAX_N],go[MAX_N];
LL cost[MAX_N][6];
vector<int> adj[MAX_N];
LL get_ans(LL x,LL p,LL q){
	ans[x] = 6-p-q;
	if(adj[x].size()==1)	return cost[x][6-p-q];
	return cost[x][6-p-q] + get_ans(go[x],q,6-p-q);
}
int main(){
	LL i,j,x,y;
	scanf("%lld",&n);
	for(j=1;j<=3;j++){
		for(i=1;i<=n;i++){
			scanf("%lld",&cost[i][j]);
		}
	}
	for(i=1;i<n;i++){
		scanf("%lld %lld",&x,&y);
		adj[x].eb(y);adj[y].eb(x);
	}
	for(i=1;i<=n;i++){
		if(adj[i].size() == 1)	x=i;
		if(adj[i].size()>2)	return !printf("-1\n");
	}
	y=x;
	while(1){
		cost[y][0]=1;
		i=y;
		for(LL p:adj[y]){
			if(cost[p][0])	continue;
			i=p;
		}
		if(y == i)	break;
		go[y]=i;
		y=i;
	}
	LL a = inf;
	for(i=1;i<=3;i++){
		for(j=1;j<=3;j++){
			if(i==j)	continue;
			y = cost[x][i] + cost[go[x]][j] + get_ans(go[go[x]],i,j);
			if(a > y){
				a=y;
				ans[x] = i;
				ans[go[x]] = j;
			}
		}
	}
	printf("%lld\n",cost[x][ans[x]] + cost[go[x]][ans[go[x]]] + get_ans(go[go[x]],ans[x],ans[go[x]]));
	for(i=1;i<=n;i++)	printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}