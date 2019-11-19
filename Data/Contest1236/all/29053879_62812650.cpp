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
const int inf = 1e9;
const int maxn = 2e5;

void init() {
  ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
}

set<int> A[maxn];
set<int> B[maxn];
int x_min;
int x_max;
int y_min;
int y_max;

int ne(set<int> &S, int p) {
  if (S.empty())
    return +inf;
  auto it = S.lower_bound(p);
  if (it == S.end())
    return +inf;
  return *it - 1;
}

int pe(set<int> &S, int p) {
  if (S.empty())
    return -inf;
  auto it = S.lower_bound(p);
  if (it == S.begin())
    return -inf;
  return (*(--it)) + 1;
}

int main() {
  init();
  int n, m, k;
  cin >> n >> m >> k;
  rep(i, 0, k) {
    int x, y;
    cin >> x >> y;
    A[x].insert(y);
    B[y].insert(x);
  }
  ll cnt = 1;
  x_min = 1;
  x_max = n;
  y_min = 1;
  y_max = m;
  int dir = 0;
  int st = 1;
  int x = 1;
  int y = 1;
  int x2, y2;
  while (1) {
    // cout << "dir = " << dir << endl;
    // cout << x << "," << y << endl;
    if (dir == 0) {
      y2 = min(y_max, ne(A[x], y));
      x_min = x + 1;
      if (y2 <= y && !st)
        break;
      else
        cnt += abs(y2 - y);
      y = y2;
    }
    if (dir == 1) {
      x2 = min(x_max, ne(B[y], x));
      y_max = y - 1;
      if (x2 <= x)
        break;
      else
        cnt += abs(x2 - x);
      x = x2;
    }
    if (dir == 2) {
      y2 = max(y_min, pe(A[x], y));
      x_max = x - 1;
      if (y2 >= y)
        break;
      else
        cnt += abs(y2 - y);
      y = y2;
    }
    if (dir == 3) {
      x2 = max(x_min, pe(B[y], x));
      y_min = y + 1;
      if (x2 >= x)
        break;
      else
        cnt += abs(x2 - x);
      x = x2;
    }
    dir = (dir + 1) % 4;
    st = 0;
  }
  if (cnt + k >= (ll)n * m) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
    // cout << cnt + k << " " << (ll)n * m << endl; // debug
  }
}
