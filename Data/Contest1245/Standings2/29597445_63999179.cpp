#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define pii pair<int, int>
#define endl '\n'
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vpii vector<pii>
typedef long long ll;
typedef long double ld;
using namespace std;
template<class T> using minheap = priority_queue<T, vector<T>, greater<T>>;

char x[110];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, a, b, c;
    string Z;
    cin >> n >> a >> b >> c >> Z;
    for (int i = 0; i < n; i++) {
      x[i] = 0;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (Z[i] == 'R') {
        if (b) {
          ++cnt;
          --b;
          x[i] = 'P';
        }
      }
      if (Z[i] == 'P') {
        if (c) {
          ++cnt;
          --c;
          x[i] = 'S';
        }
      }
      if (Z[i] == 'S') {
        if (a) {
          ++cnt;
          --a;
          x[i] = 'R';
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (x[i] == 0) {
        if (a) {
          --a; x[i] = 'R';
        } else if (b) {
          --b; x[i] = 'P';
        } else {
          --c; x[i] = 'S';
        }
      }
    }
    if (2 * cnt >= n) {
      cout << "YES\n";
      for (int i = 0; i < n; i++) {
        cout << x[i];
      }
      cout << endl;
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}