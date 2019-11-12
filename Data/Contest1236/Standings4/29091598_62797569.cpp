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

int main() { ios_base::sync_with_stdio(0); cin.tie(0);
  lld n; cin >> n;
  vector<vec> r(n);
  for (int j=0; j<n; ++j) {
    for (int i=0; i<n; ++i) {
      if (i) cout << " ";
      cout << ((i&1) ? (i+1)*n-j : i*n+j+1);
    }
    cout << "\n";
  }
  return 0;
}
