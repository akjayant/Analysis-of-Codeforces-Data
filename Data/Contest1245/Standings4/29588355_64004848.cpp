#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int ar, ap, as;
    cin >> ar >> ap >> as;

    string s;
    cin >> s;
    int br = 0, bp = 0, bs = 0;
    for (char c : s) {
      if (c == 'R') {
        br++;
      }
      if (c == 'P') {
        bp++;
      }
      if (c == 'S') {
        bs++;
      }
    }

    // cout << s << endl;

    int total = ar + ap + as;
    int wins = min(ar, bs) + min(ap, br) + min(as, bp);
    if (wins > (total - 1) / 2) {
      cout << "YES" << endl;
      // Now distribute to RPS string.
      vector<char> result(s.size(), 'z');
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'R' && ap) {
          ap--;
          result[i] = 'P';
        }
        if (s[i] == 'P' && as) {
          as--;
          result[i] = 'S';
        }
        if (s[i] == 'S' && ar) {
          ar--;
          result[i] = 'R';
        }
      }
      for (int i = 0; i < s.size(); i++) {
        if (result[i] == 'z') {
          if (ap) {
            ap--;
            result[i] = 'P';
          } else if (as) {
            as--;
            result[i] = 'S';
          } else if (ar) {
            ar--;
            result[i] = 'R';
          }
        }
        cout << result[i];
      }
      cout << endl;

    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
