#include<bits/stdc++.h>
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define nd second
#define st first
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vl=vector<ll>;
using mii=map<int,int>;
using si=set<int,int>;
using vpi=vector<pii>;
using vpl=vector<pll>;

const int N=(int)1e5+5;

int n,m,a,b,c,q,tab[6][3]={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
vi G[N];
vpi ciag,ciag2;
ll color[N][3];
bool dp[N][3][6];
ll wyn,pom;

int R(int l, int p){
	return rand()%(p-l+1)+l;
}

void wczytaj(){
	cin>>n;
	for (int i=0; i<3; ++i){
		for (int j=1; j<=n; ++j){
			cin>>color[j][i];
		}
	}
	for (int i=1; i<n; ++i){
		cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
}

void DFS(int v, int p, int kt, int nr){
	pom+=color[v][tab[nr][kt]];
//	cout<<"wie "<<v<<" pom "<<pom<<" kt "<<kt<<" nr "<<nr<<" kolor "<<color[v][tab[nr][kt]]<<'\n';
//	dp[v][kt][nr]=1;
	ciag2.pb({v,tab[nr][kt]+1});
	for(int i:G[v]){
		if (i!=p){
			DFS(i,v,(kt+1)%3,nr);
		}
	}
}

void solve(){
	int pocz=0;
	for (int i=1; i<=n; ++i){
		if (G[i].size()>2){
			cout<<-1<<'\n';
			return;
		}
		else if (G[i].size()==1){
			pocz=i;
		}
	}
	wyn=(ll)1e18;
	int xd=0;
	for (int i=0; i<6; ++i){
		pom=0;
		ciag2.clear();
		DFS(pocz,0,0,i);
		if (pom<wyn){
			wyn=pom;
			xd=i;
			ciag=ciag2;
		}
	}
	cout<<wyn<<'\n';
/*	for (int i=1; i<=n; ++i){
		if (dp[i][0][xd]==1)
			cout<<1<<' ';
		if (dp[i][1][xd]==1)
			cout<<2<<' ';
		if (dp[i][2][xd]==1)
			cout<<3<<' ';
	}*/
	sort(ciag.begin(),ciag.end());
	for (auto i:ciag)
		cout<<i.nd<<' ';
	cout<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int ilosc_przypadkow_testowych=1;
//	cin>>ilosc_przypadkow_testowych
	for (int i=1; i<=ilosc_przypadkow_testowych; ++i){
		wczytaj();
		solve();
	}
}
