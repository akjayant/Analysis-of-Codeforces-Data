#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define R cin>>
#define Z class
#define ll long long
#define ln cout<<'\n'
#define in(a) insert(a)
#define pb(a) push_back(a)
#define pd(a) printf("%.10f\n",a)
#define mem(a) memset(a,0,sizeof(a))
#define all(c) (c).begin(),(c).end()
#define iter(c) __typeof((c).begin())
#define rrep(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define tr(it,c) for(iter(c) it=(c).begin();it!=(c).end();it++)
template<Z A>void pr(A a){cout<<a;ln;}
template<Z A,Z B>void pr(A a,B b){cout<<a<<' ';pr(b);}
template<Z A,Z B,Z C>void pr(A a,B b,C c){cout<<a<<' ';pr(b,c);}
template<Z A,Z B,Z C,Z D>void pr(A a,B b,C c,D d){cout<<a<<' ';pr(b,c,d);}
template<Z A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}ln;}
ll check(ll n,ll m,ll x,ll y){return x>=0&&x<n&&y>=0&&y<m;}
const ll MAX=1e9+7,MAXL=1LL<<61,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
typedef pair<ll,ll> P;

void Main() {
  ll n,p,d,w;
  cin >> n >> p >> w >> d;
  if(p==0) {
    pr(0,0,n);
    return;
  }
  if(w*n==p) {
    pr(n,0,0);
    return;
  }
  if(d*n==p) {
    pr(0,n,0);
    return;
  }
  ll x=1;
  for(x=1;x<110000;x++) {
    ll y=p-d*x;
    if(y<0) {
      pr(-1);
      return;
    }
    if(y%w==0) break;
  }
  ll l=-1,r=p/(x*d)+3;
  while(l+1<r) {
    ll m=(l+r)/2;
    ll y=p-d*x*m;
    if(y<=0||x*m+y/w>=n) r=m;
    else l=m;
  }
  ll xx=x;
  REP(k,-1000000,1000000) {
    x=(r+k)*xx;
    ll y=(p-x*d)/w;
    ll z=n-x-y;
    if(x<0||y<0||z<0);// pr(-1);
    else if(x+y+z!=n);// pr(-1);
    else if(x*d+y*w!=p);// pr(-1);
    else {
      pr(y,x,z);
      return;
    }
  }
  pr(-1);
}

int main(){ios::sync_with_stdio(0);cin.tie(0);Main();return 0;}
