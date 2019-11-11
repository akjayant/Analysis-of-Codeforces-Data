#include <bits/stdc++.h>
using namespace std;

#define sc(x) scanf("%d",&x);
#define rep(x ,n) for(int x=0; x<n; x++)
#define ll long long
#define finish(x) return cout << x << endl,0;
#define scarr(a,n) for(int x=0; x<n; x++)scanf("%d",&a[x]);

#define MAX_N 2003
const int mod = 1e9+7;

int main()
{
    string s;
    cin >> s;

    if(count(s.begin() ,s.end() ,'m') || count(s.begin() ,s.end() ,'w')){
        cout << 0 << endl;
        return 0;
    }

    s = '-' + s;
    vector <int> dp(s.size());
    dp[0] = 1;
    for(int i=1; i<s.size(); i++){
        dp[i] = dp[i-1];
        if(s[i] == 'u' && s[i-1] == 'u')
            dp[i] = (dp[i]+dp[i-2])%mod;
        if(s[i] == 'n' && s[i-1] == 'n')
            dp[i] = (dp[i]+dp[i-2])%mod;
    }
    cout << dp[s.size()-1] << endl;
}
