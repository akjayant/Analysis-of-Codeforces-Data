#include<iostream>
#include<queue>
#include <cstring>
using namespace std;

string s;

int dp[100010][2];

const int MOD=1e9+7;

int main(){
    cin>>s;
    int ok=1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='w'||s[i]=='m'){
            ok=0;
        }
    }
    if(ok==0){
        cout<<0<<endl;
        return 0;
    }
    else {
        dp[1][0]=1;
        dp[0][0]=1;
        for(int i=2;i<=s.size();i++){
            if(s[i-1]=='u'){
                dp[i][0]=dp[i-1][1]+dp[i-1][0];
                dp[i][0]%=MOD;
                if(s[i-2]=='u'){
                    dp[i][1]=dp[i-2][0]+dp[i-2][1];
                    dp[i][1]%=MOD;
                }
            }
            else if(s[i-1]=='n'){
                dp[i][0]=dp[i-1][1]+dp[i-1][0];
                dp[i][0]%=MOD;
                if(s[i-2]=='n'){
                    dp[i][1]=dp[i-2][0]+dp[i-2][1];
                    dp[i][1]%=MOD;
                }
            }
            else {
                dp[i][0]=dp[i-1][1]+dp[i-1][0];
                dp[i][0]%=MOD;
            }
        }
//        cout<<dp[s.size()][0]<<" "<<dp[s.size()][1]<<endl;
        cout<<(dp[s.size()][0]+dp[s.size()][1])%MOD<<endl;
    }
    return 0;
}