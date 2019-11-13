#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define fff ff
#define sss ss.ff
#define ttt ss.ss
#define INF (1 << 30)
#define LLF (1ll << 60)
#define PRIME (1000000007)
#define FASTIO std::ios::sync_with_stdio(false)
#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif
#define rep(i, begin, end)                            \
  for (__typeof(end) i = (begin) - ((begin) > (end)); \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define FILE_INPUT                  \
  freopen("input.txt", "r", stdin); \
  freopen("output.txt", "w", stdout)

#define all(x) x.begin(), x.end()

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<string> vs;

/*-----------------END TEMPLATE-----------------*/

int main() {
  FASTIO;
  int k;
  cin >> k;
  while (k--) {
    int n;
    cin >> n;
    vi count(1011, 0);
    vi a(n);
    rep(i, 0, n) {
      cin >> a[i];
      count[a[i]]++;
    }
    int mx = 0;
    for (int i = 1000; i >= 1; i--) {
      count[i] += count[i + 1];
      if (count[i] >= i) {
        mx = max(mx, i);
      }
    }
    cout << mx << endl;
  }
}
