#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vii = vector<ii>;
const ll MOD = 1e9+7;
const int INF = 1e9+9;
const int MAXN = 1000006;


int n, m, k, arr[MAXN], good, bad;
bool feasible = true;
string s;
char c, t[MAXN], C[MAXN];


ll fib[MAXN];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fib[0] = fib[1] = 1;
  for (int i = 2; i < MAXN; i++) {
    fib[i] = (fib[i-1]+fib[i-2])%MOD;
  }

  cin >> s;
  n = s.size();
  ll ans = 1;
  for (int i = 0; i < n; i++) {
    int c = 0;
    if (s[i] == 'u') {
      while (i < n && s[i] == 'u') {
        i++;
        c++;
      }
      i--;
    } else if (s[i] == 'n') {
      while (i < n && s[i] == 'n') {
        i++;
        c++;
      }
      i--;
    }
    ans=ans*fib[c]%MOD;
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == 'm' || s[i] == 'w') ans = 0;
  }
  cout << ans << endl;
}
