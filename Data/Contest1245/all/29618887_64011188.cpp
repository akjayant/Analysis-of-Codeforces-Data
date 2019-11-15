#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

inline int add(int a, int b, int mod = mod) {
  a += b;
  if(a >= mod) a -= mod;
  if(a < 0) a += mod;
  return a;
}

inline int mul(int a, int b, int mod = mod) {
  return (long long) a * b % mod;
}

int dp[N];

string s;

int rec(int cur) {
  if(cur >= s.size() - 1) return 1;
  int& c = dp[cur];
  if(c != -1) return c;
  c = rec(cur + 1);
  if(s[cur] == 'n' && s[cur + 1] == 'n') {
    c = add(c, rec(cur + 2));
  }
  if(s[cur] == 'u' && s[cur + 1] == 'u') {
    c = add(c, rec(cur + 2));
  }
  return c;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> s;
  for(int i = 0; i < s.size(); ++i) {
    if(s[i] == 'm' || s[i] == 'w') {
      cout << 0 << "\n";
      return 0;
    }
  }
  memset(dp, -1, sizeof dp);
  cout << rec(0) << "\n";
}