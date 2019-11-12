#include<bits/stdc++.h>
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef vector<int> vec;
typedef vector<lld> vecl;
#define all(a) (a).begin(), (a).end()
// const int MIN = numeric_limits<int>::min();
// const int MAX = numeric_limits<int>::max();
// const lld MIN = numeric_limits<lld>::min();
// const lld MAX = numeric_limits<lld>::max();

lld f(lld a, lld b, lld m) {
  lld r=1, c=a;
  while (b) {
    if (b&1) r = (r*c)%m;
    b >>= 1;
    c = (c*c)%m;
  }
  return r;
}
int main() { ios_base::sync_with_stdio(0); cin.tie(0);
  lld n, m; cin >> n >> m;
  const lld M = 1000000007;
  m = (f(2, m, M) + M - 1) % M;
  cout << f(m, n, M) << endl;
  return 0;
}
