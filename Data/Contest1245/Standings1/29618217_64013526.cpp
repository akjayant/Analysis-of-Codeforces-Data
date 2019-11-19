#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vii = vector<ii>;
const ll MOD = 998244353;
const int INF = 1e9+9;
const int MAXN = 1000006;


ll n, x[MAXN], y[MAXN], c[MAXN], k[MAXN], ans;
vi v;
vii e;
ll p[MAXN];

int parent(int u) {
  return (p[p[u]] == p[u]? p[u] : p[u] = parent(p[u]));
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    p[i] = i;
  }
  p[n] = n;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> k[i];
  }
  using lii = pair<ll, ii>;
  priority_queue<lii, vector<lii>, greater<lii>> myq;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      ll cost = (abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]);
      myq.emplace(cost, ii(i, j));
    }
    myq.emplace(c[i], ii(i, n));
  }
  int ncc = 0;
  while (ncc < n) {
    lii con = myq.top();
    myq.pop();
    if (parent(con.second.first) == parent(con.second.second)) continue;
    p[p[con.second.first]] = p[con.second.second];
    ans+=con.first;
    if (con.second.second == n) {
      v.push_back(con.second.first);
    } else {
      e.push_back(con.second);
    }
    ncc++;
  }
  cout << ans << endl;
  cout << v.size() << endl;
  for (int i : v) {
    cout << i+1 << " ";
  }
  cout << endl << e.size() << endl;
  for (auto p : e) {
    cout << p.first+1 << " " << p.second+1 << endl;
  }
  
}
