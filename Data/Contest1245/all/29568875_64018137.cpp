#include <bits/stdc++.h>

using namespace std;
string to_string(string s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int N = 1e5 + 10, mod = 1e9 + 7;
char str[N];
long long dp[N];

int main() {
	#ifdef LOCAL
	freopen("in", "r", stdin);
	#endif
	scanf("%s", str + 1);
	dp[0] = 1;
	int n = strlen(str + 1);
    for (int i = 1; i <= n; i++) {
    	if (str[i] == 'm' || str[i] == 'w') {
    		cout << 0 << endl;
    		return 0;
    	}
    	dp[i] = dp[i - 1];
    	if (str[i] == 'u' && str[i - 1] == 'u') {
    		dp[i] += dp[i - 2];
    	}
    	if (str[i] == 'n' && str[i - 1] == 'n') {
    		dp[i] += dp[i - 2];
    	}
    	dp[i] %= mod;
    }
    cout << dp[n] << endl;
    return 0;
}