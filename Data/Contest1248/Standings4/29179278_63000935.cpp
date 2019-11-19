#include <bits/stdc++.h>
#define endl '\n'
#define f first
#define s second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int oo = numeric_limits<int>::max();

const int MAXN = 1e5, W = 0, B = 1;
const ll M = 1e9 + 7;
ll dp[MAXN][2][2];

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);

  dp[0][W][0] = dp[0][B][0] = 1;
  for (int i = 1; i < MAXN; i++) {
    dp[i][W][0] = (dp[i-1][B][0] + dp[i-1][B][1]) % M;
    dp[i][W][1] = dp[i-1][W][0];
    dp[i][B][0] = (dp[i-1][W][0] + dp[i-1][W][1]) % M;
    dp[i][B][1] = dp[i-1][B][0];
  }

  int n, m;
  cin >> n >> m;
  ll a = dp[n-1][W][0] + dp[n-1][W][1] + dp[n-1][B][0] + dp[n-1][B][1];
  ll b = dp[m-1][W][0] + dp[m-1][W][1] + dp[m-1][B][0] + dp[m-1][B][1];
  ll ans = a - 2 + b;

  cout << ans % M << endl;

  return 0;
}
