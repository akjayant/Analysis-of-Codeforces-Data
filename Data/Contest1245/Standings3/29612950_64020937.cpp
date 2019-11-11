#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+5;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll mod = 1e9+7;

int n;
string s;
ll dp[maxn];
inline void init(){
    int N = 1e5+5;
    dp[0] = 1, dp[1] = 1;
    for(int i = 2; i <= N; i++)
        dp[i] = (dp[i-1] + dp[i-2])%mod;
}
int main(){
    init();
    cin>>s;
    bool flag = true;
    ll ans = 1;
    for(int i = 0; i < s.size() && flag; i++){
        if(s[i] == 'w' || s[i] == 'm') flag = false;
        if(s[i] == 'u' || s[i] == 'n'){
            int j;
            for(j = i+1; j < s.size(); j++)
                if(s[j] != s[i]) break;
            ans = (ans*dp[j-i])%mod;
            i = j-1;
        }
    }
    if(flag) printf("%lld\n", ans);
    else puts("0");
	return 0;
}
