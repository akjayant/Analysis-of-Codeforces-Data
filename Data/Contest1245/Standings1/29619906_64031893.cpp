#include <bits/stdc++.h>
#define D if(false)
#define xx first
#define yy second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

struct DS {
  vector<int> s;

  DS(int n): s(n,-1) {}

  int find(int i) {
    return s[i] < 0 ? i : (s[i] = find(s[i]));
  }

  bool onion(int a, int b) {
    if((a = find(a)) == (b = find(b))) return 0;
    if(s[a] == s[b]) s[a]--;
    if(s[a] <= s[b]) s[b] = a; else s[a] = b;
    return 1;
  }
};

struct edge {
  ll w, a, b;

  bool operator< (const edge& o) const {
    if(w != o.w) return w < o.w;
    if(a != o.a) return a < o.a;
    return b < o.b;
  }
};

int main() {
  ll n; cin >> n;

  vector<vector<pll> > adj(n + 1);

  vector<edge> e;
  vector<pll> p(n);
  vector<ll> c(n), k(n);

  for(ll i = 0; i < n; i++) {cin >> p[i].xx >> p[i].yy;}
  for(ll i = 0; i < n; i++) {cin >> c[i];}
  for(ll i = 0; i < n; i++) {cin >> k[i];}

  for(ll i = 0; i < n; i++) {
    e.push_back(edge{c[i],n,i});

    for(ll j = i+1; j < n; j++) {
      ll d = abs(p[i].xx - p[j].xx) + abs(p[i].yy - p[j].yy);
      d *= (k[i] + k[j]);

      e.push_back(edge{d,i,j});
    }
  }

  sort(e.begin(), e.end());

  vector<ll> power;
  vector<edge> used;

  DS ds(n + 1);
  ll cost = 0;
  for(edge& ee: e) {
    if(ds.find(ee.a) == ds.find(ee.b)) continue;
    ds.onion(ee.a, ee.b);

    D cout << ee.a << " " << ee.b << ": " << ee.w << endl;
    cost += ee.w;

    if(ee.a == n) {
      power.push_back(ee.b);
    } else {
      used.push_back(ee);
    }
  }

  cout << cost << endl;
  cout << power.size() << endl;
  for(ll i = 0; i < power.size(); i++) {
    if(i) cout << " ";
    cout << power[i]+1;
  } cout << endl;
  cout << used.size() << endl;
  for(ll i = 0; i < used.size(); i++) {
    cout << used[i].a+1 << " " << used[i].b+1 << endl;
  }

  return 0;
}
