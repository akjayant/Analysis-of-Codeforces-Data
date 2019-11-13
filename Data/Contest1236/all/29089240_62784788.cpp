#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repr(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define repChar(i) for (char i = 'a'; i <= 'z'; i++)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int tcs; cin >> tcs;
  rep(tc,0,tcs) {
    int a, b, c; cin >> a >> b >> c;

    int total = 0;
    while (b > 0 && c > 1) {
      total += 3;
      b -= 1;
      c -= 2;
    }
    while (a > 0 && b > 1) {
      total += 3;
      a -= 1;
      b -= 2;
    }
    cout << total << endl;
  }
}
