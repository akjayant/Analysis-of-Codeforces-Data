#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

ll dp[100010];

ll M = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

  dp[0] = 1;
  dp[1] = 1;
  for (ll i=2; i<100010; ++i) {
    dp[i] = (dp[i-2]+dp[i-1])%M;
  }
  
  string s;
  cin>>s;
  ll n = s.size();
  ll ans = 1;
  for (ll i=0; i<n ;++i) {
    if (s[i]=='m' || s[i]=='w') {
      cout<<0<<endl;
      return 0;
    }
    if (s[i]!='u' && s[i]!='n') continue;
    char c=s[i];
    ll count=0;
    while(i<n && s[i]==c) {
      count++;
      i++;
    }
    if (i!=n) i--;
    ans = (ans*dp[count])%M;
  }
  cout<<ans<<endl;
}