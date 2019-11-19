#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(v) ((ll)v.size())
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define F first
#define S second
#define pii pair<ll,ll> 
const ll mod = 1000000007;
const ll mod1= 1000000009;
const ll base= 10529;
const ll base1=11699 ;
#define MAXN 2000004
#define trace1(x)                cerr << #x << ": " << x << "\n";
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << "\n";
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << "\n";
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << "\n";
ll c[100002][3];
vector<ll> v[100002];
ll root=0,n;
ll col[1000002];
void dfs(ll i,ll par){
  if(v[i].size()>2){
      cout<<-1;
      exit(0);
  }
  if(v[i].size()==1) root=i;
  for(auto it: v[i]) if(it!=par)dfs(it,i);
}
ll dfs1(ll i,ll par,ll ind,vector<ll>&per){
   ll ret=c[i][per[ind]];
   col[i]=per[ind]+1;
   for(auto it: v[i]) if(it!=par) ret+=dfs1(it,i,(ind+1)%3,per);
   return ret;
}

pair<ll,vector<ll>> ans; 


signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  ll i,j;
  for(i=1;i<=n;i++) cin>>c[i][0];
  for(i=1;i<=n;i++) cin>>c[i][1];
  for(i=1;i<=n;i++) cin>>c[i][2];
  for(i=0;i<n-1;i++){
    ll x,y;
    cin>>x>>y;
    v[x].pb(y);
    v[y].pb(x);
  }
  dfs(1,0);
  vector<ll> per={0,1,2};
  ans={100000000000000000ll,per};
  if(root==0) root=1;
  do{
   ans=min(ans,mp(dfs1(root,0,0,per),per));
  }
  while(next_permutation(all(per)));

  cout<<ans.F<<'\n';
  dfs1(root,0,0,ans.S);
  for(i=1;i<=n;i++) cout<<col[i]<<" ";
  return 0;
} 