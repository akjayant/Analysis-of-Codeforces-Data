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

      vector<int> counts(26);
      for (int i = 0; i < n; i++) {
	counts[s[i] - 'a']++;
	counts[t[i] - 'a']++;
      }

      auto invalid = false;
      for (int alpha = 0; alpha < 26; alpha++) {
	if (counts[alpha] % 2 == 1) {
	  invalid = true;
	  break;
	}
      }
      if (invalid) {
	cout << "No" << '\n';
      } else {
	cout << "Yes" << '\n';
      

	auto swaps = vector<pair<int, int>>{};

	for (int i = 0; i < n; i++) {
	  if (s[i] != t[i]) {
	    int first_s = -1;
	    int first_t = -1;
	    for (int j = n - 1; j >= i + 1; j--) {
	      if (s[j] == s[i]) {
		first_s = j;
	      }
	      if (t[j] == s[i]) {
		first_t = j;
	      }
	    }

	    vector<pair<int, int>> need;
	    if (first_s != -1) {
	      need.push_back({first_s, i});
	    } else {
	      need.push_back({first_t, first_t});
	      need.push_back({first_t, i});
	    }
	    for (auto [si, sj]: need) {
	      swaps.push_back({si, sj});
	      swap(s[si], t[sj]);
	    }
	  }
	}

	cout << swaps.size() << '\n';
	for (auto [i, j] : swaps) {
	  cout << (i + 1) << " " << (j + 1) << '\n';
	}
	assert(s == t);
      }
    }
}
