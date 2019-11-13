/*
 * "Voce acha que esta um passo a minha frente, mas na verdade,
 * estou uma volta ao mundo menos um passo a frente de voce", ppA, Lo (Jan, 2018)
*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

vector<int> v;
const ll mod = 1e9 + 7;
map<ii, int> dp;

ll go(int i, int j) {
  if(i >= (int)v.size())
    return 1;

  if(dp.count(ii(i, j)))
    return dp[ii(i, j)];
  int &r = dp[ii(i, j)];

  r = 0;

  if(j + 2 <= v[i]) {
    r = (r + go(i, j+2))%mod;
  }

  if(j + 1 <= v[i]) {
    r = (r + go(i, j+1))%mod;
  } else {
    r = go(i+1, 0);
  }

  return r;
}

void no() {
  cout << 0 << endl;
  exit(0);
}

int main (void) {
  ios_base::sync_with_stdio(false);

  string s; cin >> s;
  char last = '@';
  int cnt = 0;
  for(auto c : s) {
    if(c == 'w' or c == 'm')
      no();
    if(last == 'u' or last == 'n') {
      if(last == c) {
        cnt++;
      } else {
        v.pb(cnt+1);
        cnt = 0;
      }
    }
    last = c;
  }

  if(cnt)
    v.pb(cnt+1);

  cout << go(0, 0) << endl;

  return 0;
}
