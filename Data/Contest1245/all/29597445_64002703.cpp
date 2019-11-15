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

const int mod = 1e9 + 7;
const int N = 1e5 + 10;
char s[N];
int n;
ll fib[N];

int main() {
  // ios::sync_with_stdio(0);
  // cin.tie(0); cout.tie(0);

  fib[0] = fib[1] = 1;
  for (int i = 2; i < N; i++) {
    fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
  }

  scanf("%s", s);
  n = strlen(s);

  vi g;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'm' || s[i] == 'w') {
      cout << 0 << endl;
      return 0;
    }
    if (i == 0) {
      if (s[i] == 'u' || s[i] == 'n') {
        g.pb(1);
      }
    } else {
      if (s[i - 1] == s[i] && (s[i] == 'u' || s[i] == 'n')) {
        g.back()++;
      } else if (s[i] == 'u' || s[i] == 'n') {
        g.pb(1);
      }
    }
  }


  ll ans = 1;
  for (int x : g) {
    ans = ans * fib[x] % mod;
  }
  cout << ans << endl;

  return 0;
}