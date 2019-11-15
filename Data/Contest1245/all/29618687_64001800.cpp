#include <bits/stdc++.h>
using namespace std;

map<char, char> beats = {{'R', 'P'},
			 {'P', 'S'},
			 {'S', 'R'}};

map<char, int> index = {{'R', 0},
			{'P', 1},
			{'S', 2}};
vector<char> moves = {'R', 'P', 'S'};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
      int n;
      cin >> n;
      vector<int> counts(3);
      for (int i = 0; i < 3; i++) {
	cin >> counts[i];
      }
      string s;
      cin >> s;

      string sol(s.length(), '-');
      int won = 0;
      int require = (n / 2) + (n & 1);
      for (int i = 0; i < s.length(); i++) {
	auto need = beats[s[i]];
	auto ind = index[need];
	if (counts[ind] > 0) {
	  sol[i] = need;
	  counts[ind]--;
	  won++;
	}
      }

      if (won < require) {
	cout << "NO" << '\n';
      } else {

	for (int i = 0; i < s.length(); i++) {
	  if (sol[i] == '-') {
	    for (int type = 0; type < 3; type++) {
	      if (counts[type] > 0) {
		sol[i] = moves[type];
		counts[type]--;
		break;
	      }
	    }
	  }
	}

	cout << "YES" << '\n';
	cout << sol << '\n';

      }
    }
    
}
