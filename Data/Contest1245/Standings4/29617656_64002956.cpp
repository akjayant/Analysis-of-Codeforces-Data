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

int n, R, P, S;
string s;

void solve() {
  cin >> n >> R >> P >> S;
  cin >> s;

  map<char, int> m;
  for(auto c : s)
    m[c]++;

  int ans = 0;

  ans += min(R, m['S']);
  ans += min(P, m['R']);
  ans += min(S, m['P']);

  if(ans >= (n+1)/2) {
    cout << "YES" << endl;
    string ss;
    for (int i = 0; i < n; i++)
      ss += '@';

    for (int i = 0; i < n; i++) {
      if(s[i] == 'R') {
        if(P-- > 0)
          ss[i] = 'P';
      } else if(s[i] == 'P') {
        if(S-- > 0)
          ss[i] = 'S';
      } else {
        if(R-- > 0)
          ss[i] = 'R';
      }
    }

    for (int i = 0; i < n; i++) {
      if(ss[i] == '@') {
        if(R-- > 0)
          ss[i] = 'R';
        else if(P-- > 0)
          ss[i] = 'P';
        else
          ss[i] = 'S';
      }
    }
    cout << ss << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main (void) {
  ios_base::sync_with_stdio(false);

  int T;  cin >> T;
  while(T--)
    solve();

  return 0;
}
