using namespace std;

template<class T> void pr(const T& x) { cout << x; }
template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) {
  pr(first); pr(rest...);
}

void ps() { pr("\n"); }
template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) {
  pr(first," "); ps(rest...);
}

typedef vector<int> vi;

const int MOD = 1000000007;
string str;
int dp[100005];

int main(int argc, const char **argv) {
  cin >> str;
  int ans = 1;
  int N = str.size();
  vi v;
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i < 100005; ++i) {
    dp[i] = (dp[i-1] + dp[i-2])%MOD;
  }

  for (int i = 0; i < N;) {
    if (str[i] == 'm' || str[i] == 'w') {
      return 0 * printf("0\n");
    }
    int l = 0;
    while (i < N && str[i] == 'n') {
      i++;
      l++;
    }
    if (l >= 1) {
      if (l > 1) ans = (1LL * ans * dp[l]) % MOD;
      continue;
    }
    l = 0;
    while (i < N && str[i] == 'u') {
      i++;
      l++;
    }
    if (l >= 1) {
      if (l > 1) ans = (1LL * ans * dp[l]) % MOD;
      continue;
    }
    ++i;
  }
  ps(ans);
  return 0;
}
