#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;

const ll mod = 1000000007;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  vector<int> n(t);
  vector<vector<int> > p(t);
  vector<int> m(t);
  vector<vector<int> > q(t);
  for (int i = 0; i < t; i++) {
    cin >> n[i];
    p[i] = vector<int>(n[i]);
    for (auto &x: p[i]) cin >> x;
    cin >> m[i];
    q[i] = vector<int>(m[i]);
    for (auto &x: q[i]) cin >> x;
  }

  vector<ll> ans(t);
  for (int k = 0; k < t; k++) {
    ll pe = 0, po = 0;
    for (int i = 0; i < n[k]; i++) {
      if (p[k][i] % 2 == 0) pe++;
      else po++;
    }
    ll qe = 0, qo = 0;
    for (int i = 0; i < m[k]; i++) {
      if (q[k][i] % 2 == 0) qe++;
      else qo++;
    }
    ans[k] = pe * qe + po * qo;
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}
