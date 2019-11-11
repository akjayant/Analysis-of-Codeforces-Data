#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long

ll calc_poss(ll n){
    vector<ll> leer(2);
    vector<vector<ll> > dp(n, leer);
    dp[0] = {1, 0};
    dp[1] = {1, 1};
    for(int i = 2; i < n; i++){
        dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % MOD;
        dp[i][1] = dp[i-1][0];
    }
    return (dp[n-1][0] + dp[n-1][1]) % MOD;
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    ll sol = 1;
    char bef = '0';
    int hwm = 0;
    bool poss = true;
    for(int i = 0; i<n; i++){
        if(s[i] == 'm' || s[i] == 'w'){
            poss = false;
            break;
        }
        if(s[i] != bef){
            if((bef == 'u' || bef == 'n') && hwm > 1){
                sol *= calc_poss(hwm);
                sol %= MOD;
            }
            bef = s[i];
            hwm = 1;
        }
        else{
            hwm++;
        }
    }

    if((bef == 'u' || bef == 'n') && hwm > 1){
        sol *= calc_poss(hwm);
        sol %= MOD;
    }

    cout << (poss ? sol : 0) << endl;

    return 0;
}
