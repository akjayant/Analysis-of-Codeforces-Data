#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<pll,pll> ppll;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fst first
#define snd second
#define ins insert
#define pb push_back

const int N = 5e5 + 5;
const int MOD = 1e9 + 7;

ll ans = 1;
ll dp[N];
void upd(ll cnt){
    ans *= dp[cnt];
    ans %= MOD;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    string s;
    cin >> s;
    for(auto &it : s){
        if(it == 'm' || it == 'w')return cout << 0,0;
    }
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3;i < N; ++i){
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    ll cnt = 1;
    for(int i = 1;i < s.size(); ++i){
        if(s[i] == s[i - 1])cnt++;else{
            if(s[i - 1] == 'u' || s[i - 1] == 'n'){
                upd(cnt);
            }
            cnt = 1;
        }
    }
    if(s.back() == 'u' || s.back() == 'n'){
        upd(cnt);
    }
    cout << ans;
    return 0;
}
