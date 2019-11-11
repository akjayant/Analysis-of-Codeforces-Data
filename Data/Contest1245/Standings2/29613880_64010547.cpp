#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int mod = (int)1e9 + 7;

char s[100005];
ll dp[100050];

int main()
{
    scanf("%s",s + 1);
    int n = strlen(s + 1);

//    dp[0][0]
    dp[0] = dp[1] = 1;
    for(int i = 2;i <= n;i++){
        dp[i] = dp[i-2] + dp[i-1];
        if(dp[i] > mod) dp[i] -=  mod;
    }

    ll ans = 1;
    int now = 0;
    for(int i = 1 ;i<=n;i++){
        if(s[i] == 'u'){
            now ++;
        }
        else{
            if(now){
                ans *= dp[now];
                ans %= mod;
            }
            now = 0;
        }
    }
    if(now) ans *= dp[now];
    ans %= mod;

    now = 0;
    for(int i = 1 ;i<=n;i++){
        if(s[i] == 'n'){
            now ++;
        }
        else{
            if(now){
                ans *= dp[now];
                ans %= mod;
            }
            now = 0;
        }
    }
    if(now) ans *= dp[now];
    ans %= mod;


    for(int i = 1 ;i<=n;i++){
        if(s[i] == 'w') ans=0;
        if(s[i] == 'm') ans=0;
    }

    cout << ans;


    return 0;
}
