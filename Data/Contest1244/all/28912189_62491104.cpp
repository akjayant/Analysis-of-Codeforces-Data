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
ll a[200002],pre[200002];

ll n,k;
bool check(ll m){
  ll i;
  for(i=1;i<=n;i++){
    ll p=upper_bound(a+1,a+1+n,a[i]+m)-a;
    ll tot=  (i-1)*a[i]-pre[i-1];
    tot+=   (pre[n]-pre[p-1]-(n-p+1)*(a[i]+m));
    if(tot<=k) return 1;
  
    p=lower_bound(a+1,a+1+n,a[i]-m)-a;
    p--;
    tot=pre[n]-pre[i]-(n-i)*a[i];
    tot+= p*(a[i]-m)-pre[p];
    if(tot<=k) return 1;
  }
  return 0;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>k;
  ll i;
  for(i=1;i<=n;i++) 
    cin>>a[i];
  sort(a+1,a+1+n);
  for(i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];

  ll lo=0,hi=a[n]-a[1];
  if(check(lo)) {
    cout<<lo;
    return 0;
  }
  while(hi-lo>1){
    ll m=(hi+lo)>>1;
    if(check(m)) hi=m;
    else lo=m;
  }
  cout<<hi;
  return 0;
} 