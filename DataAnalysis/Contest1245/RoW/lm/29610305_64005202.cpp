using namespace std;


const int MOD = 1e9 + 7;

void solve() {
 string str;
 cin >> str;
 if (count((str).begin(), (str).end(), 'm') > 0 || count((str).begin(), (str).end(), 'w') > 0) {
  cout << 0 << endl;
  return;
 }
 int n = (int)(str).size();
 vector<int> dp(n + 1);
 dp[0] = 1;
 dp[1] = 1;
 for (int i = 2; i <= n; i++) {
  if (str[i - 1] == 'u' && str[i - 2] == 'u')
   dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
  else if (str[i - 1] == 'n' && str[i - 2] == 'n')
   dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
  else
   dp[i] = dp[i - 1];
 }
 cout << dp[n] << endl;
}

int main() {
 ios::sync_with_stdio(false); cin.tie(0);

 int t = 1;

 while (t--)
  solve();
}
