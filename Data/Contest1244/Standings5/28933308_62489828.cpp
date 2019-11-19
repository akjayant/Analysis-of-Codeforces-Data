#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef pair<int,int > pp;

 
#define sz(x) (int)x.size() 
#define PI acos(-1)
int const N=5e5+10;
int  oo = 1e9;
int mod = oo+7;
ll OO = 3e18;

int n,cost[3][N];
vector<int> adj[N];

void solve(){
	cin>>n;for(int j=0;j<3;j++)for(int i=1;i<=n;i++)cin>>cost[j][i];
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		swap(a,b);
		adj[a].push_back(b);
	}
	int lf = -1;
	for(int i=1;i<=n;i++)if(sz(adj[i])>2){
		cout<<-1;
		return ;
	}else if(sz(adj[i])==1)lf=i;
	vector<int > g;
	int pre=-1;
	for(int i=1;i<=n;i++){
		g.push_back(lf);
		if(i==n)break;
		int nxt=adj[lf][0];
		if(nxt==pre)nxt=adj[lf][1];
		pre=lf;
		lf=nxt;
	}
	int pr[3]={0,1,2},sv[3];
	ll an=OO;
	do{
		ll tmp=0;
		for(int i=0;i<n;i++){
			tmp+=cost[pr[i%3]][g[i]];
		}
		if(tmp<an){
			an=tmp;
			for(int i=0;i<3;i++)sv[i]=pr[i];
		}
		an=min(an,tmp);
	}while(next_permutation(pr,pr+3));
	cout<<an<<'\n';
	vector<int > col(n+1);
	for(int i=0;i<n;i++)col[g[i]]=sv[i%3];
	for(int i=0;i<n;i++)cout<<col[i+1]+1<<' ';
}
int main() {
	#ifndef ONLINE_JUDGE
		freopen("a.in","r",stdin);
		freopen("a.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	// cin>>t;
	t=1;
	while(t--)solve();
	
	return 0;
}

