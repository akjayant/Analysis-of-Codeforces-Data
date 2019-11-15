#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define debug(n1) cout << n1 << endl;
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

using namespace std;

const string __sep = "\n";

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (size_t tt = 0; tt < t; ++tt) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    if (s == t) {
      cout << "YES\n";
    } else {
      vector<int> nums(26, 0);
      for (int i =0 ;i < n; ++i) {
        nums[s[i] - 'a']++;
        nums[t[i] - 'a']--;
      }
      bool bad = false;
      for (int i = 0 ; i < 26; ++i) if (nums[i] & 1) {
        cout << "NO\n";
        bad = true;
        break;
      }
      if (bad) continue;
      int m = 0;
      cout << "YES\n";
      string ans = "";
      for (int i = 0; i < n; ++i) {
        char cur = s[i];
        if (cur == t[i]) continue;
        bool found = false;
        for (int j = i + 1; j < n; ++j) {
          if (t[j] == t[i]) {
            ++m;
            ans += to_string((i + 1)) + " " + to_string(j + 1) + "\n";
            t[j] = s[i];
            found = true;
            break;
          } else if (s[j] == s[i]) {
            ++m;
            ans += to_string((j + 1)) + " " + to_string(i + 1) + "\n";
            s[j] = t[i];
            found = true;
            break;
          }
        }
        if (found) continue;
        int i1 = -1;
        int i2 = -1;
        for (int j = i + 1; j < n; ++j) {
          if (t[j] == s[i]) i2 = j;
          if (s[j] == t[i]) i1 = j;
        }
        assert (i1 >= 0 && i2 >= 0);
        assert (s[i] == t[i2]);
        assert (t[i] == s[i1]);

        m += 2;
        ans += to_string((i1 + 1)) + " " + to_string(i2 + 1) + "\n";
        ans += to_string((i + 1)) + " " + to_string(i2 + 1) + "\n";
        s[i1] = s[i];
      }
      cout << m << "\n";
      cout << ans;
    }
  }

  return 0;
}
