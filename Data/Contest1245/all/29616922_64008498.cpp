#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(ll i = (a); i<= (b); ++i)
#define L first
#define R second

using namespace std;

const int M=1e5+5;
const ll INF = 1e18;
const ll MOD = 1e9+7;
ll dp[M+5];
string s;

int main() {
    ios::sync_with_stdio(0);
   // freopen("input.txt","r",stdin);
    dp[0] = dp[1] = 1;
    for(int i=1; i<M; i++) dp[i] = (dp[i-1] + dp[i-2])%MOD;
    cin>>s;
    s += 'z';
    ll cnt = 1, ans = 1;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == 'w' || s[i] == 'm') {
            cout<<0;
            return 0;
        }
        if(s[i] == s[i+1]) cnt++;
        else {
            if(s[i] == 'u' || s[i] == 'n') {
                ans = ans*dp[cnt]%MOD;
            }
            cnt = 1;
        }
    }
    cout<<ans;
    return 0;
}
