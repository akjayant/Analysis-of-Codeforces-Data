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
    string s, t;
    cin >> s >> t;
    map<pair<char,char>,int> er;
    F(n) {
      if (s[i] != t[i]) er[{s[i], t[i]}] ++;
      if (er.size() > 1) break;
    }
    if (er.size() == 0 || (er.size() == 1 && er.begin()->second == 2)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}
