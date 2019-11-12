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
const int maxn = 1000;

void init() {
  ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
}

int a[maxn][maxn];

int main() {
  init();
  int n;
  cin >> n;
  int cnt = 0;
  rep(i, 0, n) rep(j, 0, n) {
    if (i % 2) {
      int k = j;
      a[k][i] = ++cnt;
    } else {
      int k = n - 1 - j;
      a[k][i] = ++cnt;
    }
  }
  rep(i, 0, n) {
    rep(j, 0, n) { cout << a[i][j] << (j == n - 1 ? "" : " "); }
    cout << endl;
  }
}
