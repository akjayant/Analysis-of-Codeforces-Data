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
  int t; cin >> t; while (t--) {
    int a, b, c, r=0; cin >> a >> b >> c;
    for (int i=0; i<=a && 2*i<=b; ++i) {
      r = max(r, 3*(i + min(b-2*i, c/2)));
    }
    cout << r << "\n";
  }
  return 0;
}
