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

ll c[3][111111],d[111111];
vector<ll> v[111111];

void dfs(ll x,ll p) {
  rep(i,v[x].size()) {
    ll y=v[x][i];
    if(y==p) continue;
    d[y]=(d[x]+1)%3;
    dfs(y,x);
  }
}

void Main() {
  ll n;
  cin >> n;
  rep(i,3)rep(j,n) R c[i][j];
  rep(i,n-1) {
    ll x,y;
    cin >> x >> y;
    x--,y--;
    v[x].pb(y);
    v[y].pb(x);
  }
  rep(i,n) {
    if(v[i].size()>=3) {
      pr(-1);
      return;
    }
  }
  rep(i,n) {
    if(v[i].size()==1) {
      dfs(i,-1);
      break;
    }
  }
  ll a[3],b[3],M=MAXL;
  rep(i,3) a[i]=i;
  do {
    ll sum=0;
    rep(i,n) sum+=c[a[d[i]]][i];
    if(sum<M) {
      M=sum;
      rep(i,3) b[i]=a[i];
    }
  } while(next_permutation(a,a+3));
  pr(M);
  rep(i,n) {
    if(i) cout << " ";
    cout << b[d[i]]+1;
  }
  ln;
}

int main(){ios::sync_with_stdio(0);cin.tie(0);Main();return 0;}
