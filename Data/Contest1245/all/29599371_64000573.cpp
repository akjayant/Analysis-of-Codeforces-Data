#include<stdio.h>
#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<stack>
#include<algorithm>
#include<string>
#include<string.h>
#include<assert.h>
#include<iomanip>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll fpb(ll a, ll b){
    if(b == 0)return a;
    return fpb(b, a % b);
}

const int N = 1e5;
const int MOD = 1e9 + 7;

ll dp[N + 5];
ll rec(int idx){
    if(idx <= 1)return 1;
    if(dp[idx] != -1)return dp[idx];
    ll res = (rec(idx - 1) + rec(idx - 2)) % MOD;
    return dp[idx] = res;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp,-1,sizeof dp);
    string s; cin >> s;
    ll ans = 1;
    int cnt = 0;
    char bef = ' ';
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == 'm' || s[i] == 'w')ans = 0;
        else{
            if(s[i] == 'n' || s[i] == 'u'){
                if(s[i] == bef)cnt++;
                else{
                    ans *= rec(cnt);
                    ans %= MOD;
                    cnt = 1;
                }
            }else{
                ans *= rec(cnt);
                ans %= MOD;
                cnt = 0;
            }

            bef = s[i];

        }
    }

    ans *= rec(cnt);
    ans %= MOD;

    cout << ans << endl;
}