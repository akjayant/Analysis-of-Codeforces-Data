#include<bits/stdc++.h>
typedef long long int ll;

using namespace std;

const int MAXN = 1e5 + 123;
const ll MOD = 1e9 + 7;
ll dp[MAXN];

int main(){
    dp[0] = 1ll;
    dp[1] = 1ll;
    for(int i = 2; i < MAXN - 100; i ++)
        dp[i] = dp[i - 1] + dp[i - 2],
        dp[i] %= MOD;
    string s;
    cin >> s;
    ll ans = 1;
    for(int i = 0; i < s.size(); i ++){
        int j = i;
        if(s[i] == 'm' || s[i] == 'w'){
            cout << 0;
            return 0;
        }
        if(s[i] != 'n' && s[i] != 'u')
            continue;
        while(j < s.size() && s[j] == s[i])
            j ++;
        ans *= dp[j - i];
        ans %= MOD;
        i = j - 1;
    }
    cout << ans;
}
