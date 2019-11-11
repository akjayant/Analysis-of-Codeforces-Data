#include <bits/stdc++.h>

using namespace std;

const long long myMod = 1e9 + 7;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  long long n = s.size();
  vector<long long> dp(n + 1, 0);
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  for(long long i = 3; i <= n; i++)
  {
    dp[i] = (dp[i - 1] + dp[i - 2]) % myMod;
  }
  vector<long long> lens;
  for(long long i = 0; i < n;)
  {
    if(s[i] == 'm' || s[i] == 'w')
    {
      cout << "0" << endl;
      return 0;
    }
    if(s[i] == 'n' || s[i] == 'u')
    {
      long long j = i;
      for(; j < n && s[j] == s[i]; j++);
      lens.push_back(j - i);
      i = j;
    }
    else
      i++;
  }
  long long sz = lens.size();
  long long ans = 1;
  for(long long i = 0; i < sz; i++)
  {
    ans = (ans * dp[lens[i]]) % myMod;
  }
  cout << ans << endl;
  return 0;
}
