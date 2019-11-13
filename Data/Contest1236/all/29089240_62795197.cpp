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

  int n; cin >> n;
  vi xs(n*n);
  rep(i,0,sz(xs)) xs[i] = i + 1;
  reverse(all(xs));

  rep(i,0,n) {
    bool even = true;
    rep(j,0,n) {
      cout << (even ? xs[j * n + i] : xs[j * n + (n - i - 1)]) << " ";
      even = !even;
    }
    cout << endl;
  }
}
