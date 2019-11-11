#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  long long reco_table[100002];
  reco_table[1] = 1;
  reco_table[2] = 2;
  reco_table[3] = 3;

  for (int i =  4; i < 100002; i++) {
    reco_table[i] = reco_table[i - 2] + reco_table[i - 1];
    reco_table[i] %= 1000000007;

    if (i < 1000) {
      // cout << i << " " << reco_table[i] << endl;
    }
  }

  string s;
  cin >> s;

  int last_char_index = 0;
  long long num_strings = 1;
  for (int i = 1; i < s.size() + 1; i++) {
    if (i == s.size() || s[i] != s[last_char_index]) {
      int len = i - last_char_index;
      // cout << len << endl;
      if (s[last_char_index] == 'u' || s[last_char_index] == 'n') {
        // cout << "times: " << len << endl;
        num_strings *= reco_table[len];
        num_strings %= 1000000007;
      }

      last_char_index = i;
    }
  }

  for (char c : s) {
    if (c == 'm' || c == 'w') {
      cout << 0 << endl;
      return 0;
    }
  }

  cout << num_strings << endl;

  return 0;
}
