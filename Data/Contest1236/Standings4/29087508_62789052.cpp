#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int dp[105][105][105];
int solve(int a, int b, int c)
{
  int &ret = dp[a][b][c];
  if(~ret)
    return ret;
  ret = 0;
  if(a >= 1 && b >= 2)
     ret = max(ret, 3 + solve(a - 1, b - 2, c));
  if(b >= 1  && c >= 2)
    ret = max(ret, 3 + solve(a, b - 1, c - 2));
  return ret;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifdef ONLINE_JUDGE
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);
    #endif
    int t;
    cin >> t;
    memset(dp, -1, sizeof dp);
    while(t--)
    {
      int a, b, c;
      cin >> a >> b >> c;
      cout << solve(a, b, c) << '\n';
    }
    return 0;
}
