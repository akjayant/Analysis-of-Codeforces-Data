#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


const int maxn = 1e6 + 5;

int main() {
  int q;
  cin >> q;

  for (int qq = 0; qq < q; ++qq) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<int> qwe;
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i]) {
        qwe.push_back(i);
      }
    }
    if (qwe.size() != 2) {
      cout << "NO\n";
    } else {
      string aa = a;
      string bb = b;

      swap(aa[qwe.front()], bb[qwe.back()]);
      if (aa == bb) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}
