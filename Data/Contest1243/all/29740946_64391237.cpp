#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define up_b upper_bound
#define low_b lower_bound
#define sz(x) (int)x.size()
#define all(v) v.begin(),v.end()
#define nl '\n'

#define boost ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;

const ll INF=1e18;
const int inf=1e9;
const ld eps=1e-7;
const ld pi=acos(-1);
const int dx[8]={0,0 ,1,-1,1,1,-1,-1};
const int dy[8]={1,-1,0,0,1,-1,1,-1};
const int mod1=998244353;
const int mod=1e9+7;
const int N=1111;
int cnt[26];

bool prime(ll n){
  for(ll i=2;i*i<=n;i++){
    if(n%i==0)return 0;
  }
  return 1;
}

int main(){
  boost;
  ll n;
  cin>>n;
  if(n==1){
    cout<<1;
    return 0;
  }
  else if(prime(n)){
    cout<<n;
    return 0;
  }
  else{
    ll lcm=1;
    ll m=n;
    for(ll i=2;i*i<=n;i++){
      if(n%i==0){
        lcm=lcm/__gcd(lcm,i);
        lcm*=i;
        ll j=n/i;
        lcm=lcm/__gcd(lcm,j);
        lcm*=j;
      }
    }
    cout<<m/lcm;
  }
  return 0;
}
