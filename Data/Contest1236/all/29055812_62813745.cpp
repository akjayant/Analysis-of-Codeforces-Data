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
#define trace1(x)                cerr << #x << ": " << x << "\n";
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << "\n";
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z<<" " ;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d<<" " ;

const ll mod = 1000000007;
const ll mod1= 1000000009;
const ll base= 10529;
const ll base1=11699 ;
const ll N=(1<<16);
#define MAXN 2000004
const ll mx=10000000000000000;
set<ll> row[100002],col[100002],row1[100002],col1[100002];
ll cnt=1;
ll n,m,a,b;
void dfs(ll i,ll j,ll dir){
   if(a>n or b>m) return;
   // trace3(i,j,dir);
   // cout<<" | "; 
   // trace4(a,b,n,m);
   // cerr<<'\n';
   if(dir==1){
      auto it=row[i].upper_bound(j);
      ll nw;
      if(it==row[i].end() or *it>m)
        nw=m;
      else nw=*it-1;
      cnt+=nw-j;
      a++;
      m=nw;
      dfs(i,nw,2);
   }
   else if(dir==2){
      auto it=col[j].upper_bound(i);
      ll nw;
      if(it==col[j].end() or *it>n)
        nw=n;
      else nw=*it-1;
      cnt+=nw-i;
      n=nw;
      m--;
      dfs(nw,j,3);
   }
   else if(dir==3){
      auto it=row1[i].upper_bound(-j);
      ll nw;
      if(it==row1[i].end() or *it > -b)
        nw=b;
      else nw=-(*it)+1;

      b=nw;
      n--;
      cnt+=j-nw;
      dfs(i,nw,4);
   } 
   else {
      auto it=col1[j].upper_bound(-i);
      ll nw;
      if(it==col1[j].end() or *it > -a)
        nw=a;
      else nw=-(*it)+1;
      a=nw;
      b++;
      cnt+=i-nw;
      dfs(nw,j,1);
   }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll k;
  ll n1,m1;
  cin>>n>>m>>k;
  n1=n,m1=m;
  for(ll i=1;i<=k;i++){
    ll x,y;
    cin>>x>>y;
    row[x].insert(y);
    col[y].insert(x);
    row1[x].insert(-y);
    col1[y].insert(-x);
  }
  a=1,b=1;
  dfs(1,1,1);
  if(cnt==n1*m1-k) cout<<"YES";
  else cout<<"NO";
  return 0;
} 
