#include <bits/stdc++.h>
#define x first
#define y second
#define int long long

using namespace std;
const int mod = 1000000007;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int qq = 1;
    //cin >> qq;
    for(int qqq = 0; qqq<qq; qqq++){
        string s;
        cin >> s;
        s = s+"#";
        int len = 1;
        int ans = 1;
        char ls = ' ';
        for(int i = 0; i<s.length(); i++){
            if(s[i]=='m' || s[i]=='w'){
                cout << 0;
                return 0;
            }
            if(ls==s[i] && (s[i]=='n' || s[i]=='u'))
                len++;
            else {
                if(len==1){

                } else {
                    int dp1 = 1, dp2 = 1;
                    for(int j = 0; j<len-1; j++){
                        dp2 = dp1+dp2;
                        dp1 = dp2-dp1;
                        dp2%=mod;
                    }
                    ans*=dp2;
                    ans%=mod;
                }
                len = 1;
            }
            ls = s[i];
        }
        cout << ans;
    }
    return 0;
}
