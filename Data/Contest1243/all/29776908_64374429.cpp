#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=double;
using pll=pair<ll,ll>;
using vll=vector<ll>;
using vpll=vector<pll>;
using vvll=vector<vll>;
#define FOR(i,a,b) for(ll i=a;i<(ll)b;++i)
#define ROF(i,a,b) for(ll i=a;i>=(ll)b;--i)
#define F(n) FOR(i,0,n)
#define FF(n) FOR(j,0,n)
#define aa first
#define bb second
#define PB push_back
#define EQ(a,b) (fabs(a-b)<=(fabs(a+b)*EPS))
#define mp make_pair
#define INF (1ll << 40)

int main(){
  ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
  ll k;
  cin >> k;
  while (k --) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    F(n) cin >> a[i];
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    ll res = 0;
    F(n) {
      if (a[i] >= i+1) {
        res = i+1;
      }
    }
    cout << res << endl;
  }

  return 0;
}
