#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repr(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define repChar(i) for (char i = 'a'; i <= 'z'; i++)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,k; cin >> n >> k;
  vector<ll> xs(n); trav(x,xs) cin >> x;

  map<ll,int> m;
  trav(x,xs) m[x]++;

  while (k > 0 && sz(m) > 1) {
    ll small = m.begin()->first;
    int smallCount = m.begin()->second;
    auto it = m.end(); it--;
    ll big = it->first;
    int bigCount = it->second;
    if (smallCount < bigCount) {
      m.erase(m.begin());
      ll nextSmall = m.begin()->first;
      ll diff = nextSmall - small;
      if (diff * smallCount <= k) {
        m[nextSmall] += smallCount;
        k -= diff * smallCount;
      } else {
        diff = k / smallCount;
        m[small + diff] = smallCount;
        k = 0;
      }
    } else {
      m.erase(it);
      it = m.end(); it--;
      ll nextBig = it->first;
      ll diff = big - nextBig;
      if (diff * bigCount <= k) {
        m[nextBig] += bigCount;
        k -= diff * bigCount;
      } else {
        diff = k / bigCount;
        m[big - diff] = bigCount;
        k = 0;
      }
    }
  }

  if (sz(m) == 1) {
    cout << 0 << endl;
  } else {
    ll small = m.begin()->first;
    auto it = m.end(); it--;
    ll big = it->first;
    cout << big - small << endl;
  }
}
