#include <bits/stdc++.h>
     
using namespace std;
typedef long long ll;
typedef vector<ll> vl ;
     
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(v) (v).begin(),(v).end()
#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)
  
const int MOD = 998244353;
const int N = 1000005;
const double PI =4*atan(1);
const double eps = 1e-7;
const long long oo = 1e18;
 
ll n,p,w,d;
ll c[N][3];
vl adj[N];
ll col[N];
ll final[N];

vl v;
void dfs(ll src, ll par){
  v.pb(src);
  for(auto t:adj[src]){
    if(t==par)continue;
    dfs(t,src);
  }
}

int main(){
    ios::sync_with_stdio(0);
    //freopen("easy.txt","r",stdin);
    cin >> n;
    for(int j=0;j<3;j++)
    for(int i=0 ;i<n;i++){
      cin >> c[i][j];
    }
    for(int i=0;i<n-1;i++){
      ll x,y;
      cin >> x >> y;
      x--;y--;
      adj[x].pb(y);
      adj[y].pb(x);
    }
    for(int i=0;i<n;i++){
      if(adj[i].size()>2){
        cout << -1;
        return 0;
      }
    }
    for(int i=0;i<n;i++){
      if(adj[i].size()==1){
        dfs(i,-1);
        break;
      }
    }
    ll ans=1e18;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        ll res=0;
        if(i==j)continue;
        col[0]=i;
        col[1]=j;
        res=c[v[0]][i]+c[v[1]][j];
        for(int k=2;k<n;k++){
          ll x;
          for(int o=0;o<3;o++){
            if(o!=col[k-1] && o!=col[k-2]){
              x=o;
              break;
            }
          }
          //cout << x << " " << k <<" " << v[k] <<  "  " << c[v[k]][x] << endl;
          res+=c[v[k]][x];
          col[k]=x;
        }
        /*cout << res << endl;
        for(int i=0;i<n;i++){
          cout << col[i] << " ";
        }*/
        //cout << endl;
        if(res<ans){
          for(int k=0;k<n;k++){
            final[v[k]]=col[k]+1;
          }
        }
        ans=min(ans,res);
      }
    }
    cout << ans << endl;
    for(int i=0;i<n;i++){
      cout << final[i] << " ";
    }
    
    return 0;
}