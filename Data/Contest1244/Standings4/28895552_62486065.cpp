//code by lynmisakura.wish to be accepted!
/****************************/
#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<bitset>
#include <climits>
#include<set>
#include<bitset>
using namespace std;
/***************************/
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpi;
 
//const long long INF = 1LL << 55;
 
#define itn int
#define endl '\n'
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ss second
#define ff first
#define dup(x,y) ((x) + (y) - 1)/(y)
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()
#define Rep(n) for(int i = 0;i < n;i++)
#define rep(i,n) for(int i = 0;i < n;i++)
#define rrep(i,n) for(int i = n - 1;i >= 0;i--)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )
#define ioboost cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20)

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll qp(ll a, ll b) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a; a = 1ll * a*a; } while (b >>= 1); return ans; }
ll qp(ll a, ll b, int mo) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a%mo; a = 1ll * a*a%mo; } while (b >>= 1); return ans; }
 
#define _GLIBCXX_DEBUG
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

vector<int> g1,g2,g3,cost[3];
vector<int> G[100010];
vector<int> path;
int visited[100010];
void dfs(int x){
   path.pb(x);
   visited[x] = 1;
   for(auto i : G[x]){
      if(!visited[i])dfs(i);
   }
}
int main(void){
   ioboost;
   int n;cin >> n;
   rep(i,n){
      int x;cin >> x;
      cost[0].pb(x);
   }
   rep(i,n){
      int x;cin >> x;
      cost[1].pb(x);
   }
   rep(i,n){
      int x;cin >> x;
      cost[2].pb(x);
   }
   
   rep(i,n-1){
      int a,b;cin >> a >> b;
      G[--a].pb(--b);
      G[b].pb(a);
   }
   int fir;
   rep(i,n){
      if(G[i].size() > 2){
         cout << -1 << endl;
         return 0;
      }else{
         if(G[i].size() == 1)fir = i;
      }
   }
   dfs(fir);
   rep(i,n){
      switch(i%3){
         case 0:g1.pb(path[i]);break;
         case 1:g2.pb(path[i]);break;
         case 2:g3.pb(path[i]);break;
      }
   }
   int ai,aj,ak;
   ll ans = 1000000000000000;
   for(int i = 0;i < 3;i++){
      for(int j = 0;j < 3;j++){
         for(int k = 0;k < 3;k++){
            if(i == j or j == k or k == i)continue;
            
            ll sum = 0;
            for(auto idx : g1){
               sum += cost[i][idx];
            }
            for(auto idx : g2){
               sum += cost[j][idx];
            }
            for(auto idx : g3){
               sum += cost[k][idx];
            }
            
            if(sum < ans){
               ans = sum;
               ai = i,aj = j,ak = k;
            }
         }
      }
   }
   
   int ans_index[100010];
   for(auto idx : g1){
      ans_index[idx] = ai + 1;
   }
   for(auto idx : g2){
      ans_index[idx] = aj + 1;
   }
   for(auto idx : g3){
      ans_index[idx] = ak + 1;
   }
   
   bool first = true;
   cout << ans << endl;
   rep(i,n){
      if(!i)cout << ans_index[i];
      else cout << " " << ans_index[i];
   }
   cout << '\n';
}