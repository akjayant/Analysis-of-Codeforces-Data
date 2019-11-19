#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define clr(x) memset(x, 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1.0);
const int INF = 1e9;

void init() {
  ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
}

struct zml {
  map<int, int> S;
  int B;
  int n;
  zml(int _n) : n(_n) {
    rep(i, 1, n + 1) S[i] = 1;
    B = 0;
  }
  void op(int q, int c) {
    B += q;
    if (S[c - B]) {
      S[c - B - q] += S[c - B];
      S[c - B] = 0;
    }
    if (S[0 - B]) {
      S[1 - B] += S[0 - B];
      S[0 - B] = 0;
    }
    if (S[n + 1 - B]) {
      S[n - B] += S[n + 1 - B];
      S[n + 1 - B] = 0;
    }
  }
  ll sum() {
    ll ret = 0;
    for (auto &i : S)
      ret += (ll)i.fi * i.se;
    ret += (ll)B * n;
    return ret;
  }
};

int main() {
  init();
  int n, m;
  cin >> n >> m;
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  zml L(n);
  zml R(n);
  rep(i, 0, m) {
    int c;
    cin >> c;
    L.op(-1, c);
    R.op(+1, c);
  }
  L.op(-1, +INF);
  R.op(+1, +INF);
  cout << R.sum() - L.sum() + n << endl;
}
