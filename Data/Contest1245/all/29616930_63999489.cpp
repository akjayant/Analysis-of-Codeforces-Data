#include <bits/stdc++.h>
using namespace std;
template <typename T > inline void MIN(T &a, T b) { if(a>b) a=b; }
template <typename T > inline void MAX(T &a, T b) { if(a<b) a=b; }
const int N=100005;
string s;
const int mod=1000000007;
long long dp[N];
long long ans=1;

long long calc(int leng) {
    for(int i=0 ; i<=leng ; ++i) dp[i]=0;
    dp[0]=dp[1]=1;
    for(int i=2 ; i<=leng ; ++i) {
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    }
    return dp[leng];
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    cin >> s;
    for(char c:s) {
        if(c=='m' || c=='w') return cout << 0, 0;
    }
    int id=0;
    while(id<s.size()) {
        if(s[id]=='u' || s[id]=='n') {
            int cnt=id;
            for(; id+1<s.size()&&s[id+1]==s[id] ; ++id);
            cnt=id-cnt+1;

            ans=(ans*calc(cnt))%mod;
            ++id;
        } else {
            ++id;
        }

    }
    cout << ans;

    return 0;
}
