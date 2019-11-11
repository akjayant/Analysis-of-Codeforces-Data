#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1000000007;
main(){
    int f[200005];
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'm' || s[i] == 'w'){
            printf("0");
            return 0;
        }
    }
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= s.size(); i++){
        f[i] = (f[i-1]+f[i-2])%mod;
    }
    char cur = s[0];
    int ct = 1;
    int ans = 1;
    for (int i = 1; i < s.size(); i++){
        if (s[i] == cur){
            ct++;
        }
        else{
            if (cur == 'u' || cur == 'n'){
                ans *= f[ct];
                ans %= mod;
            }
            cur = s[i];
            ct = 1;
        }
    }
    if (cur == 'u' || cur == 'n'){
        ans *= f[ct];
        ans %= mod;
    }
    printf("%lld\n",ans);
}
