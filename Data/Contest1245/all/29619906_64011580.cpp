#include <bits/stdc++.h>
#define D if(false)

using namespace std;

typedef long long ll;
const ll MOD = pow(10, 9) + 7;

int main() {
  string s; cin >> s;
  ll n = s.size();

  vector<ll> table(n+1, 0);

  table[1] = 1;
  table[0] = 1;
  for(ll i = 2; i <= n; i++) {
    if(i >= 2)
      table[i] = (table[i] + table[i-2]) % MOD;
    table[i] = (table[i] + table[i-1]) % MOD;
  }

  D {
    for(ll i = 0; i <= n; i++) {
      cout << table[i] << endl;
    } cout << endl;
  }

  ll ret = 1;
  ll count = 1;

  if(s[0] == 'm' || s[0] == 'w')
    ret = 0;
  for(ll i = 1; i < n; i++) {
    if((s[i] == 'n' || s[i] == 'u') && s[i] == s[i-1]) {
      count++;
    } else {
      // take the count
      if(s[i-1] == 'n' || s[i-1] == 'u') {
        ret = (ret * table[count]) % MOD;
      }

      count = 1;
    }

    if(s[i] == 'm' || s[i] == 'w')
      ret = 0;
  }

  if(s.back() == 'n' || s.back() == 'u') {
    ret = (ret * table[count]) % MOD;
  }

  cout << ret << endl;

  return 0;
}
