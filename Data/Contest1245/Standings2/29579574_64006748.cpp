#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N = 1e6;
int dp[N];
signed main() {
    string s;
    cin>>s;
    dp[0] = 1;
    dp[1] = 1;
    int n = s.size();
    for(auto i : s)
    {
        if(i == 'm' || i == 'w')
        {
            cout<<0<<endl;
            return 0;
        }
    }
   for(int i = 2; i <= n; i++)
   {
       if(s[i - 1] == s[i - 2] && (s[i - 1] == 'u' || s[i - 1] == 'n'))
           dp[i] = dp[i - 1] + dp[i - 2];
       else
           dp[i] = dp[i - 1];
       dp[i] %= 1000000007;
   }
   cout<<dp[n]<<endl;
}