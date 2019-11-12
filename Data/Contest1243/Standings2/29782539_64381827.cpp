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
      string s, t;
      cin >> s >> t;

      vector<int> diffs;
      for (int i = 0; i < n; i++) {
	if (s[i] != t[i]) {
	  diffs.push_back(i);
	}
      }
      if ((diffs.size() == 2 and s[diffs[0]] == s[diffs[1]] and t[diffs[0]] == t[diffs[1]]) or (diffs.size() == 0)) {
	cout << "Yes" << '\n';
      } else {
	cout << "No" << '\n';
      }
    }
}
