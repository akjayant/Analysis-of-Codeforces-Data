#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef long long ll;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//*find_by_order
//order_of_key

const int maxn = 1e6 + 5;


set<ll> PF(ll x) {
  set<ll> res;
  for (ll d=2; d*d<=x; d++) {
    while (x%d==0) {
      res.insert(d);
      x=x/d;
    }
  }
  if (x>1) {
    res.insert(x);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
  cout << fixed << setprecision(12);

  ll n; cin>>n;
  if (n<=2) out(n);
  

  set<ll> s = PF(n);
  assert(!s.empty());
  ll g = *s.begin();
  for (ll x: s) g = __gcd(g, x);
  if (g == 1) out(1);

  ll x = *s.begin();
  out(x);

  return 0;
}
