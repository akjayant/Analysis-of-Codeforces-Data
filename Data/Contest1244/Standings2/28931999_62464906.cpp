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


int n, a, b, c, d, k;

void met() {
  return;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  while (n--) {
    cin >> a >> b >> c >> d >> k;
    int x = (a+c-1)/c, y = (b+d-1)/d;
    if (x+y<=k) {
      cout << x << " " << y << endl;
    } else {
      cout << -1 << endl;
    }
  }
  
}
