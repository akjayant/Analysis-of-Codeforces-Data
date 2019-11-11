#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int dp[100000 + 1];

ll fib(ll n){
    if(dp[n] != -1){
        return dp[n];
    }
    if(n == 1){
        return 1;
    }else if(n == 2){
        return 2;
    }else{
        return dp[n] = (fib(n - 1) + fib(n - 2)) % MOD;
    }
}

signed main(){
    memset(dp, -1, sizeof(dp));
    string s;
    cin >> s;
    ll ans = 1;
    ll u = 0, n = 0;
    REP(i,s.size()){
        if(s[i] == 'u'){
            if(n > 1){
                ans *= fib(n);
                ans %= MOD;
            }
            u++;
            n = 0;
        }else if(s[i] == 'n'){
            if(u > 1){
                ans *= fib(u);
                ans %= MOD;
            }
            n++;
            u = 0;
        }else if(s[i] == 'w'){
            cout << 0 << endl;
            return 0;
        }else if(s[i] == 'm'){
            cout << 0 << endl;
            return 0;
        }else{
            if(u > 1){
                ans *= fib(u);
                ans %= MOD;
            }else if(n > 1){
                ans *= fib(n);
                ans %= MOD;
            }
            u = 0;
            n = 0;
        }
    }
    if(u > 1){
        ans *= fib(u);
        ans %= MOD;
    }else if(n > 1){
        ans *= fib(n);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}