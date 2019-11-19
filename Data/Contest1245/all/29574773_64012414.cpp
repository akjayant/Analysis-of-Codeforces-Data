/*input
3
2 1
1 2
3 3
23 2 23
3 2 3
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long 
#define double long double
#define f first
#define s second
#define mp make_pair
#define pb push_back

#define RE(i,n) for (int i = 1; i <= n; i++)
#define RED(i,n) for (int i = n; i > 0; i--)
#define REPS(i,n) for(int i = 1; (i*i) <= n; i++)
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)

#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

const int INF = 1e18+1;
const int MOD = 1e9+7;
const double PI = 3.14159265358979323846264338;

int raise(int a,int n,int m = MOD){
  if(n == 0)return 1;
  if(n == 1)return a;
  int x = 1;
    x *= raise(a,n/2,m);
    x %= m;
    x *= x;
    x %= m;
    if(n%2)x*= a;
    x %= m;
    return x;
}

int floor1(int n,int k){
    if(n%k == 0 || n >= 0)return n/k;
    return (n/k)-1;
}

int ceil1(int n,int k){
    return floor1(n+k-1,k);
}

const int N = 2001;
vector< pair< int, pair<int,int> > > edges;
vector<int> nice;
vector<pair<int,int> > ok;
int c[N];
int x[N],y[N];
int k[N]; 
int n;
int sz[N];
int par[N];
int ans = 0;

int find(int x){
	if(par[x] == x)return x;
	par[x] = find(par[x]);
	return par[x];
}

void merge(int x,int y){
	x = find(x);
	y = find(y);
	if(sz[x] > sz[y])swap(x,y);
	sz[x] += sz[y];
	par[y] = x;
}

void solve(){
  	cin >> n;
  	REP(i,n+1){
  		par[i] = i;
  		sz[i] = 1;
  	}
  	RE(i,n){
  		cin >> x[i] >> y[i];
  	} 
  	RE(i,n){
  		cin >> c[i];
  		edges.pb({c[i],{0,i}});
  	}
  	RE(i,n)cin >> k[i];
  	RE(i,n){
  		RE(j,i-1){
  			int dist = abs(x[i]-x[j])+abs(y[i]-y[j]);
  			edges.pb({dist*(k[i]+k[j]),{j,i}});
  		}
  	}
  	sort(all(edges));
  	REP(i,edges.size()){
  		int u = edges[i].s.f;
  		int v = edges[i].s.s;
  		if(find(u) == find(v))continue;
  		ans += edges[i].f;
  		merge(u,v);
  		if(u == 0){
  			nice.pb(v);
  		}
  		else{
  			ok.pb({u,v});
  		}
  	}
  	cout << ans << endl;
  	cout << nice.size() << endl;
  	print(nice);
  	cout << ok.size() << endl;
  	REP(i,ok.size()){
  		cout << ok[i].f << " " << ok[i].s << endl;
  	}
}

signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  //freopen(".in","r",stdin);freopen(".out","w",stdout);
  int t = 1;
  //cin >> t;
  while(t--){
    solve();
  }
  return 0;
}