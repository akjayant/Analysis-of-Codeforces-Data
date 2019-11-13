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

int main (void) {
  ios_base::sync_with_stdio(false);
  int T;  cin >> T;

  while(T--) {
  int a, b; cin >> a >> b;

  if(__gcd(a, b) == 1) {
    cout << "Finite" << endl;
  } else {
    cout << "Infinite" << endl;
  }
  }

  return 0;
}
