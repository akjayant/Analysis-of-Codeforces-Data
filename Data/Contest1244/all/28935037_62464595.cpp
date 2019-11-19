#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repr(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define repChar(i) for (char i = 'a'; i <= 'z'; i++)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int tcs; cin >> tcs;
  rep(tc,0,tcs) {
    int a, b, c, d, k; cin >> a >> b >> c >> d >> k;

    int x = a / c; if (a % c != 0) x++;
    int y = b / d; if (b % d != 0) y++;

    if (x + y <= k) {
      cout << x << " " << y << endl;
    } else {
      cout << -1 << endl;
    }
  }
}
