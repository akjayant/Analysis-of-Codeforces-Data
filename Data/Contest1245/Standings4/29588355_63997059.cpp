#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int T;
  cin >> T;

  while (T--) {
    int a, b;
    cin >> a >> b;

    if (__gcd(a, b) > 1) {
      cout << "INFINITE" << endl;
    } else {
      cout << "FINITE" << endl;
    }
  }

  return 0;
}
