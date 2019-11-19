#include <bits/stdc++.h>
using namespace std;

int t;
int main() {
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    int minpos = -1;
    int maxpos = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        maxpos = i;
        if (minpos == -1) minpos = i;
      }
    }

    int dist = 0;
    if (minpos != -1 && maxpos != -1) {
      dist = max(
        max(n - minpos, minpos + 1), 
        max(n - maxpos, maxpos + 1)
      );
    }
    cout << max(dist * 2, n) << endl;
  }
}
