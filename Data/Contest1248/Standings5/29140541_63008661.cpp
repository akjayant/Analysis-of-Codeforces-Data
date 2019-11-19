#include<bits/stdc++.h>
 using namespace std;

#define  int  long long
#define  endl  '\n'
const int mod = 1e9 + 7;
const int N = 1e5 + 2;

int modexp(int base, int exp,int M)
{
    if(exp == 0)
       return 1;

    int x = modexp(base, exp / 2, M);
    x = (x * x) % M;
    if(exp & 1)
      x = (base * x) % M;

    return x;
}

int dp[N];

int32_t main()
{ 
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif 

  int n,m;

  cin >> n >> m;
  int mx=max(n,m);

  dp[0] = dp[1] = 1LL;
  dp[2]=2;

  for(int i = 3; i <= mx; i++)
  {
    dp[i] = dp[i - 1] % mod + dp[i - 2] % mod;
  }
  
  int ans=(((dp[m] + dp[n] - 1) % mod + mod ) * 2) % mod;
  
  cout << ans;

  return 0;
}