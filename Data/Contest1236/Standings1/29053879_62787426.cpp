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
const int mod = 1e9 + 7;

void init() {
  ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
}

int qpow(int a, int b) {
  int re = 1;
  while (b) {
    if (b & 1)
      re = (ll)re * a % mod;
    b >>= 1;
    a = (ll)a * a % mod;
  }
  return re % mod;
}

int main() {
  init();
  int n, m;
  cin >> n >> m;
  cout << qpow((qpow(2, m) + mod - 1) % mod, n) << endl;
}
