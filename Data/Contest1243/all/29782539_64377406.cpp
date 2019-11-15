#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
      int n;
      cin >> n;

      vector<int> a(n);
      for (auto& i: a) {
	cin >> i;
      }

      int sol = 1;
      for (int i = n; i >= 1; i--) {
	if (count_if(begin(a), end(a), [&](auto num){return num >= i;}) >= i) {
	    sol = i;
	    break;
	  }
      }
      cout << sol << '\n';
    }
}
