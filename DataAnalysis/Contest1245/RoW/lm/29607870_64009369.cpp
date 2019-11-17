using namespace std;
void Main();




int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  Main();
}


const int N = 1e5 + 10, MOD = 1e9 + 7;

int dp[N];

void Main() {
  string s; cin >> s;
  const int n = s.size();
  for(int i = 0; i < n; i++) {
    if(s[i] == 'm' || s[i] == 'w') {
      cout << "0\n";
      return;
    }
  }
  dp[1] = dp[0] = 1;
  for(int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1];
    if(s[i - 1] == s[i - 2] && (s[i - 1] == 'u' || s[i - 1] == 'n')) {
      dp[i] += dp[i - 2];
      if(dp[i] >= MOD) {
        dp[i] -= MOD;
      }
    }
  }
  cout << dp[n] << "\n";
}
