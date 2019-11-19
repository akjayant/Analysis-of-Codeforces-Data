#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
 
#if DEBUG
    #include "debug.h"
#else
    #define debug(args...)
#endif    

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;


#define M 1000000 
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define fill(a,x) memset(a,x,sizeof(a))
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = INT_MAX;
const int mod = 1e9+7;

const int N = 2e3 + 10;
inline int add(int x,int y){
  x += y;
  if(x >= mod) x -= mod;
  return x;
}
inline int mul(int x,int y){
  x = (1LL * x * y) % mod;
  return x;
}
clock_t time_p=clock();

int parent[N];
int size[N];
int minv[N];
int minid[N];



void initialize(int n){
	FOR(i,1,n){
		parent[i] = i;
		size[i] = 1;
		minid[i] = i;
	}
}

int root(int i){
	while(parent[i]!=i){
		parent[i] = parent[parent[i]];
		i = parent[i];
	}
	return i;
}

void weighted_union(int a,int b){
	int root_a = root(a);
	int root_b = root(b);
	if(size[root_a]<size[root_b]){
		parent[root_a] = parent[root_b];
		size[root_b]+=size[root_a];
		// minv[root_b] = min(minv[root_b],minv[root_a]);
		if(minv[root_b] > minv[root_a]) {
			minv[root_b] = minv[root_a];
			minid[root_b] = minid[root_a];
		}
	}
	else{
		parent[root_b] = parent[root_a];
		size[root_a]+=size[root_b];
		// minv[root_a] = min(minv[root_a],minv[root_b]);
		if(minv[root_a] > minv[root_b]) {
			minv[root_a] = minv[root_b];
			minid[root_a] = minid[root_b];
		}		
	}
}

ll cost[N][N];
vector<pair<ll,pair<ll,ll> > >edges;
int connect[N][N];
int parent_[N];
int bb[N];
int C[N];
	int n;


void dfs(int u, int p) {
	parent_[u] = p;
	minv[u] = C[u];
	minid[u] = u;
	FOR(i,1,n) {
		if(connect[u][i] and i != p) {
			dfs(i,u);
			if(minv[i] < minv[u]) {
				minv[u] = minv[i];
				minid[u] = minid[i];
			}
			// minv[u] = min(minv[u],minv[i]);
		}
	}
}

int32_t main(){
	fast;

	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	cin >> n;
	ll ans = 0;
	initialize(n);
	vector<ii>cord(n+1);
	FOR(i,1,n)cin >> cord[i].F >> cord[i].S;
	// vector<int>C(n+1);
	FOR(i,1,n) {
		cin >> C[i];
		ans += C[i];
		minv[i] = C[i];
	}
	vector<int>K(n+1);
	FOR(i,1,n)cin >> K[i];

	FOR(i,1,n) {
		FOR(j,i,n) {
			if(i != j) {
				cost[i][j] = (K[i] + K[j]) * 1LL * (abs(cord[i].F-cord[j].F) + abs(cord[i].S-cord[j].S));
				edges.pb({cost[i][j],{i,j}});
			}
		}
	}

	sort(all(edges));
	int ee = 0;

	for(auto x : edges) {
		int u = x.S.F;
		int v = x.S.S;
		if(root(u) != root(v) and cost[u][v] < max(minv[root(u)],minv[root(v)])) {
			connect[u][v] = 1;
			connect[v][u] = 1;
			ee++;
			ans += cost[u][v];
			ans -= max(minv[root(u)],minv[root(v)]);
			weighted_union(u,v);
		}
	}
	set<int>ss;
	// int cc = 0;
	FOR(i,1,n)ss.insert(root(i));
	int cc = sz(ss);
	cout << ans << "\n";
	cout << cc << "\n";
	for(auto x : ss) {
		cout << minid[x] << " ";
	}
	cout << "\n" << ee << "\n";

	// FOR(i,1,n) {
	// 	FOR(j,i+1,n) {
	// 		debug(i,j,cost[i][j]);
	// 	}
	// }
	// debug(ans);
	// dfs(1,-1);
	// ans += minv[1];
	// bb[minid[1]] = 1;
	// FOR(i,1,n)cout << parent_[i] << " ";
	// cout << "\n";
	// FOR(i,1,n)cout << minv[i] << " ";
	// cout << "\n";
	// FOR(i,1,n)cout << minid[i] << " ";
	// cout << "\n";
	// int cc = 0;
	// int ee = n-1;
	// FOR(i,1,n) {
	// 	FOR(j,i+1,n) {
	// 		if(connect[i][j] == 1) {
	// 			int ch;
	// 			if(parent_[i] == j)ch = i;
	// 			else ch = j;
	// 			if(cost[i][j] > minv[ch]) {
	// 				ans = ans + minv[ch] - cost[i][j];
	// 				connect[i][j] = 0;
	// 				connect[j][i] = 0; 
	// 				bb[minid[ch]] = 1;
	// 				cc++;
	// 				ee--;
	// 			}
 // 			}
	// 	}
	// }

	// cout << ans << "\n";
	// cout << cc << "\n";
	// FOR(i,1,n) {
	// 	if(bb[i] == 1)cout << i << " ";
	// }
	// cout << "\n";
	// cout << ee << "\n";
	FOR(i,1,n) {
		FOR(j,i+1,n) {
			if(connect[i][j] == 1) {
				cout << i << " " << j << "\n";
			}
		}
	}



	time_p=clock()-time_p;
	cerr<<"\nTime Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";

	return 0;
}