#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define eps 1e-5

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld pi = acos(-1);
const int MOD = 1e9 + 7;

ll x[2100];
ll y[2100];
ll c[2100];
ll k[2100];
vii eg;
vi b;
bool vis[2100];
ll dis[2100];
int n;
ll solve(){
   set<pair<pair<int, ll>, int> > pq;
   for(int i = 0; i < n; i++)
      pq.insert({{dis[i], i}, -1});
   ll ret = 0;
   while(!pq.empty()){
      int u = pq.begin()->fi.se;
      ll cc = pq.begin()->fi.fi;
      int last = pq.begin()->se;
      pq.erase(pq.begin());
      if(vis[u])continue;
      vis[u] = true;
      ret += cc;
      if(last != -1)
         eg.pb({last, u});
      else
         b.pb(u);
      for(int i=0; i<n; i++){
         if(vis[i])continue;
         ll dd = (abs(x[i]-x[u]) + abs(y[i]-y[u]))*(k[u]+k[i]);
         if(dd < dis[i]){
            dis[i] = dd;
            pq.insert({{dis[i],i}, u});
         }
      }
   }
   return ret;
}
int main(){ _
   cin >> n;
   for(int i = 0; i < n; i++)
      cin >> x[i] >> y[i];
   set<ii> sett;
   for(int i = 0; i < n; i++)
      cin >> c[i], dis[i] = c[i];
   for(int i = 0; i < n; i++)
      cin >> k[i];
   cout << solve() << endl;
   cout << b.size() << endl;
   for(int x : b)
      cout << x+1 << " ";
   cout << endl;
   cout << eg.size() << endl;
   for(ii x :eg)
      cout<<x.fi+1<<" "<<x.se+1<<endl;
   exit(0);
}
