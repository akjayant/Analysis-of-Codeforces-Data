#include <bits/stdc++.h>
#define endl '\n'
#define f first
#define s second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int oo = numeric_limits<int>::max();

const int MAXW = 1e5;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);

  ll n, p, w, d;
  cin >> n >> p >> w >> d; 

  ll wins = p / w;
  for (int i = 0; i < MAXW && wins >= 0; i++) {
    if ((p - wins * w) % d) {
      wins--;
      continue;
    }

    ll draws = (p - wins * w) / d;
    if (wins + draws <= n) {
      cout << wins << ' ' << draws << ' ' << n - wins - draws << endl;
      return 0;
    }
  }
  cout << -1 << endl;

  return 0;
}
