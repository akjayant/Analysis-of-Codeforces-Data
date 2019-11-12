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

void init() {
  ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
}

int main() {
  init();
  int n;
  cin >> n;
  while (n--) {
    int a, b, c;
    cin >> a >> b >> c;
    int m = 0;
    rep(i, 0, 100) rep(j, 0, 100) {
      if (i <= a && 2 * i + j <= b && 2 * j <= c) {
        m = max(m, (i + j) * 3);
      }
    }
    cout << m << endl;
  }
}
