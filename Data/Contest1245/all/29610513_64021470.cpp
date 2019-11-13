#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

string s;
int n;
vector<ll> dp;

ll get(int i){
    if(i < 0)return 1;
    else return dp[i];
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr); cout.tie(nullptr);
    cin >> s; n = s.size();
    dp.resize(n);   

    for(int i = 0; i < n; i++){
        if(s[i] == 'm' || s[i] == 'w'){
            cout << 0 << endl;
            return 0;
        }
        dp[i] = get(i-1);
        if(i){
            if(s[i] == 'u' && s[i-1] == 'u') {
                dp[i] += get(i-2); 
                dp[i] %= MOD;
            }else if(s[i] == 'n' && s[i-1] == 'n'){
                dp[i] += get(i-2);
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[n-1] << endl;
}
