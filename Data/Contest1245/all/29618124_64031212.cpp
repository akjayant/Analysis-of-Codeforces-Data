#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, pii> piii;
typedef double lf;

const int N = 32;
const int MOD = 1e9+7;
const ll oo = 1e18;

int a, b;
ll dp[N][2][2];
ll go(int i, int menor_a, int menor_b) {
  if(i == -1) {
//    cout << "base" << endl;
    return 1;
  }
  ll &r = dp[i][menor_a][menor_b];
  if(r == -1) {
    r = 0;
    int lim_a = (menor_a ? 1 : (a >> i)&1);
    int lim_b = (menor_b ? 1 : (b >> i)&1);
    for(int bit_a = 0; bit_a <= lim_a; bit_a++) {
      for(int bit_b = 0; bit_b <= lim_b; bit_b++) {
        if(!(bit_a == bit_b && bit_a == 1)) {
          r += go(i-1, menor_a || (bit_a < ((a>>i)&1)), menor_b || (bit_b < ((b>>i)&1)));
        }

      }
    }
  }
  return r;
}

ll calc(int x, int y) {
  if(x < 0 || y < 0) return 0;
  a = x, b = y;
  memset(dp, -1, sizeof dp);
  ll t = go(31, 0, 0);
  //cout << a << " " << b << " " << t << endl;
  return t;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #else
    #define endl '\n'
  #endif


  int t; cin >> t;
  while(t--) {
    int l, r; cin >> l >> r;
    cout << calc(r, r) - calc(r, l-1) - calc(l-1, r) + calc(l-1, l-1) << endl;
  }
  
}