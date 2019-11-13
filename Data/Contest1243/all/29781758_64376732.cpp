#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int k; cin >> k;
  for (int kkk = 0; kkk < k; kkk++) {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a.at(i);
    sort(a.begin(), a.end());
    int i = 0;
    for (; i < n; i++) {
      if (a.at(n-1-i) < i+1) break;
    }
    cout << i << endl;
  }

  return 0;
}

