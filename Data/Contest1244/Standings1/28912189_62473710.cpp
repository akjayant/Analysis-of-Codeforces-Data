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

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll n,p,w,d;
  cin>>n>>p>>w>>d;
  ll y;
  for(y=0;y<=w;y++){
    if((p-y*d)<0){
      cout<<-1;
      return 0;
    }
    if((p-y*d)%w==0){
      ll x=(p-y*d)/w;
      if(y+x<=n){
        cout<<x<<" "<<y<<" "<<n-x-y;
        return 0;
      }
    }
  }
  cout<<-1;
  return 0;
} 