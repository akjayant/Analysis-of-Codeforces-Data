#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define pu push
#define pp pop_back
#define in insert
#define ld long double
#define forn(low,high,i) for(i = low;i < high;i++)
#define forrev(high,low,i) for(i = high; i >= low;i--)
#define trace(x) cerr << #x << ": " << x << " " << endl;
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define line cout << __LINE__;
#define prv(a) for(auto x : a) cout << x << ' ';cout << '\n';
#define decimal_digits cout << fixed << setprecision(15);
#define dbg2(a,b) cerr << #a << " = " << a << " " << #b << " = " << b << '\n';        
#define debug(x) cerr << __LINE__ << ' ' << #x << " = " << x << '\n';
#define dln cerr << '\n';
#define dsp cerr << ' ';
#define pln cout << '\n';
#define psp cout << ' ';

typedef unordered_map<int,int> umi;
typedef unordered_map<ll,ll> uml;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int inf = 1e9;
const ll INF = 1e18;
const ll mod = 1e9 + 7;

clock_t time_p = clock();

void ktj(){
  time_p = clock() - time_p;
  cerr << "Time elapsed : " << (float)(time_p)/CLOCKS_PER_SEC << "\n";
}

const int N = 1e5 + 5;

ll c[N][4];
vi g[N];

int d[N];
int ans[N];

bool vis[N];

ll cost = 0;

void dfs(int v, int p, int col){
  for(auto x : g[v]){
    if(x != p){
      cost += c[x][col];
      d[x] = col;
      dfs(x, v, 6 - d[v] - col);
    }
  }
}

int main(){
  fastio

  int n;
  cin >> n;
  for(int j = 1; j <= 3; j++){
    for(int i = 1; i <= n; i++){
      cin >> c[i][j];
    }    
  }

  for(int i = 1; i < n; i++){
    int u, v;
    cin >> u >> v;
    g[u].pb(v); g[v].pb(u);
  }

  for(int i = 1; i <= n; i++){
    if(sz(g[i]) >= 3){
      cout << -1 << '\n'; return 0;
    }
  }
  ll res = INF;
  if(sz(g[1]) == 2){
    int a[] = {1, 2, 3};
    do{
      d[1] = a[0];
      d[g[1][0]] = a[1];
      d[g[1][1]] = a[2]; 
      for(int i = 1; i <= n; i++){
        vis[i] = 0;
      }
      cost = c[1][d[1]] + c[g[1][0]][d[g[1][0]]] + c[g[1][1]][d[g[1][1]]];
      vis[1] = vis[g[1][0]] = vis[g[1][1]] = 1;
      dfs(g[1][0], 1, 6 - d[g[1][0]] - d[1]);
      dfs(g[1][1], 1, 6 - d[g[1][1]] - d[1]);
      if(cost < res){
        res = cost;
        for(int i = 1; i <= n; i++){
          ans[i] = d[i];
        }
      }
    }while(next_permutation(a, a + 3));
  }else{
    int a[] = {1, 2, 3};
    do{
      d[1] = a[0];
      d[g[1][0]] = a[1];
      for(int i = 1; i <= n; i++){
        vis[i] = 0;
      }
      cost = c[1][d[1]] + c[g[1][0]][d[g[1][0]]];
      vis[1] = vis[g[1][0]] = 1;
      dfs(g[1][0], 1, 6 - d[g[1][0]] - d[1]);
      if(cost < res){
        res = cost;
        for(int i = 1; i <= n; i++){
          ans[i] = d[i];
        }
      }
    }while(next_permutation(a, a + 3));
  }

  cout << res << '\n';
  for(int i = 1; i <= n; i++){
    cout << ans[i] << ' ';
  }
  cout << '\n';

  ktj();
}
