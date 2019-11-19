#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const ll modulo = 1e9 + 7;

struct Node {
  int n, l, r, ul, ur;
};

int check(string s) {
  int l = 0, p = 0, ur = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '(')
      l++;
    else {
      if (l > 0) {
        l--;
        if (l == 0)
          p++;
      } else {
        ur++;
        p = 0;
      }
    }
  }
  if (ur > 0)
    p++;
  return p;
}

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int l = 0;
  for (int i = 0; i < n; ++i)
    l += s[i] == '(';
  if (l != n - l) {
    cout << 0 << endl;
    cout << 1 << " " << 1 << endl;
    return 0;
  }

  int ans = check(s), li = 1, ri = 1;
  for (int i = 0; i < n - 1; ++i)
    for (int j = i + 1; j < n; ++j) {
      string t = s;
      if (s[i] != s[j])
        swap(t[i], t[j]);
      int res = check(t);
      if (res > ans) {
        ans = res;
        li = i + 1;
        ri = j + 1;
      }
    }

  cout << ans << endl;
  cout << li << " " << ri << endl;

  //  vector<vector<Node>> f(n + 1, vector<Node>(4));
  //  for (int i = 1; i <= n; ++i) {
  //    bool left = s[i] == '(';
  //    if (left) {
  //      f[i][0] = f[i-1][0];
  //      f[i][0].ul++;
  //
  //      f[i][1] = f[i-1][1];
  //      f[i][1].ul++;
  //
  //      f[i][2] = f[i-1][2];
  //      f[i][2].ul++;
  //      if (f[i-1][0].ul == 1)
  //
  //      f[i][3] = f[i-1][3];
  //      f[i][3].ul++;
  //    }
  //  }
}