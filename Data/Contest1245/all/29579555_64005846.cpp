#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(false)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
const int mod=1e9+7;
bool isok(char a,char b){
    if(a=='u'&&b=='u')return 1;
    if(a=='n'&&b=='n')return 1;
    return 0;
}
int main()
{
    string s;
    while(cin>>s){
        bool ok=1;
        for(auto x:s){
            if(x=='w'||x=='m'){
                ok=0;
                break;
            }
        }
        if(!ok)cout<<0<<endl;
        else {
                            int n=s.length();
            vector<int> dp(n+1,0);
            dp[0]=1;
            for(int i=1;i<=n;i++){
                dp[i]=(dp[i]+dp[i-1])%mod;
                if(i>=2&&isok(s[i-1],s[i-2])){
                    dp[i]=(dp[i]+dp[i-2])%mod;
                }
            }
        cout<<dp[n]<<endl;
        }
    }
    return 0;
}
